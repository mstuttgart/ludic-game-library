#include "tile.h"

using namespace sgl::image;

//-----------------------------------------------------------

Tile::Tile(int _x, int _y, ALLEGRO_BITMAP* _bitmap, int _index ) :
	bitmap(_bitmap), x(_x), y(_y), index(_index) {}

//-----------------------------------------------------------

void Tile::parse( TiXmlNode* node ) {

	/*if( !node ) return;

	// Convertemos o node para element
	TiXmlElement* elem = node->ToElement();

	// Inicializamos o id
	elem->Attribute( "id", &id );

	// Inicializamos o propertySet
	properties.parse( node->FirstChild( "properties" ) );*/

}// parser

//-----------------------------------------------------------

void Tile::draw() {
	al_draw_bitmap( bitmap, x, y, 0 );
}
