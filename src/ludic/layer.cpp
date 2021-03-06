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

Vector2D Layer::getPosition() const {
	return position;
}

//////////////////////////////////////////////////////////////

float Layer::getX() const {
	return position.getX();
}

//////////////////////////////////////////////////////////////

float Layer::getY() const {
	return position.getY();
}

//////////////////////////////////////////////////////////////

bool Layer::isVisible() const {
	return visible;
}

//////////////////////////////////////////////////////////////