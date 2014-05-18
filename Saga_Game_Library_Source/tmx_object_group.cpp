#include "tmx_object_group.hpp"

using namespace sgl::image;
using namespace std;

//--------------------------------------------------------

TMXObjectGroup::TMXObjectGroup() : width( 0 ), height( 0 ) {
}

//--------------------------------------------------------

TMXObjectGroup::~TMXObjectGroup() {
	
	for( unsigned int i = 0; i < objects.size(); i++ )
		delete objects[i];
		
	objects.clear();
	name.clear();
}

//--------------------------------------------------------

void TMXObjectGroup::parse( TiXmlNode* node ) {
	
	// Transformamos o no em elemento
	TiXmlElement* elem = node->ToElement();

	// Recebemos o name
	const char* aux = elem->Attribute( "name" );

	// Se houver name, guardamos seu valor
	if( aux )
		name = aux;

	// Recebemos as dimensoes do object group
	elem->Attribute( "width", &width   );
	elem->Attribute( "height", &height );

	// Passamos para o primeiro no com object
	node = node->FirstChild( "object" );

	// Variavel auxiliar
	TMXObject* obj;

	while( node ) {
		
		// Criamos um novo objeto
		obj = new TMXObject();

		// Realizamos o parser
		obj->parse( node );

		// Inserimo no vetor
		objects.push_back( obj );

		// passamos para o proximo object
		node = node->NextSibling( "object" );

	}//while

}

//--------------------------------------------------------
