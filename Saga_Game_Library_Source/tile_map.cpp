#include "tile_map.h"

using namespace sgl::image;

//---------------------------------------------

TileMap::TileMap() :
	rows(0), colums(0), width(0), height(0), tileWidth(0), tileHeight(0) {};

//---------------------------------------------

TileMap::TileMap( const char* tmxFileName ) :
	width(0), height(0), tileWidth(0), tileHeight(0) {
	loadMap( tmxFileName );
}

//---------------------------------------------

TileMap::~TileMap() {

	for( unsigned int i=0; i<tilesets.size(); i++ ) {
		delete tilesets[i];
	}

	for( unsigned int i=0; i<layers.size(); i++ ) {
		delete layers[i];
	}

	for( unsigned int i=0; i<images.size(); i++ ) {
		delete images[i];
	}

	for( unsigned int i=0; i<cRects.size(); i++ ) {
		delete cRects[i];
	}

	tilesets.clear();
	layers.clear();
	images.clear();
	cRects.clear();

}

//---------------------------------------------

void TileMap::loadMap( const char* tmxFileName ) {

	//Carregamos o mapa
	TiXmlDocument doc;
	
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "Initializing tmx file load..."               << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

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

	// Realizamos o parse do mapa
	parse( root, tmxFileName );

	// Fechamos o doc
	doc.Clear();

	std::cout << "\nThe tmx file " << tmxFileName << " was loaded successfully!"
	          << std::endl << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

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

	while( nodeAux ) {

		// Criamos o tileset
		TileSet* t = new TileSet( source );

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

	while( nodeAux ) {

		// Criamos o layer
		TiledLayer* l = new TiledLayer( width, height );

		// Realizamos o parser
		l->parse( nodeAux, tilesets, colums, tileWidth, tileHeight );

		// Armazenamos o tileset
		layers.push_back( l );

		// Proximo no com tileset
		nodeAux = nodeAux->NextSibling( "layer" );

	}//while*/

	//-------------------------------------------

	// Carregamos os objects
	nodeAux = root->FirstChild( "objectgroup" );

	// Variaveis auxiliares
	int x , y, w, h;
	int gid;

	while( nodeAux ) {

		// Salvamos os objetos
		elem = nodeAux->FirstChildElement( "object" );

		while( elem ) {

			gid = -1;

			// Pegamos o id to tile
			elem->Attribute( "gid", &gid );

			if( gid == -1 ) {
				elem->Attribute( "x", &x );
				elem->Attribute( "y", &y );
				elem->Attribute( "width", &w  );
				elem->Attribute( "height", &h );
				cRects.push_back( new CollisionRect( x, y, w, h ) );
			}//if
			else {
				parseImages( gid, elem );
			}//else

			// Passamos para o proximo indice
			elem = elem->NextSiblingElement( "object" );

		}//while

		// Proximo no com tileset
		nodeAux = nodeAux->NextSibling( "objectgroup" );

	}//while

}

//---------------------------------------------

void TileMap::parseImages( int gid, TiXmlElement* elem ) {

	// Variaveis auxiliares
	int x, y;
	int w, h;
	int firstGid;

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
			StaticSprite* img = new StaticSprite( ImageResource::getSubImageResource(
			        tilesets[i]->getImage(), x, y, w, h  ) ) ;

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
			images.push_back( img );

		}//if

	}//for

}

//---------------------------------------------

TiledLayer* TileMap::getLayer( unsigned int idx ) {

	try {
		return layers.at(idx);
	}
	catch( std::exception ex ) {
		std::cout << ex.what() << std::endl;
	}

	return nullptr;

}

//---------------------------------------------

StaticSprite* TileMap::getImageObject( unsigned int idx ) {

	try {
		return images.at( idx );
	}
	catch( std::exception ex ) {
		std::cout << ex.what() << std::endl;
	}

	return NULL;
}

//---------------------------------------------

const char* TileMap::getProperty(const char* name) {

	// Iterator para properties
	std::map<std::string, std::string>::iterator it;

	// Criamos um iterator para o mapa
	it = properties.find( name );

	// Verificamos se o resource esta presente no mapa
	return it != properties.end() ? it->second.c_str() : NULL;

}

//---------------------------------------------

void TileMap::drawLayer( unsigned int layerIndex) {

	try {
		layers.at( layerIndex )->draw();
	}
	catch( std::exception& ex ) {
		std::cout << ex.what() << std::endl;
	}

}

//---------------------------------------------

bool TileMap::collisionVerify(CollisionRect& rect) {

	int size = cRects.size();

	for( int i=0; i < size; i++ ) {
		// Verificamos a colisao individualmente de cada retangulo
		if( cRects[i]->checkCollision( rect ) )
			return true;
	}//for

	return false;

}

//---------------------------------------------

bool TileMap::collisionVerify(CollisionRect& rect, unsigned int idx ) {

	if( idx>= cRects.size() ) return false;

	// Retorna o resultado da colisao
	return cRects[idx]->checkCollision( rect );

}

//---------------------------------------------

int TileMap::sizeLayers() {
	return layers.size();
}

//---------------------------------------------

int TileMap::sizeImageObjects() {
	return images.size();
}

//---------------------------------------------

int TileMap::getRows() const {
	return rows;
}

//---------------------------------------------

int TileMap::getColums() const {
	return colums;
}

//---------------------------------------------

int TileMap::getWidth() const {
	return width;
}

//---------------------------------------------

int TileMap::getHeight() const {
	return height;
}

//---------------------------------------------

int TileMap::getTileWidth() const {
	return tileWidth;
}

//---------------------------------------------

int TileMap::getTileHeight() const {
	return tileHeight;
}

//---------------------------------------------

int TileMap::sizeRects() {
	return cRects.size();
}
