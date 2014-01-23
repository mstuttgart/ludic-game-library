#include "animation.h"

namespace sgl {

namespace image {

//-----------------------------------------------

Animation::Animation( ALLEGRO_BITMAP* bitmap, int* v_index,	
								unsigned int& rows, unsigned int& columns ) :
							currentFrame( 0 ), repeat( false ), ended( false ) {

	// Calculamos a largura e altura dos frames da animacao
	frameW = al_get_bitmap_width ( bitmap ) / columns;
	frameH = al_get_bitmap_height( bitmap ) / rows;

	// Variavel auxiliar para receber a posicao
	// de cada frame dentro do sprite sheet
	int x, y;

	// Pegamos o tamanho de vetor
	const int s = sizeof( v_index ) / sizeof( int );

	// Inicializamos o vetor com os sub bitmaps
	for( int i = 0; i < s; i++ ) {

		x =         ( v_index[i] % columns ) * frameW;
		y = ( int ) ( v_index[i] / columns ) * frameH;

		v_bitmap.push_back( al_create_sub_bitmap( bitmap, x, y, frameW, frameH ) );

	}//for

}//CONTRUTOR

//-----------------------------------------------

Animation* Animation::createAnimation( ImageResource* imgRsc, int* v_index,
								   unsigned int rows, unsigned int columns ) {

	// Verificamos se os ponteiro sao validos
	if( !imgRsc || !v_index ) return NULL;

	Animation* am = new Animation( imgRsc->getBitmap(), v_index, rows, columns );

	return am;

}

//-----------------------------------------------

void Animation::nextFrame() {

	currentFrame++;

	if( repeat && currentFrame == 0 ) {
		currentFrame = 0;
	}//if

}

//-----------------------------------------------

int Animation::getCurrentFrame() const {
	return currentFrame;
}

//-----------------------------------------------

int Animation::getFrameAmount() const {
	return v_bitmap.size();
}

//-----------------------------------------------

int Animation::getFrameWidth() const {
	return frameW;
}

//-----------------------------------------------

int Animation::getFrameHeight() const {
	return frameH;
}

//-----------------------------------------------

void Animation::resetAnimation() {
	currentFrame = 0;
}

//-----------------------------------------------

void Animation::setRepeat( bool repeat ) {
	this->repeat = repeat;
}

//-----------------------------------------------

bool Animation::isRepeat() {
	return repeat;
}

//-----------------------------------------------

bool Animation::isEnded() {
	return ended;
}

//-----------------------------------------------

void Animation::draw( int& x, int& y, int& mirror ) {

	// Desenhamos o conteudo do buffers
	al_draw_bitmap( v_bitmap[currentFrame], x, y, mirror );

}

//-----------------------------------------------

}
} /* namespace */
