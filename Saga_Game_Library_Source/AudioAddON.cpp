#include "AudioAddON.h"

namespace sgl {

// Aqui a instance e executada
bool AudioAddON::addOnState = false;

// Aqui iniciamos a Allegro AUDIO
AudioAddON::AudioAddON() {

	if ( !addOnState ) {
		// Iniciamos a allegro
		try	{

			if ( !al_init_acodec_addon() ) {

				// Se a inicilizacao falhou
				AddOnException ex;
				throw ex;

			}//if

			addOnState = true;

		}//try
		catch ( sgl::AddOnException& ex ) {
			std::cout << ex.what() << "\nError in AudioAddON." << std::endl;
		}
		catch ( std::exception& ex ) {
			std::cout << ex.what() << std::endl;
		}

	}//if

}//construtor

bool AudioAddON::isInit() {
	return addOnState;
}

} /* namespace sgl */
