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
	elem->Attribute( "width", &width   );
	elem->Attribute( "height", &height );
	elem->Attribute( "rotation", &rotation );
	elem->Attribute( "gid", &gid );

	if( elem->Attribute( "visible" ) ) visible = false;

	// Inicializamos o propertySet
	properties.parse( node->FirstChild( "properties" ) );


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
