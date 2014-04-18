#include "audio_stream.h"
#include <iostream>

using namespace sgl::audio;
using namespace sgl;

AudioStream::AudioStream() :
	Audio(), streamRsc( nullptr ), stopped( false ), paused( false ) {}

//-----------------------------------------------------

AudioStream::AudioStream
(
    const String& fileName,
    unsigned int buff,
    unsigned int samples
) :
	Audio(), streamRsc( nullptr ), stopped( false ), paused( false ) {

	// Verificamos se o carregamento deu errado
	if( !load( fileName, buff, samples ) )
		throw sgl::Exception( "Error in load AudioStream " + fileName );

}

//-----------------------------------------------------

AudioStream::~AudioStream() {}

//-----------------------------------------------------

bool AudioStream::load(
    const String& fileName, unsigned int buff, unsigned int samples ) {

	try {
		// Carregamos o resource
		streamRsc = AudioStreamResource::createAudioStreamResource( fileName,
																buff, samples );
	}
	catch( sgl::Exception& ex ) {
		std::cout << ex.what() << std::endl;
		return false;
	}

	return true;
}

//-----------------------------------------------------

void AudioStream::play() {

	stopped = false;
	paused  = false;

	// Definimos um mixer padrao para o stream
	al_attach_audio_stream_to_mixer( *streamRsc, al_get_default_mixer() );
	al_set_audio_stream_playing( *streamRsc, true );
}

//-----------------------------------------------------

void AudioStream::pause() {

	stopped = false;
	paused  = true;

	// Pausamos o audio
	al_set_audio_stream_playing( *streamRsc, false );
}

//-----------------------------------------------------

void AudioStream::stop() {

	stopped = true;
	paused  = false;

	// Primeiro pausamos o audio
	al_set_audio_stream_playing( *streamRsc, false );

	// depois o reiniciamos
	al_rewind_audio_stream( *streamRsc );
}

//-----------------------------------------------------

void AudioStream::setSpeed( float speed ) {
	this->speed = speed;
	al_set_audio_stream_speed( *streamRsc, speed );
}

//-----------------------------------------------------

void AudioStream::setGain( float gain ) {
	this->gain = gain;
	al_set_audio_stream_gain( *streamRsc, gain );
}

//-----------------------------------------------------

void AudioStream::setPan( float pan ) {
	this->pan = pan;
	al_set_audio_stream_pan( *streamRsc, pan );
}

//-----------------------------------------------------

void AudioStream::setLoopingMode( AudioPlayMode l ) {
	al_set_audio_stream_playmode( *streamRsc, ( ALLEGRO_PLAYMODE ) l );
}

//-----------------------------------------------------

void AudioStream::setLooping( double ini, double fin ) {
	al_set_audio_stream_loop_secs( *streamRsc, ini, fin );
}

//-----------------------------------------------------

void AudioStream::setBegin( double pos ) {
	al_seek_audio_stream_secs( *streamRsc, pos );
}

//------------------------------------------------------

bool AudioStream::isPlaying() const {
	return al_get_audio_stream_playing( *streamRsc );
}

//------------------------------------------------------

bool AudioStream::isPaused() const {
	return paused;
}

//------------------------------------------------------

bool AudioStream::isStopped() const {
	return stopped;
}

//------------------------------------------------------
