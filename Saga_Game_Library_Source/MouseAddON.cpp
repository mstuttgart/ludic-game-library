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
			
			LogOutput::printInLogout( "MouseAddOn initialized successfully." );

		}//try
		catch ( sgl::HardwareException& ex ) {
			
			std::string str( ex.what() );
			str += " Error in MouseAddON.";	
		
			std::cout << str << std::endl;			
			LogOutput::printInLogout( str.c_str() );
			exit ( -1 );
			
		}
		catch ( std::exception& ex ) {
			
			std::cout << ex.what() << std::endl;
			LogOutput::printInLogout( ex.what() );
			exit ( -1 );
			
		}//catch

	}//if

}//contrutor

bool MouseAddON::isInit()
{
	return al_is_mouse_installed();
}
	
} /* namespace sgl */
