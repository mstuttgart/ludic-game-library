#include "AllegroStarter.h"

namespace sgl {

/* Instancia da classe. Atraves dela, o constructor sera chamado dando
   inicio a incilizacao da Allegro5 */
AllegroStarter AllegroStarter::instance;

// Inciamos toda a biblioteca dentro do constructor
AllegroStarter::AllegroStarter() {

	// Iniciamos a allegro e seus componentes
	try	{

		// Iniciando a Allegro
		if( !al_init() ) throw Exception::INIT_ALLEGRO;

		LogOutput::printInLogout( "Allegro initialized successfully." );

		// Iniciando o suporte a arquivos de imagem
		if( !al_init_image_addon() ) 
			throw Exception::INIT_IMAGE;

		LogOutput::printInLogout( "AllegroImage initialized successfully." );
		
		// Iniciando o suporte a arquivos de font e font TTF
		al_init_font_addon();

		if( !al_init_ttf_addon() ) 
			throw Exception::INIT_TTF;
			
		LogOutput::printInLogout( "AllegroFont initialized successfully." );

		// Iniciando suporte ao audio
		if( !al_install_audio() || !al_init_acodec_addon() ) 
			throw Exception::INIT_AUDIO;
			
		LogOutput::printInLogout( "AllegroAudio initialized successfully." );
			
		// Inciando o suporte ao teclado
		if ( !al_install_keyboard() )
			throw Exception::INSTALL_KEYBOARD;
			
		LogOutput::printInLogout( "Allegro Keyboard initialized successfully." );
			
		// Inciando suporte ao mouse
		if ( !al_install_mouse() )
			throw Exception::INSTALL_MOUSE;
			
		LogOutput::printInLogout( "Allegro Mouse initialized successfully." );
	
	}//try
	catch ( Exception::EXCEPTION& ex ) {

		std::cout << Exception::getError( ex ) << std::endl;
		LogOutput::printInLogout( Exception::getError( ex ) ); // Saida para log
		exit ( -1 );

	}//catch

}//contructor


}/* namespace */
