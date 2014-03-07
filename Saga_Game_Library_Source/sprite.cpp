#include "sprite.h"

using namespace sgl::image;
using namespace sgl;

//---------------------------------------------------

Sprite::Sprite() : Layer(), flip(0){}

//---------------------------------------------------

void Sprite::setPosition( int x, int y ) {
	Layer::setPosition( x, y );
	rect.setXi( x );
	rect.setYi( y );
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
	return rect.checkCollision( s->getCollisionRect() );
}

//-----------------------------------------------------------

int Sprite::getFlip() const {
	return flip;
}

//-----------------------------------------------------------

CollisionRect& Sprite::getCollisionRect() {
	return rect;
}
//-----------------------------------------------------------
