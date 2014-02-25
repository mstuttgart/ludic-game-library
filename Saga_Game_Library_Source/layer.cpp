#include "layer.h"

using namespace sgl::image;

//-----------------------------------------------------------

Layer::Layer() : x( 0 ), y( 0 ), flip(0), visible( false ) {}

//-----------------------------------------------------------

void Layer::setPosition( int x, int y ) {
	this->x = x;
	this->y = y;
}

//-----------------------------------------------------------

int Layer::getX() const {
	return x;
}

//-----------------------------------------------------------

int Layer::getY() const {
	return y;
}

//-----------------------------------------------------------

void Layer::move( int dx, int dy ) {
	this->x += dx;
	this->y += dy;
}

//-----------------------------------------------------------

void Layer::setVisible( bool visible ) {
	this->visible = visible;
}

//-----------------------------------------------------------

bool Layer::isVisible() const {
	return visible;
}

//-----------------------------------------------------------

void Layer::setFlip( FLIP flag ) {
	flip = (int) flag;
}

//-----------------------------------------------------------

int Layer::getFlip() const{
	return flip;
}

//-----------------------------------------------------------
