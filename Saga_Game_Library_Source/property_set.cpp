#include "property_set.h"

namespace sgl {
namespace image {

//-----------------------------------------------------------

void PropertySet::parse(TiXmlNode* node) {

	// Pegamos um node que tem a tag properties
	TiXmlElement* elem = node->FirstChildElement( "properties" );

	// Percorremos a tag Properties salvando cada um das proriedades
	while( elem ) {

		// Capturamos os atributos da property
		property[ elem->Attribute( "name" ) ] = elem->Attribute( "value" );

		// Passamos para a proxima property
		elem = elem->NextSiblingElement( "property" );

	}//while

}// parser

//-----------------------------------------------------------

const char* PropertySet::getPropertyValue(const char* name) {
	
	// Criamos um iterator para o mapa
	std::map<const char*, const char*>::iterator it;
	
	// Inicializamos o iterator
	it = property.find( name );

	// Verificamos se o resource esta presente no mapa
	return it != property.end() ? it->second : NULL;
	
}

//-----------------------------------------------------------

bool PropertySet::hasProperty(const char* name) {
	
	// Criamos um iterator para o mapa
	std::map<const char*, const char*>::iterator it;
	
	// Inicializamos o iterator
	it = property.find( name );

	// Verificamos se o resource esta presente no mapa
	return it != property.end() ? true : false;

}

}
} /* namespace */
