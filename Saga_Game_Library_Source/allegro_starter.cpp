#include "allegro_starter.hpp"
#include "video.hpp"
#include "resource_manager.hpp"
#include "keyboard_manager.hpp"
#include "mouse_manager.hpp"

using namespace sgl;
using namespace std;

/** Instancia da classe. Atraves dela, o constructor sera chamado dando
   inicio a incilizacao da Allegro5 */
AllegroStarter AllegroStarter::instance;

//----------------------------------------------------

// Inciamos toda a biblioteca dentro do constructor
AllegroStarter::AllegroStarter() {

	// Iniciamos a allegro e seus componentes
	try	{

		// Pegamos os detalhes da versao instalada da Allegro
		uint32_t version = al_get_allegro_version();
		int major    = version  >> 24;
		int minor    = (version >> 16) & 255;
		int revision = (version >> 8)  & 255;
		int release  = version & 255;

		cout << "================================================" << endl;
		cout << "Allegro Version " << major << "." << minor << "."
		     << revision << " [" << release << "]" << endl;
		cout << "================================================"<<
		     endl<< endl;

		cout << "Initializing Allegro and components..." << endl << endl;

		// Iniciando a Allegro
		if( !al_init() ) {
			throw sgl::Exception( "Failed to initialize ALLEGRO_Lib." );
		}

		cout << "* Allegro initialized successfully." << endl;

		// Iniciando o suporte a arquivos de imagem
		if( !al_init_image_addon() ) {
			throw sgl::Exception( "Failed to initialize ALLEGRO_IMAGE_ADDON." );
		}

		cout << "* AllegroImage initialized successfully." << endl;

		// Iniciando o suporte a desenho de primitivas graficas
		if( !al_init_primitives_addon() ) {
			throw sgl::Exception( "Failed to initialize ALLEGRO_PRIMITIVES_ADDON." );
		}

		cout << "* AllegroPrimitives initialized successfully." << endl;


		// Iniciando o suporte a arquivos de font e font TTF
		al_init_font_addon();

		if( !al_init_ttf_addon() ) {
			throw sgl::Exception( "Failed to initialize ALLEGRO_FONT_TTF_ADDON." );
		}

		cout << "* AllegroFont initialized successfully." << endl;

		// Iniciando suporte ao audio
		if( !al_install_audio() || !al_init_acodec_addon() ) {
			throw sgl::Exception( "Failed to initialize ALLEGRO_AUDIO_ADDON." );
		}

		cout << "* AllegroAudio initialized successfully." << endl;

		// Inciando o suporte ao teclado
		if ( !al_install_keyboard() ) {
			throw sgl::Exception( "Failed to initialize ALLEGRO_KEYBOARD_SUPPORT." );
		}

		cout << "* Allegro Keyboard support initialized successfully." << endl;

		// Inciando suporte ao mouse
		if ( !al_install_mouse() ) {
			throw sgl::Exception( "Failed to initialize ALLEGRO_MOUSE_SUPPORT." );
		}

		cout << "* Allegro Mouse support initialized successfully." << endl << endl;

		cout << "Allegro and components initialized successfully!" << endl << endl;

	}//try
	catch ( sgl::Exception& exp ) {
		
		std::cout << exp.what() << std::endl;
		exit ( -1 );
	}//catch

	cout << "=================================================" << endl;
	cout << "Running Saga Game Library..."   << endl;
	cout << "=================================================" << endl;

	cout << endl;

}//contructor

//-----------------------------------------------------

AllegroStarter::~AllegroStarter() {

	cout << endl;
	cout << "================================================" << endl;
	cout << "Closing Allegro and components..." << endl;
	cout << "================================================"<< endl << endl;

	// Deletamos todos os Resources
	ResourceManager::destroy();

	// Precisamos destruir o monitor por ultimo
	//VideoManager::destroy();
	
	// Deletamos MouseManager
	//sgl::input::MouseManager::release();

	// Desligamos a Allegro
	//al_uninstall_system();

}

//------------------------------------------------------
