#include "layer.h"

using namespace sgl::image;

//-----------------------------------------------------------

Layer::Layer() : visible( false ) {}

//-----------------------------------------------------------

void Layer::setVisible( bool visible ) {
	this->visible = visible;
}

//-----------------------------------------------

bool Layer::isVisible() const {
	return visible;
}


