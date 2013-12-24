#include "KeyboardAddON.h"

namespace sgl {
	namespace core {

// Aqui a instance e executada
KeyboardAddON KeyboardAddON::instance;

// Aqui iniciamos a Allegro
KeyboardAddON::KeyboardAddON() {

	// Iniciamos a allegro
	try	{

		if ( !al_install_keyboard() ){

			// Se a inicilizacao falhou
			HardwareException ex;
			throw ex;

		}//if

	}
	catch( sgl::core::HardwareException& ex ){
		std::cout << ex.what() << "\nError in Allegro Hardware Addon."<< std::endl;
	}
	catch( std::exception& ex ){
		std::cout << ex.what() << std::endl;
	}

}//contrutor


} /* namespace core */
} /* namespace sgl */
