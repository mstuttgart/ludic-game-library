#include "audio_sample.h"
#include <iostream>

using namespace sgl::audio;
using namespace sgl;
using namespace std;

AudioSample::AudioSample() : 
Audio(), sampleRsc( nullptr ), loop( AudioPlayMode::PLAY_ONCE ) {}

//------------------------------------------

AudioSample::AudioSample( const String& fileName ) : 
Audio(), sampleRsc( nullptr ), loop( AudioPlayMode::PLAY_ONCE )  {

	// Verificamos se o carregamento deu certo
	if( !load( fileName ) )
		throw sgl::Exception( "Error in load AudioSample: " + fileName );
	
}

//------------------------------------------

AudioSample::~AudioSample() {}

//------------------------------------------

bool AudioSample::load( const String& fileName ) {

	try{
		// Realizamos o carregamento do sampleResource
		sampleRsc = AudioSampleResource::createSampleResource( fileName );
	}
	catch( sgl::Exception& ex )
	{
		cout << ex.what() << endl;
		return false;
	}
	
	return true;
}

//------------------------------------------

void AudioSample::play() {
	al_play_sample( *sampleRsc, -1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL );
}

//------------------------------------------

void AudioSample::stopAll() {
	al_stop_samples();
}

//------------------------------------------

void AudioSample::setGain( float g ) {
	this->gain = g;
}

//------------------------------------------
void AudioSample::setPan( float p ) {
	
	if( p < -1 || p > 1 )
		return;

	this->pan = p;

}

//------------------------------------------

void AudioSample::setSpeed( float s ) {
	this->speed = s;
}

//------------------------------------------

const AudioSampleResource* AudioSample::getSampleResource() const {
	return sampleRsc;
}

//------------------------------------------

void AudioSample::setLoopingMode( AudioPlayMode l ) {
	this->loop = l;
}

//-------------------------------------------
