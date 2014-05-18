#include "audio_resource.hpp"
#include "resource_manager.hpp"

using namespace sgl::audio;

int AudioResource::samplesSize = 0;

//------------------------------------------

AudioResource :: AudioResource ( const String& fileName, void* audio ) :
	Resource ( fileName, audio ) {}

//-----------------------------------------

void AudioResource::incSamplesSize() {
	//samplesSize++;
	al_reserve_samples( ++samplesSize );
}

//-----------------------------------------

void AudioResource::decSamplesSize() {
	//samplesSize--;
	al_reserve_samples( --samplesSize );
}

//-----------------------------------------

int AudioResource::getSamplesSize() {
	return samplesSize;
}

//-----------------------------------------
