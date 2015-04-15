#include "audio.hpp"

using namespace sgl::audio;

bool Audio::active = true;

//////////////////////////////////////////////////////////////////

Audio::Audio() : gain( 1.0f ), pan( 0.0f ), speed( 1.0f ) {

	/*if( active ) {
		
		
		mixer = al_create_mixer( 2000, ALLEGRO_AUDIO_DEPTH_FLOAT32,
		                         ALLEGRO_CHANNEL_CONF_1);
		
		ALLEGRO_VOICE *voice = 
		al_create_voice(2000, ALLEGRO_AUDIO_DEPTH_FLOAT32, ALLEGRO_CHANNEL_CONF_1 );
		
		al_set_default_mixer( mixer );
		
		al_attach_mixer_to_voice(mixer, voice);
	}*/

	// Se tudo deu certo, reservamos mais um canal
	AudioResource::incSamplesSize();
}

//////////////////////////////////////////////////////////////////

Audio::~Audio() {
	// Decrementamos o numero de canais
	AudioResource::decSamplesSize();
} //dtor

//////////////////////////////////////////////////////////////////

float Audio::getGain() const {
	return gain;
}

//////////////////////////////////////////////////////////////////

float Audio::getPan() const {
	return pan;
}

//////////////////////////////////////////////////////////////////

float Audio::getSpeed() const {
	return speed;
}

//////////////////////////////////////////////////////////////////
