#include "tmx_object_group.hpp"

using namespace Ludic;
using namespace std;

//////////////////////////////////////////////////////////////

TMXObjectGroup::TMXObjectGroup() : width( 0 ), height( 0 ) {
}

//////////////////////////////////////////////////////////////

TMXObjectGroup::~TMXObjectGroup() {
	
	for( unsigned int i = 0; i < objects.size(); i++ )
		delete objects[i];
		
	objects.clear();
	name.clear();
}

//////////////////////////////////////////////////////////////

void TMXObjectGroup::parse( TiXmlNode* node ) {
	
	// Transformamos o no em elemento
	TiXmlElement* elem = node->ToElement();

	// Recebemos o name
	const char* aux = elem->Attribute( "name" );

	// Se houver name, guardamos seu valor
	if( aux )
		name = aux;

	// Recebemos as dimensoes do object group
	width  = (int) atoi( elem->Attribute( "width" ) );
	height = (int) atoi( elem->Attribute( "height" ));

	// Passamos para o primeiro no com object
	node = node->FirstChild( "object" );

	while( node ) {
		
		// Criamos um novo objeto
		TMXObject* obj = new TMXObject();

		// Realizamos o parser
		obj->parse( node );

		// Inserimo no vetor
		objects.push_back( obj );

		// passamos para o proximo object
		node = node->NextSibling( "object" );

	}//while

}//parse

//////////////////////////////////////////////////////////////

int TMXObjectGroup::getHeight() const {
	return height;
}

//////////////////////////////////////////////////////////////

const String& TMXObjectGroup::getName() const {
	return name;
}

//////////////////////////////////////////////////////////////

const std::vector<TMXObject*>& TMXObjectGroup::getObjects() const {
	return objects;
}

//////////////////////////////////////////////////////////////

int TMXObjectGroup::getWidth() const {
	return width;
}

//////////////////////////////////////////////////////////////
