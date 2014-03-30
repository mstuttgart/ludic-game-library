#include "sprite.h"

using namespace sgl::image;
using namespace sgl;

//---------------------------------------------------

Sprite::Sprite() : Layer(), flip( 0 ) {}

//---------------------------------------------------

void Sprite::setPosition( const Vector2D& vec ) {
	Layer::setPosition( vec );
	rect.setPosition( vec );
}

//----------------------------------------------------

void Sprite::move( const Vector2D& vec ) {
	Layer::move( vec );
	rect.move( vec );
}


//-----------------------------------------------

void Sprite::setFlip( FLIP flag ) {
	flip = ( int ) flag;
}

//----------------------------------------------------

bool Sprite::collidesWith( Sprite* s ) {
	return rect.checkCollision( s->getBoundingBox() );
}

//-----------------------------------------------------------

int Sprite::getFlip() const {
	return flip;
}

//-----------------------------------------------------------

BoundingBox& Sprite::getBoundingBox() {
	return rect;
}
//-----------------------------------------------------------
