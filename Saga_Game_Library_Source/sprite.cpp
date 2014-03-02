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

void Sprite::setAngle(float angle) {
	this->angle = angle;
}
//----------------------------------------------------

void Sprite::setScale( float scale_x, float scale_y ) {
	this->scale_x = scale_x;
	this->scale_y = scale_y;
}

//----------------------------------------------------

bool Sprite::collidesWith( Sprite* s ) {
	return rect.checkCollision( s->getCollisionRect() );
}

//-----------------------------------------------------------
