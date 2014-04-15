#include "animation.h"

using namespace sgl::image;
using namespace sgl;
using namespace std;

//---------------------------------------------------------

Animation::Animation(
    const vector< int >& data, ImageResource* baseImages[],
    const vector< TMXTileSet* >& tmxTileset ) : currentFrame( 0 ), repeat( true ) {

	// Variaveis temporarias
	int x, y, w, h;
	int firstGid;
	ImageResource* bitmap;

	for( unsigned int i = 0; i < data.size(); i++ ) {

		// Inserimos no vetor de frames apenas os tiles com id > 0
		// pois id = 0 representa um tile vazio
		if( data[i] > 0 ) {

			for( unsigned int j = 0; j < tmxTileset.size(); j++ ) {

				// Pegamos o primeiro id do tileset
				firstGid = tmxTileset[j]->getFirstGid();

				if( data[i] >= firstGid && data[i] <= tmxTileset[j]->getLastGid() ) {

					// Recebemos as dimensoes do tile do tileset
					w = tmxTileset[j]->getTileWidth();
					h = tmxTileset[j]->getTileHeight();

					// Encontramos a posicao do frame dentro
					// do seu respectivo tileset
					x = ( ( data[i] - firstGid ) % tmxTileset[j]->getColums() ) * w;
					y = ( ( data[i] - firstGid ) / tmxTileset[j]->getColums() ) * h;

					// Criamos um subbitmap com estas coordenadas
					// Este subbitmap representa o frame em questao
					bitmap = ImageResource::getSubImageResource(
					             baseImages[j], x, y, w, h );

					// Inserimos o bitmap no vetor
					frames.push_back( new Frame( data[i], w, h, bitmap ) );

				}//if

			}//for

		}//if data

	}//for i

}

//-----------------------------------------------------------

Animation::~Animation() {

	// Percorremos o vetor com os sub bitmaps, deletando-os
	for( unsigned int i = 0; i < frames.size(); i++ ) {

		if( frames[i] )
			delete frames[i];

	}//for

	frames.clear();

}

//-----------------------------------------------

void Animation::nextFrame() {

	currentFrame++;

	if( repeat && currentFrame == frames.size() ) {
		currentFrame = 0;
	}//if

}

//-----------------------------------------------

int Animation::getCurrentFrameIndex() const {
	return currentFrame;
}

//-----------------------------------------------

Frame* Animation::getCurrentFrame() const {
	return frames.at( currentFrame );
}

//-----------------------------------------------

int Animation::getFrameAmount() const {
	return frames.size();
}

//-----------------------------------------------

int Animation::getFrameWidth() const {
	return frames.at( currentFrame )->getWidth();
}

//-----------------------------------------------

int Animation::getFrameHeight() const {
	return frames.at( currentFrame )->getHeight();
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
