#include "tile_map.h"
#include "video_manager.h"

using namespace sgl::image;

//---------------------------------------------

TileMap::TileMap() : rows(0), colums(0), width(0), height(0),
	tileWidth(0), tileHeight(0){};

//---------------------------------------------

TileMap::TileMap( const char* tmxFileName ) : rows(0), colums(0),
	width(0), height(0), tileWidth(0), tileHeight(0){
	loadMap( tmxFileName );

}

//---------------------------------------------

TileMap::~TileMap() {
	release();
}

//---------------------------------------------

void TileMap::loadMap( const char* tmxFileName ) {

	//Carregamos o mapa
	TiXmlDocument doc;

	std::cout << "\n=============================================="<< std::endl;
	std::cout << "Initializing tmx file load..."               << std::endl;
	std::cout << "==============================================\n"<< std::endl;

	// Carregamos o documento
	if( !doc.LoadFile( tmxFileName ) ) {
		std::cout << doc.ErrorDesc() << std::endl;
		return;
	}//if

	// Carregamos o elemento root
	TiXmlNode* root = doc.FirstChild( "map" );

	if( !root ) {
		std::cout << "Failed to read tmx file: No root element." << std::endl;
		doc.Clear();
		return;
	}//if

	// Se os recursos da classe foram alocados antes, nos os desalocamos
	release();

	// Realizamos o parse do mapa
	parse( root, tmxFileName );

	// Fechamos o doc
	doc.Clear();

	std::cout << "\nThe tmx file " << tmxFileName << " was loaded successfully!"
	          << std::endl << std::endl;
	std::cout << "==============================================\n" << std::endl;

}

//---------------------------------------------

void TileMap::parse( TiXmlNode* root, const char* source  ) {

	//-----------------------------------------

	// Pegamos os atributos do mapa
	root->ToElement()->Attribute( "width", &colums   );
	root->ToElement()->Attribute( "height", &rows );
	root->ToElement()->Attribute( "tilewidth", &tileWidth   );
	root->ToElement()->Attribute( "tileheight", &tileHeight );

	// Calculamos as dimensoes do mapa em pixels
	width  = colums * tileWidth;
	height = rows   * tileHeight;

	//-----------------------------------------

	// Pegamos os properties do mapa
	TiXmlNode* nodeAux = root->FirstChild( "properties" );

	// Usado para percorrer os atributos de cada element
	TiXmlElement* elem;

	if( nodeAux ) {

		// Element para percorrermos os atributos de cada property
		elem = nodeAux->FirstChildElement( "property" );

		while( elem ) {
			// Pegamos os atributos da property
			properties[ elem->Attribute("name") ] = elem->Attribute("value");

			// Proximo element
			elem = elem->NextSiblingElement( "property" );

		}//while
	}//if

	//-----------------------------------------

	// Primeiro no com tileset
	nodeAux = root->FirstChild( "tileset" );

	// Tilset auxiliar
	TileSet* t;
	std::vector<TileSet*> tilesets;

	while( nodeAux ) {

		// Criamos o tileset
		t = new TileSet( source );

		// Realizamos o parser
		t->parse( nodeAux );

		// Armazenamos o tileset
		tilesets.push_back( t );

		// Proximo no com tileset
		nodeAux = nodeAux->NextSibling( "tileset" );

	}//while

	//-------------------------------------------

	// Carregamos os layers
	nodeAux = root->FirstChild( "layer" );

	// Criamos o layer
	TiledLayer* l;
	
	VideoManager* vm = VideoManager::getVideoManager();

	unsigned int displayW = vm->getDisplayWidth();
	unsigned int displayH = vm->getDisplayHeight();

	while( nodeAux ) {

		// Criamos o layer
		l = new TiledLayer( width, height, colums, displayW, displayH );

		// Realizamos o parser
		l->parse( nodeAux, tilesets, tileWidth, tileHeight );

		// Armazenamos o tileset
		layers.push_back( l );

		// Proximo no com tileset
		nodeAux = nodeAux->NextSibling( "layer" );

	}//while

	//-------------------------------------------

	// Carregamos os objects
	nodeAux = root->FirstChild( "objectgroup" );

	int gid;

	while( nodeAux ) {

		// Salvamos os objetos
		elem = nodeAux->FirstChildElement( "object" );

		while( elem ) {

			gid = -1;

			// Pegamos o id to tile
			elem->Attribute( "gid", &gid );

			if( gid != -1 )
				// Realizamos o parse do ImageObject
				parseImages( gid, elem, tilesets );

			// Passamos para o proximo indice
			elem = elem->NextSiblingElement( "object" );

		}//while

		// Proximo no com tileset
		nodeAux = nodeAux->NextSibling( "objectgroup" );

	}//while

	// Destruimos o tilesets
	for( unsigned int i=0; i<tilesets.size(); i++ ) {
		delete tilesets.at(i);
	}

	tilesets.clear();

}

//---------------------------------------------

void TileMap::parseImages( int& gid, TiXmlElement* elem, std::vector<TileSet*>& tilesets ) {

	// Variaveis auxiliares
	int x, y;
	int w, h;
	int firstGid;
	ImageResource* imgRsc;
	StaticSprite* img;

	unsigned int size = tilesets.size();

	for( unsigned int i = 0; i < size; i++ ) {

		// Pegamos o primeiro id do tileset
		firstGid = tilesets[i]->getFirstGid();

		if( gid >= firstGid && gid <= tilesets[i]->getLastGid() ) {

			w = tilesets[i]->getTileWidth();
			h = tilesets[i]->getTileHeight();

			// Calculamos a posicao x, y do tile dentro do
			// seu respectivo tileset
			x = ( ( gid - firstGid ) % tilesets[i]->getColums() ) * w;
			y = ( ( gid - firstGid ) / tilesets[i]->getColums() ) * h;

			// Criamos um subbitmap com as dimensoes encontradas
			imgRsc = ImageResource::getSubImageResource(
			             tilesets[i]->getImage(), x, y, w, h );

			img = new StaticSprite( imgRsc );

			// Setamos a visibilidade do layer
			if( !elem->Attribute( "visible" ) ) {
				img->setVisible( true );
			}

			// Lemos as coordenadas da imagem
			elem->Attribute( "x", &x );
			elem->Attribute( "y", &y );

			// Setamos as coordenadas da imagem
			img->setPosition( x, y - h );

			// Inserimos a imagem no vetor de imagens
			imgObject.push_back( img );

		}//if

	}//for

}

//---------------------------------------------

TiledLayer* TileMap::getLayer( unsigned int idx ) {

	try {
		return layers.at(idx);
	}
	catch( const std::out_of_range& ex ) {
		std::cout << "Invalid value of idx " << idx << std::endl
		          << "* Method: " << __FUNCTION__ <<"()" << std::endl
		          << "* Class: "  << "TileMap"    << std::endl;
	}//catch

	return nullptr;

}

//---------------------------------------------

StaticSprite* TileMap::getImageObject( unsigned int idx ) {

	try {
		return imgObject.at( idx );
	}
	catch( const std::out_of_range& ex ) {
		std::cout << "Invalid value of idx " << idx << std::endl
		          << "* Method: " << __FUNCTION__ <<"()" << std::endl
		          << "* Class: "  << "TileMap"    << std::endl;
	}//catch

	return NULL;
}

//---------------------------------------------

const char* TileMap::getProperty(const char* name) {

	// Iterator para properties
	std::map<std::string, std::string>::iterator it;

	// Criamos um iterator para o mapa
	it = properties.find( name );

	// Verificamos se o resource esta presente no mapa
	return it != properties.end() ? it->second.c_str() : nullptr;

}

//-----------------------------------------------------

void TileMap::drawLayer( unsigned int idx ) {

	try {
		layers.at( idx )->draw();
	}
	catch( const std::out_of_range& ex ) {
		std::cout << "Invalid value of idx " << idx << std::endl
		          << "* Method: " << __FUNCTION__ <<"()" << std::endl
		          << "* Class: "  << "TileMap"    << std::endl;
	}//catch
}

//------------------------------------------------------

void TileMap::release() {

	// Deletamos os layer
	for( unsigned int i=0; i<layers.size(); i++ ) {
		delete layers[i];
	}

	// Deletamos imageObject
	for( unsigned int i=0; i<imgObject.size(); i++ ) {
		delete imgObject[i];
	}

	layers.clear();
	imgObject.clear();
	properties.clear();

}

//---------------------------------------------

int TileMap::getTileId(int x, int y) {

	// Encontramos a coluna e fileria referente as coordenadas
	int blocks_x = x / tileWidth;
	int blocks_y = y / tileHeight;

	return ( blocks_x + blocks_y * colums );

}

//----------------------------------------------

bool TileMap::checkCollision( Sprite& spr, int movX, int movY, int layer, int tileId ) {

	// Calculamos a nova coordenada x e y com o acrescimo do movimento
	int auxX = spr.getX() + movX;
	int auxY = spr.getY() + movY;

	// Calculamos a coluna referente a localizacao do ponto X do sprite
	int iX = ( auxX ) / tileWidth;

	// Calculamos a fileira referente a localizacao do ponto Y do Sprite
	int iY = ( auxY ) / tileHeight;

	// Calculamos a coluna referente a localizacao do ponto Xf do Sprite
	int iMaxX = ( spr.getXf() + movX ) / tileWidth;

	// Calculamos a fileira referente a localizacao do ponto Yf do Sprite
	int iMaxY = ( spr.getYf() + movY ) / tileHeight;

	// Criamos um BoundingBox na futura posicao do rpite
	BoundingBox box1( auxX, auxY, spr.getWidth(), spr.getHeight() );

	// Criamos um BoundingBox para representar o tile que estamos procurando
	BoundingBox box2( 0, 0, tileWidth, tileHeight );

	// Variavel auxiliar
	Tile* t = nullptr;

	// Percorremos do tile (X,Y) ate o tile (Xf,Yf)
	for( int j = iY; j <= iMaxY; j++ ) {

		for( int i = iX; i <= iMaxX; i++ ) {

			// Calculamos o id do tile ep egamos o tile no layer
			// e com o id calculado
			t = layers.at( layer )->getTile( i + j * colums );

			// Verificamos se o t é != NULL e se o Id do tile no layer
			// e o id que estamos procurando (tileId)
			if( t != nullptr && t->getId() == tileId ) {

				// Setamos as coordenadas do box2 de acordo com o tile
				box2.setXL( t->getX() );
				box2.setYU( t->getY() );

				// Verificamos se ocorreu uma colisao
				if( box2.checkCollision( box1 ) )
					return true;

			}//if

		}//for i

	}//for j

	return false;
}
//--------------------------------------------------------

void TileMap::scroll()
{
	for( unsigned int i=0; i<layers.size(); i++ ) {
		layers[i]->scrool();
	}
}
