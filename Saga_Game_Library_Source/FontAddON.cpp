#include "FontAddON.h"

namespace sgl {

// Aqui a instance e executada
bool FontAddON::addOnState = false;

// Aqui iniciamos a Allegro
FontAddON::FontAddON() {

	if ( !addOnState ) {
		// Iniciamos a allegro
		try	{

			al_init_font_addon();

			if ( !al_init_ttf_addon() ) {

				// Se a inicilizacao falhou
				AddOnException ex;
				throw ex;

			}//if

			addOnState = true;
			LogOutput::printInLogout( "FontAddOn initialized successfully." );

		}//try
		catch ( sgl::AddOnException& ex ) {
			
			std::string str( ex.what() );
			str += " Error in FontAddon.";
			
			std::cout << str << std::endl;
			LogOutput::printInLogout( str.c_str() ); // Saida para log 
			exit ( -1 );

		}
		catch ( std::exception& ex ) {
			
			std::cout << ex.what() << std::endl;
			LogOutput::printInLogout( ex.what() );
			exit ( -1 );
			
		}

	}//if

}//contrutor

bool FontAddON::isInit() {
	return addOnState;
}

} /* namespace sgl */
