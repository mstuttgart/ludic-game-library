#include "tile.h"

using namespace sgl::image;

//-----------------------------------------------------------

Tile::Tile(int& _x, int& _y, const int& _id, int& w, int& h, ImageResource* _bitmap ) :
	id(_id), position( _x, _y ), bitmap(_bitmap), box( position, w, h ) {}

//-----------------------------------------------------------

void Tile::move( const Vector2D& vec ) {
	position += vec;
}

//--------------------------------------------------------

Tile::~Tile() {
	delete bitmap;
}

//--------------------------------------------------------
