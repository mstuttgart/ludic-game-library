#include "allegro_starter.h"

namespace sgl {
	
using namespace std;

/** Instancia da classe. Atraves dela, o constructor sera chamado dando
   inicio a incilizacao da Allegro5 */
AllegroStarter AllegroStarter::instance;

// Inciamos toda a biblioteca dentro do constructor
AllegroStarter::AllegroStarter() {

	// Iniciamos a allegro e seus componentes
	try	{
		
		cout << "================================================" << endl;
		cout << "Initializing Allegro and components..." << endl;
		cout << "================================================" << endl << endl;

		// Iniciando a Allegro
		if( !al_init() ) throw Exception::INIT_ALLEGRO;

		cout << "* Allegro initialized successfully." << endl;

		// Iniciando o suporte a arquivos de imagem
		if( !al_init_image_addon() ) 
			throw Exception::INIT_IMAGE;

		cout << "* AllegroImage initialized successfully." << endl;
		
		// Iniciando o suporte a arquivos de font e font TTF
		al_init_font_addon();

		if( !al_init_ttf_addon() ) 
			throw Exception::INIT_TTF;
			
		cout << "* AllegroFont initialized successfully." << endl;
		
		// Iniciando suporte ao audio
		if( !al_install_audio() || !al_init_acodec_addon() ) 
			throw Exception::INIT_AUDIO;
			
		cout << "* AllegroAudio initialized successfully." << endl;
	
		// Inciando o suporte ao teclado
		if ( !al_install_keyboard() )
			throw Exception::INSTALL_KEYBOARD;
			
		cout << "* Allegro Keyboard support initialized successfully." << endl;
	
		// Inciando suporte ao mouse
		if ( !al_install_mouse() )
			throw Exception::INSTALL_MOUSE;
			
		cout << "* Allegro Mouse support initialized successfully." << endl << endl;
		
		cout << "Allegro and components initialized successfully!" << endl << endl;
		
	}//try
	catch ( Exception::EXCEPTION& ex ) {

		std::cout << Exception::getError( ex ) << std::endl;
		exit ( -1 );

	}//catch
	
	cout << "=================================================" << endl;
	cout << "Running Saga Game Library..."   << endl;
	cout << "=================================================" << endl;
	
	cout << endl;

}//contructor


}/* namespace */
