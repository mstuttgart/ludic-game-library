#include "KeyboardAddON.h"

namespace sgl {

// Aqui iniciamos a Allegro
KeyboardAddON::KeyboardAddON() {

	if ( !al_is_keyboard_installed() ) {
		
		// Iniciamos a allegro
		try	{

			if ( !al_install_keyboard() ) {
				// Se a inicilizacao falhou
				HardwareException ex;
				throw ex;
			}//if
			
			LogOutput::printInLogout( "KeyboardAddOn initialized successfully." );

		}//try
		catch ( sgl::HardwareException& ex ) {
			
			std::string str( ex.what() );
			str += " Error in KeyboardAddON.";	
		
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

}//contrutor

bool KeyboardAddON::isInit() {
	return al_is_keyboard_installed();
}


} /* namespace sgl */
