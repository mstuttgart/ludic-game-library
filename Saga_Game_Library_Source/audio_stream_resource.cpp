#include "audio_stream_resource.h"
#include "resource_manager.h"

using namespace sgl::audio;
using namespace sgl;

//----------------------------------------------------------

AudioStreamResource::AudioStreamResource(
    const String& fileName, ALLEGRO_AUDIO_STREAM* stream,
    unsigned int& _buff, unsigned int& _samples) :
	AudioResource( fileName, stream ),
	buff( _buff ),
	samples( _samples ) {}

//----------------------------------------------------------

AudioStreamResource::~AudioStreamResource() {

	if( getStream() )
		al_destroy_audio_stream( getStream() );
}

//----------------------------------------------------------

AudioStreamResource* AudioStreamResource::createAudioStreamResource(
    const String& fileName, unsigned int buff, unsigned int samples ) {

	// Criamos a mensagem de carregamento
	String str( "File " + fileName );

	// Instancia de ResourceManager
	ResourceManager* rscMap = ResourceManager::Instance();

	// Verificamos se o Resource ja foi carregado
	AudioStreamResource* rsc =
	    static_cast<AudioStreamResource*>( rscMap->getResource( fileName ) );

	if ( !rsc ) {

		// Criamos o AudioStream
		ALLEGRO_AUDIO_STREAM* stream =
		    al_load_audio_stream( fileName.c_str(), buff, samples );

		if( !stream ) {
			throw sgl::Exception(
			    "ERROR: Error to load AudioStreamResource " + fileName );
			return nullptr;
		}

		// Criamos o AudioStreamResource
		rsc = new AudioStreamResource( fileName, stream, buff, samples );

		// Adicionamos ao mapa
		rscMap->addResource( fileName, rsc );

		str += " loaded successfully!";

	} else {
		str += " already exists!";
	}

	// Imprimims a mensagem de carregamento
	std::cout << str << std::endl;

	return rsc;
}

//----------------------------------------------------------

ALLEGRO_AUDIO_STREAM* AudioStreamResource::getStream() {
	return static_cast<ALLEGRO_AUDIO_STREAM*>( getResourcePtr() );
}

//----------------------------------------------------------

AudioStreamResource::operator ALLEGRO_AUDIO_STREAM*() {
	return getStream();
}

//----------------------------------------------------------

unsigned int AudioStreamResource::getBuff() const {
	return buff;
}

//----------------------------------------------------------

unsigned int AudioStreamResource::getSamples() const {
	return samples;
}

//----------------------------------------------------------
