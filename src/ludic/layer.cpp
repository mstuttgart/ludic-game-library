#include "layer.hpp"

using namespace Ludic;

//////////////////////////////////////////////////////////////

Layer::Layer() : visible( false ) {}

//////////////////////////////////////////////////////////////

void Layer::setPosition( const Vector2D& vec ) {
	position = vec;
}

//////////////////////////////////////////////////////////////

void Layer::move( const Vector2D& vec ) {
	position += vec;
}

//////////////////////////////////////////////////////////////

void Layer::setVisible( bool visible ) {
	this->visible = visible;
}

//////////////////////////////////////////////////////////////