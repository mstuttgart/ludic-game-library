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

		}//try
		catch ( sgl::HardwareException& ex ) {
			std::cout << ex.what() << "\nError in Allegro Hardware Addon."<< std::endl;
		}
		catch ( std::exception& ex ) {
			std::cout << ex.what() << std::endl;
		}

	}//if

}//contrutor

bool KeyboardAddON::isInit() {
	return al_is_keyboard_installed();
}


} /* namespace sgl */
