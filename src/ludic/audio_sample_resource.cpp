#include "audio_sample_resource.hpp"
#include "resource_manager.hpp"

using namespace Ludic;

//////////////////////////////////////////////////////////////////

AudioSampleResource::AudioSampleResource(
    const String& fileName, ALLEGRO_SAMPLE* audio ) : AudioResource( fileName, audio ) {}

//////////////////////////////////////////////////////////////////

AudioSampleResource::~AudioSampleResource()
{
	if( getSample() != nullptr )
		al_destroy_sample( getSample() );
}

//////////////////////////////////////////////////////////////////

AudioSampleResource* AudioSampleResource::createSampleResource( const String& fileName )
{

	// String com a mensagem de carregamento
	String str( "File " + fileName );

	// Recebemos a instancia da ResourceManager
	ResourceManager* rscMap = ResourceManager::Instance();

	// Carregamos a instancia do resource
	AudioSampleResource* rsc =
	    static_cast<AudioSampleResource*>( rscMap->getResource( fileName ) );

	// Se for NULL, o resource ainda nao existe
	if ( rsc == nullptr ) {

		// Criamos o sample
		ALLEGRO_SAMPLE* sample = al_load_sample( fileName.c_str() );

		if( sample == nullptr ) {
			throw Ludic::Exception( "ERROR: Error to load sample " + fileName );
			return nullptr;
		}

		// Criamos o Resource com o sample
		rsc = new AudioSampleResource( fileName, sample );

		// Adicionamos o resource ao mapa
		rscMap->addResource( fileName, rsc );

		str += " loaded successfully!";

	} else {
		str += " already exists!";
	}

	std::cout << str << std::endl;

	return rsc;
}

//////////////////////////////////////////////////////////////////

ALLEGRO_SAMPLE* AudioSampleResource::getSample()
{
	return static_cast<ALLEGRO_SAMPLE*>( getResourcePtr() );
}

//////////////////////////////////////////////////////////////////

AudioSampleResource::operator ALLEGRO_SAMPLE*()
{
	return getSample();
}

//////////////////////////////////////////////////////////////////
