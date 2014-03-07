#include "layer.h"

using namespace sgl::image;

//-----------------------------------------------------------

Layer::Layer() : x(0), y(0), visible( false ) {}

//----------------------------------------------------------

void Layer::setPosition( int& x, int& y ) {
	this->x = x;
	this->y = y;
}

//----------------------------------------------------------

void Layer::move( int& dx, int& dy ) {
	this->x += dx;
	this->y += dy;
}

//----------------------------------------------------------

void Layer::setVisible( bool visible ) {
	this->visible = visible;
}

//----------------------------------------------------------