#include "tile.h"

using namespace sgl::image;

//-----------------------------------------------------------

Tile::Tile(int& _x, int& _y, int& _id, ImageResource* _bitmap ) :
	x(_x), y(_y), id(_id), bitmap(*_bitmap) {}

//-----------------------------------------------------------

void Tile::move( int& dx, int& dy ) {
	x += dx;
	y += dy;
}

//--------------------------------------------------------

Tile::~Tile() {
	al_destroy_bitmap( bitmap );
}

//--------------------------------------------------------
