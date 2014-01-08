#include "AllegroAddON.h"

namespace sgl {

// Aqui iniciamos a Allegro
AllegroAddON::AllegroAddON() {

	if ( !al_is_system_installed() ) {

		// Iniciamos a allegro
		try	{

			if ( !al_init() ) {
				AddOnException ex; // Se a inicilizacao falhou
				throw ex;
			}//if
			
			LogOutput::printInLogout( "AllegroAddOn initialized successfully." );

		}//try
		catch ( sgl::AddOnException& ex ) {

			std::string str( ex.what() );
			str += " Error in AllegroAddon.";
			
			std::cout << str << std::endl;
			LogOutput::printInLogout( str.c_str() ); // Saida para log 
			exit ( -1 );

		}
		catch ( std::exception& ex ) {

			std::cout << ex.what() << std::endl;
			LogOutput::printInLogout( ex.what() );
			exit ( -1 );

		}//catch

	}//if

}//construtor

//-----------------------------------------------

bool AllegroAddON::isInit() {
	return al_is_system_installed();
}

//-----------------------------------------------

} /* namespace sgl */
