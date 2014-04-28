#include "animated_sprite.h"
#include "color.h"

#include <exception>

using namespace sgl::image;
using namespace sgl;
using namespace std;

//--------------------------------------------------------

AnimatedSprite::AnimatedSprite() : currentAnimation( nullptr ) {}

//--------------------------------------------------------

AnimatedSprite::AnimatedSprite( const String& file ) : currentAnimation( nullptr ) {

	// Se o carregamento der errado, lancamos a extensao
	if( !load( file ) )
		throw sgl::Exception( "Error to load file " + file );

}

//--------------------------------------------------------

AnimatedSprite::~AnimatedSprite() {
	release();
}

//--------------------------------------------------------

bool AnimatedSprite::load( const String& file ) {

	// Criamos o loader
	TMXLoader loader;

	// Carregamos o arquivo .TMX. Se o load der errado retorna false.
	if( !loader.load( file ) )
		return false;
		
	if( !animationMap.size() )
		release();

	// Realizamos o parser dos tilesets e layers
	loader.parseTileset();
	loader.parseLayers();

	initAnimations( loader );

	return true;

}

//--------------------------------------------------------

void AnimatedSprite::initAnimations( const TMXLoader& loader ) {

	// Recebemos os vetores que foram carregados pelo loader
	const vector< TMXTileSet* >& tmx_tilesets = loader.getTmxTilesets();
	const vector< TMXLayer* >&   tmx_layers   = loader.getTmxLayers();

	// Criamos um vetor para receber as ImageResource que servirao
	// como base para os tiles
	ImageResource* baseImage[ tmx_tilesets.size() ];

	// Carregamos as imagens
	for( unsigned int i = 0; i < tmx_tilesets.size(); i++ ) {

		try {
			// Criamos a imageResource
			baseImage[i] =
			    ImageResource::loadImageResource( tmx_tilesets[i]->getSource() );
		} catch( sgl::Exception& ex ) {
			cout << ex.what() << endl;
			return;
		}

		// Setamos a colorkey da imagem, se houver
		if( !tmx_tilesets[i]->getColorkey().empty() ) {
			baseImage[i]->setColorKey( Color( tmx_tilesets[i]->getColorkey() ) );
		}

	}//for i

	// Criamos o animation
	Animation* anim = nullptr;

	for( unsigned int i = 0; i < tmx_layers.size(); i++ ) {

		// Recebemos o vetor de dados do tmx_layer
		const vector< TMXLayer::DataInfo >& data = tmx_layers[i]->getData();

		// Carregamos a animation
		anim = new Animation( tmx_tilesets, data, baseImage );

		// Armazenamos o novo animation
		animationMap[ tmx_layers[i]->getName() ] = anim;

	}//for i

	// Setamos a animation adicionada com animation atual
	currentAnimation = anim;

	// Ajustamos as dimensões do retangulo de colisão
	rect.setDimension( anim->getFrameWidth(), anim->getFrameHeight() );

}

//--------------------------------------------------------

void AnimatedSprite::setCurrentAnimation( const String& label ) {

	try {

		// Setamos a animacao
		currentAnimation = animationMap.at( label );

		// Ajustamos as dimensões do retangulo de colisão
		rect.setDimension( currentAnimation->getFrameWidth(),
		                   currentAnimation->getFrameHeight() );
	} catch( std::out_of_range& ex ) {
		cout << ex.what() << endl;
		cout << "There is no animation with this label." << endl;
	}//catch

}

//--------------------------------------------------------

bool AnimatedSprite::hasAnimation( const String& label ) {

	// Criamos um iterator para o mapa
	it = animationMap.find( label );

	// Verificamos se o resource esta presente no mapa
	return it != animationMap.end() ? true : false;
}

//--------------------------------------------------------

float AnimatedSprite::getWidth() const {
	return currentAnimation->getFrameWidth();
}

//--------------------------------------------------------

float AnimatedSprite::getHeight() const {
	return currentAnimation->getFrameHeight();
}

//--------------------------------------------------------

void AnimatedSprite::draw() {

	if( isVisible() ) {

		al_draw_bitmap( *currentAnimation->getCurrentFrame(), getX(), getY(), getFlip() );

		/*al_draw_scaled_rotated_bitmap( currentAnimation->getCurrentFrame(),
		                               0, 0, getX(), getY(), 1.0, 1.0, 0, getFlip());*/
		/*al_draw_scaled_rotated_bitmap( currentAnimation->getCurrentFrame(),
		                               getRefX(), getRefY(), getX(), getY(),
									   getScaleX(), getScaleY(),
									   getAngle(), getFlip() );*/

		al_draw_rectangle( rect.getPosition_i().getX(),
		                   rect.getPosition_i().getY(),
		                   rect.getPosition_f().getX(),
		                   rect.getPosition_f().getY(),
		                   al_map_rgb( 255, 0, 255 ), 1.0 );


	}//if

}

//--------------------------------------------------------

void AnimatedSprite::nextFrame() {
	currentAnimation->nextFrame();
}

//--------------------------------------------------------

int AnimatedSprite::size() {
	return animationMap.size();
}

//--------------------------------------------------------

void AnimatedSprite::release() {

	// Destruimos o mapa de animacao
	for( auto& x : animationMap ) {
		delete x.second;
	}

	currentAnimation = nullptr;

	// Limpamos o mapa
	animationMap.clear();
}
