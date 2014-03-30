#include "layer.h"

using namespace sgl::image;
using namespace sgl;

//-----------------------------------------------------------

Layer::Layer() : visible( false ) {}
//----------------------------------------------------------

void Layer::setPosition( const Vector2D& vec ) {
	position = vec;
}

//----------------------------------------------------------

void Layer::move( const Vector2D& vec ) {
	position += vec;
}

//----------------------------------------------------------

void Layer::setVisible( bool visible ) {
	this->visible = visible;
}

//----------------------------------------------------------