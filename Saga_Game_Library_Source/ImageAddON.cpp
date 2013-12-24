#include "ImageAddON.h"

namespace sgl {
	namespace core {

// Aqui a instance e executada
ImageAddON ImageAddON::instance;

// Aqui iniciamos a AllegroImage
ImageAddON::ImageAddON() {

	// Iniciamos a allegro
	try	{

		if ( al_init_image_addon() ){

			// Se a inicilizacao falhou
			AddOnException ex;
			throw ex;

		}//if

	}
	catch( sgl::core::AddOnException& ex ){
		std::cout << ex.what() << "\nError in ImageAddon."<< std::endl;
	}
	catch( std::exception& ex ){
		std::cout << ex.what() << std::endl;
	}

}//contrutor


} /* namespace core */
} /* namespace sgl */
