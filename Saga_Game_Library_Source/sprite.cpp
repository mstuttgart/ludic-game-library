#include "sprite.h"

using namespace sgl::image;
using namespace sgl;

//---------------------------------------------------

Sprite::Sprite() : x(0), y(0) {}

//---------------------------------------------------

void Sprite::setPosition( int x, int y ) {
	this->x = x;
	this->y = y;
	rect.setXi( x );
	rect.setYi( y );
}

//----------------------------------------------------

void Sprite::move( int dx, int dy ) {
	this->x += dx;
	this->y += dy;
	rect.moveRectangle( dx, dy );
}

//----------------------------------------------------

int Sprite::getX() const {
	return x;
}

//----------------------------------------------------

int Sprite::getY() const {
	return y;
}

//----------------------------------------------------

bool Sprite::collidesWith( Sprite* s ) {
	return rect.checkCollision( s->getCollisionRect() );
}

//-----------------------------------------------------------

CollisionRect& Sprite::getCollisionRect() {
	return rect;
}

//-----------------------------------------------------------
