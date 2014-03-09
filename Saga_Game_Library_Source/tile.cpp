#include "tile.h"

using namespace sgl::image;

//-----------------------------------------------------------

Tile::Tile(int& _x, int& _y, ALLEGRO_BITMAP* _bitmap, int& _index ) :
	bitmap(_bitmap), x(_x), y(_y), index(_index) {}

//-----------------------------------------------------------

void Tile::scroll( int& dx, int& dy ) {
	this->x += dx;
	this->y += dy;
}
