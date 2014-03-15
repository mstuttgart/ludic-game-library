#include "tiled_layer.h"
#include <stdexcept>

using namespace sgl::image;

//-----------------------------------------------------------

TiledLayer::TiledLayer( int& w, int& h, int& _colums ) : Layer(),
	name(" "), vel_x(0), vel_y(0), width( w ), height( h ), colums( _colums ) {}

//---------------------------------------------------------

TiledLayer::~TiledLayer() {

	// Variavel auxiliar
	Tile* t;

	// Percorremo o mapa deletando os tiles deletaveis
	for( it = mapTiles.begin(); it != mapTiles.end(); ++it ) {

		// Pegamos o Tile
		t = it->second;

		// Deletamos o Tile
		delete t;

	}//for

	// Limpamos o mapa de tiles
	mapTiles.clear();

};

//-----------------------------------------------------------

void TiledLayer::parse( TiXmlNode* node ) {

	// Convertemos o node para element
	TiXmlElement* elem = node->ToElement();

	// Pegamos o nome do layer
	name = elem->Attribute( "name" );

	// Verificamos se o layer e visivel
	if( !elem->Attribute( "visible" ) ) setVisible( true );

}

//----------------------------------------------------------

void TiledLayer::parse( TiXmlNode* node, std::vector<TileSet*>& tileset,
                        int& blockw, int& blockh  ) {

	// Realizamos o parse dos atributos do layer
	this->parse( node );

	// Pegamos o primeiro indice para preenchermos o vetor
	TiXmlElement* elem = node->FirstChild( "data" )->FirstChildElement( "tile" );

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
					x = ( (id - firstGid ) % tileset[i]->getColums() ) * w;
					y = ( (id - firstGid ) / tileset[i]->getColums() ) * h;

					// Criamos um subbitmap com estas coordenadas
					// Este subbitmap representa o tile em questao
					bitmap = al_create_sub_bitmap(
					             tileset[i]->getImage()->getBitmap(), x, y, w, h );

					// Calculamos as coordenadas do tile no display
					x = ( count % colums ) * blockw;
					y = ( count / colums ) * blockh - h + blockh;

					// Criamos o Tile e inserimos no mapa
					mapTiles[ count ] = new Tile( x, y, id, bitmap );

				}//if

			}//for

		}//if

		// Passamos para o proximo indice
		elem = elem->NextSiblingElement( "tile" );

		// Incrementamos o contador
		count++;

	}//while

}

//-----------------------------------------------------------

void TiledLayer::setPosition( int x, int y ) {

	// Calculamos o deslocamento necessario
	int dx = x - getX();
	int dy = y - getY();

	// Atualizamos a posicao do mapa
	Layer::setPosition( x, y );

	// Movemos os tiles que constituem este tiledlayer
	this->move( dx, dy );

}

//-----------------------------------------------------------
void TiledLayer::move( int dx, int dy ) {

	// Atualizamos a coordenada principal do mapa
	Layer::move( dx, dy );

	// Percorremo o mapa
	for( it = mapTiles.begin(); it != mapTiles.end(); ++it ) {
		// Realizamos o scrool do Tile
		it->second->scroll( dx, dy );
	}

}

//-----------------------------------------------------------

void TiledLayer::setScroolVelocity( int vx, int vy ) {
	vel_x = vx;
	vel_y = vy;
}

//-----------------------------------------------------------

const char* TiledLayer::getName() {
	return name.c_str();
}

//-----------------------------------------------------------

int TiledLayer::size() const {
	return mapTiles.size();
}

//-----------------------------------------------------------

void TiledLayer::draw() {

	// Verificamos se o layer esta visivel
	if( isVisible() ) {

		// Desenhamos cada tile do layer
		for( it = mapTiles.begin(); it != mapTiles.end(); ++it ) {
			if( it->second->getX() < 640 && it->second->getY() < 480)
				it->second->draw();
		}

	}// if

}

//------------------------------------------------------------
void TiledLayer::scrool() {

	// Percorremos cada tile do layer
	for( it = mapTiles.begin(); it != mapTiles.end(); ++it ) {
		it->second->scroll( vel_x, vel_y );
	}
}

//------------------------------------------------------------

int TiledLayer::getHeight() {
	return height;
}

//------------------------------------------------------------

int TiledLayer::getWidth() {
	return width;
}

//-----------------------------------------------------------

int TiledLayer::getTileId( int x, int y ) {

	// Encontramos a coluna e fileria referente as coordenadas
	int blocks_x = x / 32;
	int blocks_y = y / 32;

	int id = blocks_x + blocks_y * colums;

	// Criamos um iterator para o mapa
	it = mapTiles.find( id );

	// Verificamos se o resource esta presente no mapa
	return it != mapTiles.end() ? it->second->getId() : 0;

}

//----------------------------------------------------------

Tile* TiledLayer::getTile(int id ) {
	
	// Encontramos a coluna e fileria referente as coordenadas
	//int blocks_x = x / 32;
	//int blocks_y = y / 32;

	//std::cout << "block x " << blocks_x << std::endl;
	//std::cout << "block y " << blocks_y << std::endl;

	//int id = blocks_x + blocks_y * colums;
	
	// Criamos um iterator para o mapa
	it = mapTiles.find( id );

	// Verificamos se o resource esta presente no mapa
	return it != mapTiles.end() ? it->second : NULL;
}

//----------------------------------------------------------
