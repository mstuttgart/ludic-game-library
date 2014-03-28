#include "tile_map.h"
#include "video_manager.h"

#include <cmath>

using namespace sgl::image;
using namespace std;

TileMap* TileMap::instance = nullptr;

//---------------------------------------------

TileMap::TileMap() : rows ( 0 ), colums ( 0 ),
	width ( 0 ), height ( 0 ), tileWidth ( 0 ), tileHeight ( 0 ) {};

//---------------------------------------------

TileMap::~TileMap() {

	// Percorremo o mapa deletando os tiles deletaveis
	for ( itrL = layers.begin(); itrL != layers.end(); ++itrL ) {

		if ( itrL->second != nullptr )
			delete itrL->second;

	}//for

	// Percorremo o mapa deletando os tiles deletaveis
	for ( itrT = tilesets.begin(); itrT != tilesets.end(); ++itrT ) {

		if ( itrT->second != nullptr )
			delete itrT->second;

	}//for

	// Limpamos os conteirners
	layers.clear();
	tilesets.clear();
}

//--------------------------------------------------------

TileMap* TileMap::createTileMap ( String tmxFileName ) {


	if ( instance ) {

		// Verificamos se o arquivo tmx possui o mesmo nome
		// se sim, significa que el ja foi criado
		String str ( tmxFileName );

		if ( str.compare ( instance->getMapName() ) == 0 ) {

			// Mensagem de erro.
			cout << "TileMap " << tmxFileName << " already loaded!" << endl;

			// Retornamos a instancia da classe ja incializada.
			return instance;
		}//if

	}//if


	/* O TileMap nao foi inicializado ou o nome do arquivo TMX e diferente
	   ou seja, outro mapa sera carregado. */

	// Destruimos o mapa antigo, se existir
	TileMap::destroyTileMap();

	// Alocamos um novo TileMap
	instance = new TileMap();

	// Carregamos o mapa e verificamos se o mesmo foi inicializado com sucesso.
	instance = instance->load ( tmxFileName ) ? instance : nullptr;

	// Retornamos o mapa ja inicializado.
	return instance;

}

//--------------------------------------------------------

bool TileMap::load ( String& tmxFileName ) {

	// Setamos o nome do arquivo
	file = tmxFileName;

	//Carregamos o mapa
	TiXmlDocument doc;

	cout << "\n=============================================="<< endl;
	cout << "Initializing tmx file load..."               << endl;
	cout << "==============================================\n"<< endl;

	// Carregamos o documento
	if ( !doc.LoadFile ( tmxFileName.c_str() ) ) {
		cout << doc.ErrorDesc() << endl;
		return false;
	}//if

	// Carregamos o elemento root
	TiXmlNode* root = doc.FirstChild ( "map" );

	if ( !root ) {
		cout << "Failed to read tmx file: No root element." << endl;
		doc.Clear();
		return false;
	}//if

	// Realizamos o parse do mapa
	parse ( root, tmxFileName );

	// Fechamos o doc
	doc.Clear();

	cout << "\nThe tmx file " << tmxFileName
	     << " was loaded successfully!" << endl << endl;
	//cout << "==============================================\n" << endl;

	return true;

}

//---------------------------------------------

void TileMap::parse ( TiXmlNode* root, String& source ) {

	//-----------------------------------------
	TiXmlElement* elem = root->ToElement();

	// Pegamos os atributos do mapa
	elem->Attribute ( "width", &colums );
	elem->Attribute ( "height", &rows  );
	elem->Attribute ( "tilewidth", &tileWidth   );
	elem->Attribute ( "tileheight", &tileHeight );

	// Calculamos as dimensoes do mapa em pixels
	width  = colums * tileWidth;
	height = rows   * tileHeight;

	// Primeiro no com tileset
	TiXmlNode* nodeAux = root->FirstChild ( "tileset" );

	// Tilset auxiliar
	TileSet* t;

	while ( nodeAux ) {

		// Criamos o tileset
		t = new TileSet();

		// Realizamos o parser
		t->parse ( nodeAux, source );

		// Armazenamos o tileset
		tilesets[ t->getSource() ] = t;

		// Proximo no com tileset
		nodeAux = nodeAux->NextSibling ( "tileset" );

	}//while

	//-------------------------------------------

	// Carregamos os layers
	nodeAux = root->FirstChild ( "layer" );

	// Convertemos o node para element
	elem = nodeAux->ToElement();

	// Criamos o layer
	TiledLayer* l;

	// Variaveis que receberam as dimensoes do display
	int displayW = 640;
	int displayH = 480;

	VideoManager* display = VideoManager::getVideoManager();

	if( display ) {
		displayW = display->getDisplayWidth();
		displayH = display->getDisplayHeight();
	}//if

	while ( nodeAux ) {

		// Convertemos o node para element
		elem = nodeAux->ToElement();

		// Criamos o layer
		l = new TiledLayer( elem->Attribute ( "name" ), colums,
		                    tileWidth, tileHeight,
		                    displayW, displayH,
		                    parseLayers( nodeAux ) );

		// Verificamos se o layer e visivel
		if ( !elem->Attribute ( "visible" ) )
			l->setVisible ( true );

		// Armazenamos o tileset
		layers[ l->getName() ] = l;

		// Proximo no com tileset
		nodeAux = nodeAux->NextSibling ( "layer" );

	}//while

	//-------------------------------------------
}

//-------------------------------------------------------

map<int, Tile*>* TileMap::parseLayers ( TiXmlNode* node ) {

	// Pegamos o primeiro indice para preenchermos o vetor
	TiXmlElement* elem = node->FirstChild( "data" )->FirstChildElement( "tile" );

	// Criamos o mapa que recebera os tiles
	map<int, Tile*>* mapTiles = new map<int, Tile*>();

	int x, y, w, h;
	int id, firstGid, count = 0;
	ImageResource* bitmap;

	while( elem ) {

		// Pegamos o numero do tile
		elem->Attribute( "gid", &id );

		if( id > 0 ) {

			for( itrT = tilesets.begin(); itrT != tilesets.end(); ++itrT ) {

				// Pegamos o primeiro id do tileset
				firstGid = itrT->second->getFirstGid();

				if( id >= firstGid && id <= itrT->second->getLastGid() ) {

					w = itrT->second->getTileWidth();
					h = itrT->second->getTileHeight();

					// Calculamos a posicao do tile dentro do seu respectivo
					// tileset
					x = ( ( id - firstGid ) % itrT->second->getColums() ) * w;
					y = ( ( id - firstGid ) / itrT->second->getColums() ) * h;

					// Criamos um subbitmap com estas coordenadas
					// Este subbitmap representa o tile em questao
					bitmap = ImageResource::getSubImageResource( 
					             itrT->second->getImage(), x, y, w, h );

					// Calculamos as coordenadas do tile no display
					x = ( count % colums ) * tileWidth;
					y = ( count / colums ) * tileHeight - h + tileHeight;

					// Criamos o Tile e inserimos no mapa
					mapTiles->insert(
					    pair<int, Tile*>( count, new Tile( x, y, id, bitmap ) ) );

				}//if

			}//for

		}//if

		// Passamos para o proximo indice
		elem = elem->NextSiblingElement( "tile" );

		// Incrementamos o contador
		count++;

	}//while

	return mapTiles;

}

//-------------------------------------------------------

TiledLayer* TileMap::getLayer ( String layerName ) {

	if ( hasLayer ( layerName ) )
		return layers.at ( layerName );

	cout << "Layer with layerName " << layerName << " no exist!" << endl;
	return nullptr;
}

//------------------------------------------------------

int TileMap::getTileId ( int x, int y ) {

	// Encontramos a coluna e fileria referente as coordenadas
	int blocks_x = x / tileWidth;
	int blocks_y = y / tileHeight;

	return ( blocks_x + blocks_y * colums );

}

//--------------------------------------------------------

void TileMap::scroll ( unsigned int dx, unsigned int dy ) {

	// Percorremo o mapa deletando os tiles deletaveis
	for ( itrL = layers.begin(); itrL != layers.end(); ++itrL ) {
		itrL->second->scrool ( dx, dy );
	}//for

}

//--------------------------------------------------------

void TileMap::setVisible ( bool visible ) {

	// Percorremo o mapa deletando os tiles deletaveis
	for ( itrL = layers.begin(); itrL != layers.end(); ++itrL )
		itrL->second->setVisible ( visible );

}

//---------------------------------------------------------

bool TileMap::hasLayer ( String name ) {

	// Iterator do map de layers
	itrL = layers.find ( name );

	return itrL != layers.end() ? true : false;

}

//--------------------------------------------------------

void TileMap::setPosition ( int x, int y ) {

	// Percorremo o mapa deletando os tiles deletaveis
	for ( itrL = layers.begin(); itrL != layers.end(); ++itrL )
		itrL->second->setPosition ( x, y );

}

//-------------------------------------------------------

void TileMap::setLayerSpeed ( int velx, int vely ) {

	// Percorremo o mapa deletando os tiles deletaveis
	for ( itrL = layers.begin(); itrL != layers.end(); ++itrL )
		itrL->second->setScroolSpeed ( velx, vely );

}

//-------------------------------------------------------

TiledLayer* TileMap::removeLayer ( String layerName ) {

	// Iterator do map de layers
	if ( hasLayer ( layerName ) ) {

		// Pegamos o layer em especificado
		TiledLayer* l = layers.at ( layerName );

		// Retiramos o layer do mapa
		layers.erase ( layerName );

		// Retornamos o layer
		return l;
	}

	return nullptr;
}

//-------------------------------------------------------

void TileMap::destroyTileMap() {

	if ( instance )
		delete instance;

	instance = nullptr;
}

//-------------------------------------------------------

const TileSet* TileMap::getTileSet( String tilesetName ) {

	if ( hasTileSet ( tilesetName ) )
		return tilesets.at ( tilesetName );

	cout << "Tileset with tilesetName " << tilesetName << " no exist!" << endl;
	return nullptr;

}

//-------------------------------------------------------

bool TileMap::hasTileSet( String tilesetName ) {

	// Iterator do map de tileset
	itrT = tilesets.find ( tilesetName );

	return itrT != tilesets.end() ? true : false;
}

//-------------------------------------------------------
