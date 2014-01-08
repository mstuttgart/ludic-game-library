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
			LogOutput::printInLogout( "ImageAddOn initialized successfully." );

		}//try
		catch ( sgl::AddOnException& ex ) {
			
			std::string str( ex.what() );
			str += " Error in ImageAddON.";	
		
			std::cout << str << std::endl;
			LogOutput::printInLogout( str.c_str() );
			exit ( -1 );
			
		}
		catch ( std::exception& ex ) {
			
			std::cout << ex.what() << std::endl;
			LogOutput::printInLogout( ex.what() );
			exit ( -1 );
			
		}

	}//if

}//contrutor

bool ImageAddON::isInit() {
	return addOnState;
}

} /* namespace sgl */
