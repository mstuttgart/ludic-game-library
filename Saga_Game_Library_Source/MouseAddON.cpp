#include "MouseAddON.h"

namespace sgl {
	namespace core {

// Aqui a instance e executada
MouseAddON MouseAddON::instance;

// Aqui iniciamos a Allegro
MouseAddON::MouseAddON() {

	// Iniciamos a allegro
	try	{

		if ( !al_install_mouse() ){

			// Se a inicilizacao falhou
			AddOnException ex;
			throw ex;

		}//if

	}
	catch( sgl::core::HardwareException& ex ){
		std::cout << ex.what() << "\nError in Allegro Mouse Support."<< std::endl;
	}
	catch( std::exception& ex ){
		std::cout << ex.what() << std::endl;
	}

}//contrutor


} /* namespace core */
} /* namespace sgl */
