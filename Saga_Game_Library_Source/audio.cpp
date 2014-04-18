#include "audio.h"

using namespace sgl::audio;

//-----------------------------------------

Audio::Audio() : gain( 1.0f ), pan( 0.0f ), speed( 1.0f ) {
	// Se tudo deu certo, reservamos mais um canal
	AudioResource::incSamplesSize();
}

//------------------------------------------

Audio::~Audio() {
	// Decrementamos o numero de canais
	AudioResource::decSamplesSize();
} //dtor

//------------------------------------------

float Audio::getGain() const {
	return gain;
}

//------------------------------------------

float Audio::getPan() const {
	return pan;
}

//------------------------------------------

float Audio::getSpeed() const {
	return speed;
}

//------------------------------------------
