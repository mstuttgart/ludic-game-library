#include "tiled_layer.h"
#include <stdexcept>  

using namespace sgl::image;

//-----------------------------------------------------------

TiledLayer::TiledLayer( int& w, int& h ) : Layer(),
	name(" "), width( w ), height( h ) {}

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
                        int& width, int& blockw, int& blockh  ) {

	// Realizamos o parse dos atributos do layer
	this->parse( node );

	// Pegamos o primeiro indice para preenchermos o vetor
	TiXmlElement* elem = node->FirstChild( "data" )->FirstChildElement( "tile" );

	int x, y;
	int w, h;
	int id;
	int count = 0;
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

					x = ( (id - firstGid ) % tileset[i]->getColums() ) * w;
					y = ( (id - firstGid ) / tileset[i]->getColums() ) * h;

					bitmap = al_create_sub_bitmap(
					             tileset[i]->getImage()->getBitmap(), x, y, w, h );

					x = ( count % width ) * blockw;
					y = ( count / width ) * blockh - h + blockh;

					mapTiles[ count ] = new Tile( x, y, bitmap );

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

Tile* TiledLayer::getTile(int tileId) {

	// Retornamos Tile e verificamos se ocorreu alguma excecao
	try {
		return mapTiles.at( tileId );
	}
	catch( const std::out_of_range& ex ) {
		std::cout << "Invalid value of tileId " << tileId  << std::endl
		          << "* Method: " << __FUNCTION__    <<"()" << std::endl
		          << "* Class: "  << "TiledLayer"    << std::endl;
	}

	return nullptr;
}
//----------------------------------------------------------
