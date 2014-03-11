#include "tiled_layer.h"

using namespace sgl::image;

//-----------------------------------------------------------

TiledLayer::TiledLayer( int& w, int& h ) : Layer(),
	name(" "), width( w ), height( h ) {}

//---------------------------------------------------------

TiledLayer::~TiledLayer() {

	// Destruimos o tilesets
	for( unsigned int i=0; i<tiles.size(); i++ ) {
		delete tiles.at(i);
	}

	tiles.clear();

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

					tiles.push_back( new Tile( x, y, bitmap, count ) );

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

	// Pegamos o tamanho do vetor de tiles
	unsigned int size = tiles.size();

	// Movemos cada tile de acordo com os parametros dx e dy
	for( unsigned int i=0; i<size; i++ ) {
		tiles[i]->scroll( dx, dy );
	}//fo
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
	return tiles.size();
}

//-----------------------------------------------------------

void TiledLayer::draw() {

	// Verificamos se o layer esta visivel
	if( isVisible() ) {

		// Pegamos o tamanho de vetor
		unsigned int size = tiles.size();

		// Desenhamos cada tile do layer
		for( unsigned int i=0; i<size; i++ ) {

			if( tiles.at(i)->getX() < 640 && tiles.at(i)->getY() < 480)
				tiles.at(i)->draw();
		}//for

	}// if

}

//------------------------------------------------------------
void TiledLayer::scrool() {

	unsigned int size = tiles.size();

	for( unsigned int i=0; i<size; i++ ) {
		tiles[i]->scroll( vel_x, vel_y );
	}//for

}

//------------------------------------------------------------

int TiledLayer::getHeight() {
	return height;
}

//------------------------------------------------------------

int TiledLayer::getWidth() {
	return width;
}
