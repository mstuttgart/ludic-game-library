#include "audio_resource.h"
#include "resource_manager.h"

using namespace sgl::audio;

int AudioResource::sizeSamples = 0;

//------------------------------------------

AudioResource :: AudioResource ( const String& fileName, void* audio ) :
	Resource ( fileName, audio ) {}

//-----------------------------------------

void AudioResource::incSamplesSize() {
	sizeSamples++;
	al_reserve_samples( sizeSamples );
}

//-----------------------------------------

void AudioResource::decSamplesSize() {
	sizeSamples--;
	al_reserve_samples( sizeSamples );
}

//-----------------------------------------

int AudioResource::getSamplesSize() {
	return sizeSamples;
}

//-----------------------------------------
