#include "tile.h"

using namespace sgl::image;

//-----------------------------------------------------------

Tile::Tile(int& _x, int& _y, int& _id, ALLEGRO_BITMAP* _bitmap ) :
	x(_x), y(_y), id(_id), bitmap(_bitmap) {}

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
