#include "AllegroAddON.h"

namespace sgl {
	namespace core {

// Aqui a instance e executada
AllegroAddON AllegroAddON::instance;

// Aqui iniciamos a Allegro
AllegroAddON::AllegroAddON() {

	// Iniciamos a allegro
	try	{

		if ( !al_init() ){

			// Se a inicilizacao falhou
			AddOnException ex;
			throw ex;

		}//if

	}
	catch( sgl::core::AddOnException& ex ){
		std::cout << ex.what() << "\nError in AllegroAddon."<< std::endl;
		exit(-1);
	}
	catch( std::exception& ex ){
		std::cout << ex.what() << std::endl;
	}

}//contrutor


} /* namespace core */
} /* namespace sgl */
