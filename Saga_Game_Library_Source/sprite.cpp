#include "sprite.h"

using namespace sgl::image;
using namespace sgl;

//---------------------------------------------------

Sprite::Sprite() : Layer(), flip(0){}

//---------------------------------------------------

void Sprite::setPosition( int x, int y ) {
	Layer::setPosition( x, y );
	rect.setXL( x );
	rect.setYU( y );
}

//----------------------------------------------------

void Sprite::move( int dx, int dy ) {
	Layer::move( dx, dy );
	rect.moveRectangle( dx, dy );
}

//-----------------------------------------------

void Sprite::setFlip(FLIP flag) {
	flip = (int) flag;
}

//----------------------------------------------------

bool Sprite::collidesWith( Sprite* s ) {
	return rect.checkCollision( s->getBoundingBox() );
}

//-----------------------------------------------------------

int Sprite::getFlip() const {
	return flip;
}

//-----------------------------------------------------------

BoundingBox& Sprite::getBoundingBox() {
	return rect;
}
//-----------------------------------------------------------
