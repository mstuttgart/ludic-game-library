#include "tiled_layer.h"

using namespace sgl::image;

//-----------------------------------------------------------

TiledLayer::TiledLayer( int& w, int& h ) :
	name(" "), width(w), height(h), visible( true ) {}

//-----------------------------------------------------------

void TiledLayer::parse( TiXmlNode* node ) {

	// Convertemos o node para element
	TiXmlElement* elem = node->ToElement();

	// Pegamos o nome do layer
	name = elem->Attribute( "name" );

	// Verificamos se o layer e visivel
	if( elem->Attribute( "visible" ) ) visible = false;

}

//----------------------------------------------------------

void TiledLayer::parse( TiXmlNode* node, std::vector<TileSet*>& tileset, int width, int blockw, int blockh ) {

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

					bitmap = al_create_sub_bitmap( tileset[i]->getImage()->getBitmap(), x, y, w, h );

					x = ( count % width ) * blockw;
					y = ( count / width ) * blockh - h + blockh;

					tiles.push_back( new Tile( x, y, bitmap, count ) );

				}//if

			}//for

		}//if*/

		// Passamos para o proximo indice
		elem = elem->NextSiblingElement( "tile" );

		// Incrementamos o contador
		count++;

	}//while

}

//-----------------------------------------------------------

void TiledLayer::setVisible(bool visible) {
	this->visible = visible;
}

//-----------------------------------------------------------

const char* TiledLayer::getName() {
	return name.c_str();
}

//-----------------------------------------------------------

bool TiledLayer::isVisible() const {
	return visible;
}

//-----------------------------------------------------------

int TiledLayer::size() const {
	return tiles.size();
}

//-----------------------------------------------------------

void TiledLayer::draw() {

	if( visible ) {

		unsigned int size = tiles.size();

		for( unsigned int i=0; i<size; i++ ) {
			tiles[i]->draw();
		}//for

	}// if

}

//------------------------------------------------------------
