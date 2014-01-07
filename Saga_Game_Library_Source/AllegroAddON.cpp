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

		}//try
		catch ( sgl::AddOnException& ex ) {
			std::cout << ex.what() << "\nError in AllegroAddon."<< std::endl;
			exit ( -1 );
		}
		catch ( std::exception& ex ) {
			std::cout << ex.what() << std::endl;
			exit ( -1 );
		}//catch

	}//if

}//construtor

bool AllegroAddON::isInit() {
	return al_is_system_installed();
}

} /* namespace sgl */
