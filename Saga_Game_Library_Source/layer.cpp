#include "layer.h"

using namespace sgl::image;

//-----------------------------------------------------------

Layer::Layer() : flip(0), visible( false ) {}

//-----------------------------------------------------------

void Layer::setVisible( bool visible ) {
	this->visible = visible;
}

//-----------------------------------------------

bool Layer::isVisible() const {
	return visible;
}

//-----------------------------------------------

int Layer::getFlip() const {
	return flip;
}

//-----------------------------------------------

void Layer::setFlip(FLIP flag) {
	flip = (int) flag;
}

//-----------------------------------------------
