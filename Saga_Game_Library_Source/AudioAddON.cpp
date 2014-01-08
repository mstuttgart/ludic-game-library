#include "AudioAddON.h"

namespace sgl {

// Aqui a instance e executada
bool AudioAddON::addOnState = false;

// Aqui iniciamos a Allegro AUDIO
AudioAddON::AudioAddON() {

	if ( !addOnState ) {
		
		// Iniciamos a allegro audio
		try	{

			if ( !al_init_acodec_addon() ) {

				// Se a inicilizacao falhou
				AddOnException ex;
				throw ex;

			}//if
		
			addOnState = true;

		}//try
		catch ( sgl::AddOnException& ex ) {
			
			std::string str( ex.what() );
			str += " Error in AudioAddON.";	
		
			std::cout << str << std::endl;
			LogOutput::printInLogout( str.c_str() );
			exit ( -1 );
							 
		}
		catch ( std::exception& ex ) {
			
			std::cout << ex.what() << std::endl;
			LogOutput::printInLogout( ex.what() );
			exit ( -1 );
					 
		}//catch

	}//if

}//construtor

bool AudioAddON::isInit() {
	return addOnState;
}

} /* namespace sgl */
