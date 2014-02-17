#include "tile.h"

namespace sgl {
namespace image {

//-----------------------------------------------------------

Tile::Tile() : id(-1){}

//-----------------------------------------------------------

void Tile::parse( TiXmlNode* node ) {
	
	if( !node ) return;
	
	// Convertemos o node para element
	TiXmlElement* elem = node->ToElement();

	// Inicializamos o id
	elem->Attribute( "id", &id );

	// Inicializamos o propertySet
	properties.parse( node->FirstChild( "properties" ) );

}// parser

//-----------------------------------------------------------

}
} /* namespace */
