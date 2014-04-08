#include "audio_resource.h"
#include "resource_manager.h"
#include <iostream>

using namespace sgl::audio;

AudioResource :: AudioResource (String fileName, void* audio) :
    Resource (fileName,audio){}

//------------------------------------------

AudioResource :: ~AudioResource()
{
    //dtor
}

//------------------------------------------

AudioResource* AudioResource :: createAudioResource(String fileName, bool aux, size_t buff, unsigned int samples){


	std::string str( "File " );
	str += fileName;


	ResourceManager* rscMap = ResourceManager::Instance();
	AudioResource* rsc = ( AudioResource* ) rscMap->getResource( fileName );



	if (!rscMap->hasResource(fileName)) {


       try {

          if (aux==false){ //chamada da classe Sample

			 ALLEGRO_SAMPLE* sample = al_load_sample(fileName.c_str());

			if( !sample ) {
				sgl::Exception ex( "Error to load sample.");
				throw ex;
			}

			rsc = new AudioResource( fileName, sample);

			}else{ //chamada da classe Stream

			    ALLEGRO_AUDIO_STREAM* stream = al_load_audio_stream(fileName.c_str(), buff, samples);

			    if(!stream){
                    sgl::Exception ex("Error to load stream.");
                    throw ex;
			    }

			    rsc = new AudioResource( fileName, stream);

			}


			rscMap->addResource( fileName, rsc );


			str += " loaded successfully!";


		}
		catch( sgl::Exception ex ) {
			std::cout << ex.what() << std::endl;
			return NULL;
		}



	}
	else {

		str += " already exists!";

	}


	std::cout << str << std::endl;


	return rsc;



}

//------------------------------------------

ALLEGRO_SAMPLE* AudioResource :: getSamplePtr(){

return (ALLEGRO_SAMPLE*) getResorcePtr();

}

//------------------------------------------

ALLEGRO_AUDIO_STREAM* AudioResource :: getStreamPtr(){

return (ALLEGRO_AUDIO_STREAM*) getResorcePtr();

}

