#include "MouseAddON.h"

namespace sgl {

// Aqui iniciamos o suporte para Mouse da Allegro
MouseAddON::MouseAddON() {

	if ( !al_is_mouse_installed() ) {

		try	{

			if ( !al_install_mouse() ) {
				// Se a inicilizacao falhou
				AddOnException ex;
				throw ex;
			}//if

		}//try
		catch ( sgl::HardwareException& ex ) {
			std::cout << ex.what() << "\nError in Allegro Mouse Addon."<< std::endl;
		}
		catch ( std::exception& ex ) {
			std::cout << ex.what() << std::endl;
		}//catch

	}//if

}//contrutor

bool MouseAddON::isInit()
{
	return al_is_mouse_installed();
}
	
} /* namespace sgl */
