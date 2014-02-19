#include "object_group.h"

namespace sgl {
namespace image {

//--------------------------------------------------

ObjectGroup::ObjectGroup() : name(" "), opacity(1.0), visible(true) {}

//--------------------------------------------------

ObjectGroup::~ObjectGroup() {

	for( unsigned int i=0; i < vObjects.size(); i++ ) {
		delete vObjects.at( i );
	}//for

	vObjects.clear();
}

//--------------------------------------------------

void ObjectGroup::parse(TiXmlNode* node) {
	
	// Convertemos para element
	TiXmlElement* elem = node->ToElement();

	// Capturamos os atributos do object group
	name = elem->Attribute( "name" );
	
	// Capturamos a opacidade do object group
	elem->Attribute( "opacity", &opacity );

	// Verificamos se e visible
	if( elem->Attribute( "visible" ) ) visible = false;

	// Inicializamos o propertySet
	properties.parse( node->FirstChild( "properties" ) );

}

//--------------------------------------------------

void ObjectGroup::parse( TiXmlNode* node, std::vector<TileSet*>& tileset )
{
	// Realizamos o parser basico
	parse( node );
	
	// Salvamos os objetos
	node = node->FirstChild( "object" );

	while( node ) {

		// Criamos o object
		Object* obj = new Object();

		// realizamos o parser
		obj->parse( node, tileset );

		// Inserimos no vetor
		vObjects.push_back( obj );

		// Passamos para o proximo indice
		node = node->NextSibling( "object" );

	}//while

	
}

//--------------------------------------------------

Object* ObjectGroup::getObject( unsigned int index )
{
	if( index >= vObjects.size() ) return NULL;
	
	return vObjects.at( index );
	
}

//--------------------------------------------------

const char* ObjectGroup::getName() {
	return name;
}

//--------------------------------------------------

double ObjectGroup::getOpacity() const {
	return opacity;
}

//--------------------------------------------------

const std::vector<Object*>& ObjectGroup::getObjects() const {
	return vObjects;
}

//--------------------------------------------------

bool ObjectGroup::isVisible() const {
	return visible;
}

//--------------------------------------------------

int ObjectGroup::size()
{
	return vObjects.size();
}

//--------------------------------------------------

int ObjectGroup::isEmpty()
{
	return vObjects.empty();
}

//--------------------------------------------------

}
} /* namespace */
