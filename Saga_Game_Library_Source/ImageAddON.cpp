#include "ImageAddON.h"

namespace sgl {

// Inicializamos o flag
bool ImageAddON::addOnState = false;

// Aqui iniciamos a AllegroImage
ImageAddON::ImageAddON() {

	if ( !addOnState ) {

		// Iniciamos a allegro
		try	{

			if ( !al_init_image_addon() ) {

				// Se a inicilizacao falhou
				AddOnException ex;
				throw ex;

			}//if

			addOnState = true;

		}//try
		catch ( sgl::AddOnException& ex ) {
			std::cout << ex.what() << "\nError in ImageAddon."<< std::endl;
		}
		catch ( std::exception& ex ) {
			std::cout << ex.what() << std::endl;
		}

	}//if

}//contrutor

bool ImageAddON::isInit() {
	return addOnState;
}

} /* namespace sgl */
