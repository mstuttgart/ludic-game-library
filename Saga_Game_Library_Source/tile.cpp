#include "tile.h"

namespace sgl {
namespace image {

Tile::Tile() : id( -1 ) {}

//-----------------------------------------------------------

void Tile::parse( TiXmlNode* node ) {

	// Pegamos um node que tem a tag tile
	TiXmlElement* elem = node->FirstChildElement( "tile" );
	
	// Inicializamos o id
	elem->Attribute( "id", &id );
	
	// Inicializamos o propertySet
	propertySet.parse( elem );

}// parser

//-----------------------------------------------------------

}} /* namespace */
