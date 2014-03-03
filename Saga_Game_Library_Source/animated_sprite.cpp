#include "animated_sprite.h"
#include <exception>

using namespace sgl::image;
using namespace std;

//--------------------------------------------------------

AnimatedSprite::AnimatedSprite() : currentAnimation( nullptr ) {}

//--------------------------------------------------------

AnimatedSprite::~AnimatedSprite() {

	// Destruimos o mapa de animacao
	for( auto& x: animationMap ) {
		currentAnimation = x.second;
		delete currentAnimation;
	}

	// Limpamos o mapa
	animationMap.clear();

}

//--------------------------------------------------------

void AnimatedSprite::addAnimation( int animationIndex, Animation* anim ) {

	// Inserimos o resource no mapa de animãcoes
	animationMap.insert( std::pair<int, Animation*>( animationIndex, anim ) );

	// Setamos a animation adicionada com animation atual
	currentAnimation = anim;

	// Ajustamos as dimensões do retangulo de colisão
	rect.setW( anim->getFrameWidth()  );
	rect.setH( anim->getFrameHeight() );
}

//--------------------------------------------------------

bool AnimatedSprite::removeAnimation( int animationIndex ) {

	// Criamos um iterator para o mapa
	it = animationMap.find( animationIndex );

	if( it != animationMap.end() ) {
		animationMap.erase( it );
		return true;
	}//if

	return false;
}

//--------------------------------------------------------

void AnimatedSprite::setCurrentAnimation( int animationIndex ) {

	try {

		// Setamos a animacao
		currentAnimation = animationMap.at( animationIndex );

		// Ajustamos as dimensões do retangulo de colisão
		rect.setW( currentAnimation->getFrameWidth()  );
		rect.setH( currentAnimation->getFrameHeight() );
	}
	catch( std::exception& ex ) {
		cout << ex.what() << endl;
		cout << "There is no animation with this animationIndex." << endl;
	}//catch

}

//--------------------------------------------------------

bool AnimatedSprite::hasAnimation( int animationIndex ) {

	// Criamos um iterator para o mapa
	it = animationMap.find( animationIndex );

	// Verificamos se o resource esta presente no mapa
	return it != animationMap.end() ? true : false;
}

//--------------------------------------------------------

int AnimatedSprite::getWidth() {
	return currentAnimation->getFrameWidth();
}

//--------------------------------------------------------

int AnimatedSprite::getHeight() {
	return currentAnimation->getFrameHeight();
}

//--------------------------------------------------------

void AnimatedSprite::draw() {

	if( isVisible() ) {
		//al_draw_bitmap( currentAnimation->getCurrentFrame(), getX(), getY(), getFlip() );
		/*al_draw_scaled_rotated_bitmap( currentAnimation->getCurrentFrame(),
		                               0, 0, getX(), getY(), 1.0, 1.0, 0, getFlip());*/
		al_draw_scaled_rotated_bitmap( currentAnimation->getCurrentFrame(),
		                               getRefX(), getRefY(), getX(), getY(), 
									   getScaleX(), getScaleY(), 
									   getAngle(), getFlip() );
	}//if

}

//--------------------------------------------------------

void AnimatedSprite::nextFrame() {
	currentAnimation->nextFrame();
}

//--------------------------------------------------------

int AnimatedSprite::sizeAnimations() {
	return animationMap.size();
}

//--------------------------------------------------------
