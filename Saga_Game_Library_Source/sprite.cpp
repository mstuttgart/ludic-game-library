#include "sprite.h"

using namespace sgl::image;
using namespace sgl;

//---------------------------------------------------

Sprite::Sprite() : x(0), y(0), flip(0), angle(0), ref_x(0), ref_y(0),
	scale_x(1.0), scale_y(1.0) {}

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

void Sprite::setRotatePoint(int ref_x, int ref_y) {
	if( ref_x <= getWidth() )
		this->ref_x = ref_x;

	if( ref_y <= getHeight() )
		this->ref_y = ref_y;
}
//----------------------------------------------------

void Sprite::setAngle(ROTATE angle) {
	// Convertemos para radianos
	this->angle = (float) angle * 3.1415/180;
}

//-----------------------------------------------

void Sprite::setFlip(FLIP flag) {
	flip = (int) flag;
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

int Sprite::getX() const {
	return x;
}
//-----------------------------------------------------------

int Sprite::getY() const {
	return y;
}
//-----------------------------------------------------------

int Sprite::getRefX() const {
	return ref_x;
}
//-----------------------------------------------------------

int Sprite::getRefY() const {
	return ref_y;
}
//-----------------------------------------------------------

float Sprite::getAngle() const {
	return angle;
}
//-----------------------------------------------------------

int Sprite::getFlip() const {
	return flip;
}
//-----------------------------------------------------------

float Sprite::getScaleX() const {
	return scale_x;
}
//-----------------------------------------------------------

float Sprite::getScaleY() const {
	return scale_y;
}
//-----------------------------------------------------------

CollisionRect& Sprite::getCollisionRect() {
	return rect;
}
//-----------------------------------------------------------