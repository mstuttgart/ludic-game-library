#include "tile.h"

using namespace sgl::image;

//-----------------------------------------------------------

Tile::Tile(int& _x, int& _y, ALLEGRO_BITMAP* _bitmap ) :
	x(_x), y(_y), bitmap(_bitmap) {}

//-----------------------------------------------------------

void Tile::scroll( int& dx, int& dy ) {
	this->x += dx;
	this->y += dy;
}

//--------------------------------------------------------

Tile::~Tile() {
	al_destroy_bitmap( bitmap );
}

//--------------------------------------------------------
