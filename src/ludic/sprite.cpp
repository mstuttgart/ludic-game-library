#include "sprite.hpp"

using namespace Ludic;

//////////////////////////////////////////////////////////////

Sprite::Sprite() : Layer(), flip( 0 ) {}

//////////////////////////////////////////////////////////////

void Sprite::setPosition( const Vector2D& vec ) {
	Layer::setPosition( vec );
	collisionBox.setPosition( vec );
}

//////////////////////////////////////////////////////////////

void Sprite::move( const Vector2D& vec ) {
	Layer::move( vec );
	collisionBox.move( vec );
}

//////////////////////////////////////////////////////////////

void Sprite::setFlip( FLIP flag ) {
	flip = ( int ) flag;
}

//////////////////////////////////////////////////////////////

bool Sprite::collidesWithBox( Sprite* s ) {
	return collisionBox.checkCollision( s->getBoundingBox() );
}

//////////////////////////////////////////////////////////////

bool Sprite::collidesWithPixel( Sprite* s) const
{
	int xc = getX() + getWidth()  * 0.5 - ( s->getX() + s->getWidth() * 0.5  );
	int yc = getY() + getHeight() * 0.5 - ( s->getY() + s->getHeight() * 0.5 );

	return getMask().collisionVerify( s->getMask(), xc, yc );
}

//////////////////////////////////////////////////////////////

int Sprite::getFlip() const {
	return flip;
}

//////////////////////////////////////////////////////////////

CollisionBox& Sprite::getBoundingBox() {
	return collisionBox;
}
