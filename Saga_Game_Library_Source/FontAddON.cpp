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

		}//try
		catch ( sgl::AddOnException& ex ) {
			std::cout << ex.what() << "\nError in FontAddon."<< std::endl;
		}
		catch ( std::exception& ex ) {
			std::cout << ex.what() << std::endl;
		}

	}//if

}//contrutor

bool FontAddON::isInit() {
	return addOnState;
}

} /* namespace sgl */
