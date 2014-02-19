#include "object.h"

namespace sgl {
namespace image {

//-------------------------------------------

Object::Object() : name(" "), type(" "), x(0), y(0), width(0),
	height(0), rotation(0),	gid(0),	visible(true) {}

//-------------------------------------------

void Object::parse( TiXmlNode* node ) {

	// Convertemos para element
	TiXmlElement* elem = node->ToElement();

	// Inicializamos o id
	name = elem->Attribute( "name" );
	type = elem->Attribute( "type" );

	elem->Attribute( "x", &x );
	elem->Attribute( "y", &y );
	elem->Attribute( "rotation", &rotation );

	if( elem->Attribute( "visible" ) ) visible = false;

	// Inicializamos o propertySet
	properties.parse( node->FirstChild( "properties" ) );


}

//-------------------------------------------

void Object::parse( TiXmlNode* node, std::vector<TileSet*>& tileset ) {
	
	parse( node );

	// Convertemos para element
	TiXmlElement* elem = node->ToElement();

	gid = -1;

	// Pegamos o id to tile
	elem->Attribute( "gid", &gid );

	if( gid == -1 ) {
		elem->Attribute( "width", &width   );
		elem->Attribute( "height", &height );
	}//if
	else {
		
		int x_aux, y_aux;
		int w, h;
		int firstGid;
		unsigned int size;

		ALLEGRO_BITMAP* bitmap;

		// Pegamos a qualtidade de tiles do tileset
		size = tileset.size();

		for( unsigned int i=0; i < size; i++ ) {

			// Pegamos o primeiro id do tileset
			firstGid = tileset[i]->getFirstGid();

			if( gid >= firstGid && gid <= tileset[i]->getLastGid() ) {

				w = tileset[i]->getTileWidth();
				h = tileset[i]->getTileHeight();

				x_aux = ( ( gid - firstGid ) % tileset[i]->getColums() ) * w;
				y_aux = ( ( gid - firstGid ) / tileset[i]->getColums() ) * h;

				bitmap = al_create_sub_bitmap( tileset[i]->getImage()->getBitmap(), x_aux, y_aux, w, h );

			}//if

		}//for

	}//else

}

//-------------------------------------------

int Object::getGid() const {
	return gid;
}

//-------------------------------------------

int Object::getHeight() const {
	return height;
}

//-------------------------------------------

const char* Object::getName() {
	return name;
}

//-------------------------------------------

double Object::getRotation() const {
	return rotation;
}

//-------------------------------------------

const char* Object::getType() {
	return type;
}

//-------------------------------------------

bool Object::isVisible() const {
	return visible;
}

//-------------------------------------------

int Object::getWidth() const {
	return width;
}

//-------------------------------------------

int Object::getX() const {
	return x;
}

//-------------------------------------------

int Object::getY() const {
	return y;
}

//-------------------------------------------
}
} /* namespace */
