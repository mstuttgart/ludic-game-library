#include "allegro_starter.h"

using namespace sgl;
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

		// Criamos o objeto de excecao
		sgl::Exception ex;

		// Iniciando a Allegro
		if( !al_init() ) {
			ex.setMensage( "Failed to initialize ALLEGRO_Lib." );
			throw ex;
		}

		cout << "* Allegro initialized successfully." << endl;

		// Iniciando o suporte a arquivos de imagem
		if( !al_init_image_addon() ) {
			ex.setMensage( "Failed to initialize ALLEGRO_IMAGE_ADDON." );
			throw ex;
		}

		cout << "* AllegroImage initialized successfully." << endl;

		// Iniciando o suporte a arquivos de font e font TTF
		al_init_font_addon();

		if( !al_init_ttf_addon() ) {
			ex.setMensage( "Failed to initialize ALLEGRO_FONT_TTF_ADDON." );
			throw ex;
		}

		cout << "* AllegroFont initialized successfully." << endl;

		// Iniciando suporte ao audio
		if( !al_install_audio() || !al_init_acodec_addon() ) {
			ex.setMensage( "Failed to initialize ALLEGRO_AUDIO_ADDON." );
			throw ex;
		}

		cout << "* AllegroAudio initialized successfully." << endl;

		// Inciando o suporte ao teclado
		if ( !al_install_keyboard() ) {
			ex.setMensage( "Failed to initialize ALLEGRO_KEYBOARD_SUPPORT." );
			throw ex;
		}

		cout << "* Allegro Keyboard support initialized successfully." << endl;

		// Inciando suporte ao mouse
		if ( !al_install_mouse() ) {
			ex.setMensage( "Failed to initialize ALLEGRO_MOUSE_SUPPORT." );
			throw ex;
		}

		cout << "* Allegro Mouse support initialized successfully." << endl << endl;

		cout << "Allegro and components initialized successfully!" << endl << endl;

	}//try
	catch ( sgl::Exception exp ) {

		std::cout << exp.what() << std::endl;
		exit ( -1 );

	}//catch

	cout << "=================================================" << endl;
	cout << "Running Saga Game Library..."   << endl;
	cout << "=================================================" << endl;

	cout << endl;

}//contructor
