#include "layer.h"

namespace sgl {

namespace image {

//-----------------------------------------------------------

Layer::Layer() : name(" "), opacity(1.0), visible( true ) {}

//-----------------------------------------------------------

void Layer::parse( TiXmlNode* node ) {

	// Convertemos o node para element
	TiXmlElement* elem = node->ToElement();

	// Pegamos o nome do layer
	name = elem->Attribute( "name" );

	// Pegamos a opacidade
	elem->Attribute( "opacity", &opacity );

	// Verificamos se o layer e visivel
	if( elem->Attribute( "visible" ) ) visible = false;

	// Inicializamos o propertySet
	properties.parse( node->FirstChild( "properties" ) );

}

//----------------------------------------------------------

void Layer::parse( TiXmlNode* node, std::vector<TileSet*>* tileset, int width, int blockw, int blockh ) {

	// Realizamos o parse dos atributos do layer
	this->parse( node );

	// Pegamos o primeiro indice para preenchermos o vetor
	TiXmlElement* elem = node->FirstChild( "data" )->FirstChildElement( "tile" );

	int x, y;
	int w, h;
	int id;
	int count = 0;

	ALLEGRO_BITMAP* bitmap;

	while( elem ) {

		// Pegamos o numero do tile
		elem->Attribute( "gid", &id );

		if( id > 0 ) {

			for( unsigned int i=0; i < tileset->size(); i++ ) {

				if( id >= tileset->at(i)->getFirstGid() && id <= tileset->at(i)->getLastGid() ) {

					w = tileset->at(i)->getTileWidth();
					h = tileset->at(i)->getTileHeight();

					x = ( (id - tileset->at(i)->getFirstGid() ) % tileset->at(i)->getColums() ) * w;
					y = ( (id - tileset->at(i)->getFirstGid() ) / tileset->at(i)->getColums() ) * h;

					bitmap = al_create_sub_bitmap( tileset->at(i)->getImage()->getBitmap(), x, y, w, h );

					x = ( count % width ) * blockw;
					y = ( count / width ) * blockh - h + blockh;

					data.push_back( new Tile(x,y,bitmap) );

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

void Layer::setOpacity(double opacity) {
	this->opacity = opacity;
}

//-----------------------------------------------------------

void Layer::setVisible(bool visible) {
	this->visible = visible;
}

//-----------------------------------------------------------

const char* Layer::getName() {
	return name;
}

//-----------------------------------------------------------

double Layer::getOpacity() const {
	return opacity;
}

//-----------------------------------------------------------

bool Layer::isVisible() const {
	return visible;
}

//-----------------------------------------------------------

int Layer::size() const {
	return data.size();
}

//-----------------------------------------------------------

void Layer::draw() {

	if( visible ) {
		
		for( unsigned int i=0; i<data.size(); i++ ) {
			data[i]->draw();
		}//for
		
	}// if

}

}
} /* namespace */
