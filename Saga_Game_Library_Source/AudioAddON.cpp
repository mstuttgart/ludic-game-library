#include "AudioAddON.h"

namespace sgl {
	namespace core {

// Aqui a instance e executada
AudioAddON AudioAddON::instance;

// Aqui iniciamos a Allegro AUDIO
AudioAddON::AudioAddON() {

	// Iniciamos a allegro
	try	{

		if ( !al_init_acodec_addon() ){

			// Se a inicilizacao falhou
			AddOnException ex;
			throw ex;

		}//if

	}
	catch( sgl::core::AddOnException& ex ){
		std::cout << ex.what() << "\nError in AudioAddON."<< std::endl;
	}
	catch( std::exception& ex ){
		std::cout << ex.what() << std::endl;
	}

}//contrutor


} /* namespace core */
} /* namespace sgl */
