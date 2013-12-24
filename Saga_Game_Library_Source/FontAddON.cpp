#include "FontAddON.h"

namespace sgl {
	namespace core {

// Aqui a instance e executada
FontAddON FontAddON::instance;

// Aqui iniciamos a Allegro
FontAddON::FontAddON() {

	// Iniciamos a allegro
	try	{

		al_init_font_addon();

		if ( !al_init_ttf_addon() ){

			// Se a inicilizacao falhou
			AddOnException ex;
			throw ex;

		}//if

	}
	catch( sgl::core::AddOnException& ex ){
		std::cout << ex.what() << "\nError in FontAddon."<< std::endl;
	}
	catch( std::exception& ex ){
		std::cout << ex.what() << std::endl;
	}

}//contrutor


} /* namespace core */
} /* namespace sgl */
