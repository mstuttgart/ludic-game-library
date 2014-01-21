#include "Animation.h"

namespace sgl {

namespace image {

//-----------------------------------------------

Animation::Animation( Image* baseImg, int* v_index, int rows, int colums ) {

	// Pegamos o tamanho de vetor
	const int s = sizeof( v_index ) / sizeof( int );
	
	// Bitmap auxiliar
	ALLEGRO_BITMAP* bitmap = baseImg->getAllegroBitmap() ;

	int frame_w = al_get_bitmap_width ( bitmap ) / colums;
	int frame_h = al_get_bitmap_height( bitmap ) / rows;

	/* Variavel auxiliar para receber a posicao 
	 * de cada frame dentro do sprite sheet */
	int frame_x, frame_y;

	// Inicializamos o vetor com os sub bitmaps
	for( int i = 0; i < s; i++ ){
		
		frame_x =         ( v_index[i] % colums ) * frame_w;
		frame_y = ( int ) ( v_index[i] / colums ) * frame_h;

		v_bitmap.push_back( al_create_sub_bitmap( bitmap, frame_x, frame_y, frame_w, frame_h ) );
	}

}

//-----------------------------------------------

Animation::~Animation() {
	
	// Pegamos o tamanho de vetor
	const int s = v_bitmap.size();
	
	for( int i = 0; i < s; i++ ) {
		al_destroy_bitmap( v_bitmap[i] );
	}//for
	
}

//-----------------------------------------------

void Animation::nextFrame() {
	
	currentFrame++;
	
	if( repeat && currentFrame == 0)
	{
		currentFrame = 0;
	}

}

//-----------------------------------------------

int Animation::getCurrentFrameIndex() const {
	return currentFrame;
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
