#include "surface.h"

using namespace sgl::image;

//-----------------------------------------------------------

Surface::Surface() : x( 0 ), y( 0 ), flip(0), visible( false ) {}

//-----------------------------------------------------------

void Surface::setPosition( int x, int y ) {
	this->x = x;
	this->y = y;
}

//-----------------------------------------------------------

int Surface::getX() const {
	return x;
}

//-----------------------------------------------------------

int Surface::getY() const {
	return y;
}

//-----------------------------------------------------------

void Surface::move( int dx, int dy ) {
	this->x += dx;
	this->y += dy;
}

//-----------------------------------------------------------

void Surface::setVisible( bool visible ) {
	this->visible = visible;
}

//-----------------------------------------------------------

bool Surface::isVisible() const {
	return visible;
}

//-----------------------------------------------------------

void Surface::setFlip( FLIP flag ) {
	flip = (int) flag;
}

//-----------------------------------------------------------

int Surface::getFlip() const{
	return flip;
}

//-----------------------------------------------------------
