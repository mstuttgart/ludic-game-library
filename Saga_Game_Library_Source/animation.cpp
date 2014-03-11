#include "animation.h"

using namespace sgl::image;

//-----------------------------------------------

Animation::Animation( ImageResource* _imgRsc, std::vector<int> &v_index,
                      unsigned int& rows, unsigned int& columns ) :
	currentFrame( 0 ), repeat( true ), imgRsc( _imgRsc ) {

	// Pegamos o bitmap da ImageResource
	ALLEGRO_BITMAP* bitmap = imgRsc->getBitmap();

	// Calculamos a largura e altura dos frames da animacao
	frameW = al_get_bitmap_width ( bitmap ) / columns;
	frameH = al_get_bitmap_height( bitmap ) / rows;

	// Variavel auxiliar para receber a posicao
	// de cada frame dentro do sprite sheet
	int x, y;

	// Pegamos o tamanho de vetor
	const int s = v_index.size();

	// Inicializamos o vetor com os sub bitmaps
	for( int i = 0; i < s; i++ ) {

		x =         ( v_index[i] % columns ) * frameW;
		y = ( int ) ( v_index[i] / columns ) * frameH;

		v_bitmaps.push_back(
		    al_create_sub_bitmap( bitmap, x, y, frameW, frameH ) );

	}//for

}//CONTRUTOR

//-----------------------------------------------

Animation* Animation::createAnimation( ImageResource* imgRsc,
                                       std::vector<int> &v_index,
                                       unsigned int rows,
                                       unsigned int columns ) {

	// Verificamos se os ponteiro sao validos
	if( !imgRsc || !rows || !columns ) return NULL;

	// Criamos e retornamos um ponteiro para a animacao
	return ( new Animation( imgRsc, v_index, rows, columns ) );

}


//-----------------------------------------------

Animation* Animation::createAnimation( const char* fileName,
                                       std::vector<int> &v_index,
                                       unsigned int rows,
                                       unsigned int columns) {

	// Verificamos se o filename nao e NULL
	if( !fileName || !rows || !columns ) return NULL;

	// Criamos o resource
	ImageResource* imgRsc = ImageResource::createImageResource( fileName );

	// Retornamos a nova animacao
	return ( new Animation( imgRsc, v_index, rows, columns ) );

}

//-----------------------------------------------

void Animation::nextFrame() {

	currentFrame++;

	if( repeat && currentFrame == v_bitmaps.size() ) {
		currentFrame = 0;
	}//if

}

//-----------------------------------------------

int Animation::getCurrentFrameIndex() const {
	return currentFrame;
}

//-----------------------------------------------

ALLEGRO_BITMAP* Animation::getCurrentFrame() const {
	return v_bitmaps.at( currentFrame );
}

//-----------------------------------------------

int Animation::getFrameAmount() const {
	return v_bitmaps.size();
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

ImageResource* Animation::getImageResouce() {
	return imgRsc;
}

//-----------------------------------------------
