#include "tile_map.h"
#include "video_manager.h"
#include <cmath>

using namespace sgl::image;
using namespace std;

TileMap* TileMap::instance = nullptr;

//---------------------------------------------

TileMap::TileMap() : rows ( 0 ), colums ( 0 ), width ( 0 ), height ( 0 ),
	tileWidth ( 0 ), tileHeight ( 0 ) {};

//---------------------------------------------

TileMap::~TileMap() {

	// Percorremo o mapa deletando os tiles deletaveis
	for ( it = layers.begin(); it != layers.end(); ++it ) {

		// Verificamos se o objeto nao e nulo
		if ( it->second != nullptr )
			delete it->second; // Pegamos o Tile

	}//for

	// Limpamos os conteirners
	layers.clear();

}

//--------------------------------------------------------

TileMap* TileMap::createTileMap ( String tmxFileName ) {


	if ( instance ) {

		string str ( tmxFileName );

		// Verificamos se o arquivo tmx possui o mesmo nome
		// se sim, significa que el ja foi criado
		if ( str.compare ( instance->getMapName() ) == 0 ) {

			// Mensagem de erro.
			cout << "TileMap " << tmxFileName << " already loaded!" << endl;

			// Retornamos a instancia da classe ja incializada.
			return instance;
		}

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
	std::vector<TileSet*> tilesets;

	while ( nodeAux ) {

		// Criamos o tileset
		t = new TileSet ( source );

		// Realizamos o parser
		t->parse ( nodeAux );

		// Armazenamos o tileset
		tilesets.push_back ( t );

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
	}

	while ( nodeAux ) {

		// Convertemos o node para element
		elem = nodeAux->ToElement();

		// Criamos o layer
		l = new TiledLayer( elem->Attribute ( "name" ), colums,
		                    tileWidth, tileHeight, 
							displayW, displayH,
		                    parseLayers( nodeAux, tilesets ) );

		// Verificamos se o layer e visivel
		if ( !elem->Attribute ( "visible" ) )
			l->setVisible ( true );

		// Armazenamos o tileset
		layers[ l->getName() ] = l;

		// Proximo no com tileset
		nodeAux = nodeAux->NextSibling ( "layer" );

	}//while

	//-------------------------------------------

	// Destruimos o tilesets
	for ( unsigned int i=0; i<tilesets.size(); i++ ) {
		delete tilesets.at ( i );
	}

	tilesets.clear();

}

//-------------------------------------------------------

map<int, Tile*>* TileMap::parseLayers ( TiXmlNode* node, vector<TileSet*>& tileset ) {

	// Pegamos o primeiro indice para preenchermos o vetor
	TiXmlElement* elem = node->FirstChild( "data" )->FirstChildElement( "tile" );

	// Criamos o mapa que recebera os tiles
	map<int, Tile*>* mapTiles = new map<int, Tile*>();

	int x, y;
	int w, h;
	int id, count = 0;
	int firstGid;
	unsigned int size;

	ALLEGRO_BITMAP* bitmap;

	while( elem ) {

		// Pegamos o numero do tile
		elem->Attribute( "gid", &id );

		if( id > 0 ) {

			// Pegamos a qualtidade de tiles do tileset
			size = tileset.size();

			for( unsigned int i=0; i < size; i++ ) {

				// Pegamos o primeiro id do tileset
				firstGid = tileset[i]->getFirstGid();

				if( id >= firstGid && id <= tileset[i]->getLastGid() ) {

					w = tileset[i]->getTileWidth();
					h = tileset[i]->getTileHeight();

					// Calculamos a posicao do tile dentro do seu respectivo
					// tileset
					x = ( ( id - firstGid ) % tileset[i]->getColums() ) * w;
					y = ( ( id - firstGid ) / tileset[i]->getColums() ) * h;

					// Criamos um subbitmap com estas coordenadas
					// Este subbitmap representa o tile em questao
					bitmap = al_create_sub_bitmap(
					             *tileset[i]->getImage(), x, y, w, h );

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
	for ( it = layers.begin(); it != layers.end(); ++it ) {
		it->second->scrool ( dx, dy );
	}//for

}

//--------------------------------------------------------

void TileMap::setVisible ( bool visible ) {

	// Percorremo o mapa deletando os tiles deletaveis
	for ( it = layers.begin(); it != layers.end(); ++it ) {
		it->second->setVisible ( visible );
	}//for

}

//---------------------------------------------------------

bool TileMap::hasLayer ( String name ) {

	// Iterator do map de layers
	it = layers.find ( "name" );

	return it != layers.begin() ? true : false;

}

//--------------------------------------------------------

void TileMap::setPosition ( int x, int y ) {

	// Percorremo o mapa deletando os tiles deletaveis
	for ( it = layers.begin(); it != layers.end(); ++it ) {

		it->second->setPosition ( x, y );
	}//for

}

//-------------------------------------------------------

void TileMap::setLayerSpeed ( int velx, int vely ) {

	// Percorremo o mapa deletando os tiles deletaveis
	for ( it = layers.begin(); it != layers.end(); ++it ) {

		it->second->setScroolSpeed ( velx, vely );
	}//for
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
