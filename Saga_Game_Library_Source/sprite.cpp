#include "sprite.h"
#include <exception>

namespace sgl {

namespace image {

using namespace std;

//--------------------------------------------------------

Sprite::Sprite() : currentAnimation( nullptr ) {}

//--------------------------------------------------------

Sprite::~Sprite() {
	if( currentAnimation ) delete currentAnimation;
}

//--------------------------------------------------------

void Sprite::addAnimation( int animationIndex, Animation* anim ) {

	// Inserimos o resource no mapa de animãcoes
	animationMap.insert( std::pair<int, Animation*>( animationIndex, anim ) );
}

//--------------------------------------------------------

bool Sprite::removeAnimation( int animationIndex ) {

	// Criamos um iterator para o mapa
	it = animationMap.find( animationIndex );

	if( it != animationMap.end() ) {
		animationMap.erase( it );
		return true;
	}//if

	return false;
}

//--------------------------------------------------------

void Sprite::setCurrentAnimation( int animationIndex ) {

	try {
		// Setamos a animacao
		currentAnimation = animationMap.at( animationIndex );
	}
	catch( std::exception& ex ) {
		cout << ex.what() << endl;
		cout << "There is no animation with this animationIndex." << endl;
	}//catch

}

//--------------------------------------------------------

bool Sprite::isAnimationPresent( int animationIndex ) {

	// Criamos um iterator para o mapa
	it = animationMap.find( animationIndex );

	// Verificamos se o resource esta presente no mapa
	return it != animationMap.end() ? true : false;
}

//--------------------------------------------------------

int Sprite::getWidth() {
	return currentAnimation->getFrameWidth();
}

//--------------------------------------------------------

int Sprite::getHeight() {
	return currentAnimation->getFrameHeight();
}

//--------------------------------------------------------

void Sprite::draw() {
	al_draw_bitmap( currentAnimation->getCurrentFrame(), getX(), getY(), 0 );
}

//--------------------------------------------------------

}
} /* namespace */
