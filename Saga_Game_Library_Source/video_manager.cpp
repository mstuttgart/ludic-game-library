#include "video_manager.h"
#include "image_resource.h"

#include <allegro5/allegro_opengl.h>

using namespace sgl;

// Declarando as variaveis static
VideoManager* VideoManager::instance = nullptr;

//---------------------------------------

VideoManager::VideoManager( ALLEGRO_DISPLAY* _display, ALLEGRO_COLOR backg ) :
display(_display), backGroundColor(backg){}

//---------------------------------------

VideoManager::~VideoManager() {
	
	al_set_target_bitmap(NULL);

	// Destruimos o display da Allegro
	if( display )
		al_destroy_display ( display );

	// Reincializamos instance e display
	display  = nullptr;
	instance = nullptr;
	
	std::cout << "VideoManager was terminated!" << std::endl;

}

//---------------------------------------
VideoManager* VideoManager::createVideoManager ( unsigned int width,
        unsigned int height, DISPLAY_MODE mode ) {

	// Vericamos se instance ja foi instanciada
	if( !instance ) {
		
		// Criamos o display
		ALLEGRO_DISPLAY* _display;

		// Incializamos o display
		try {
			
			int aux = (int) mode;

			#if UNIX
			aux = aux | ALLEGRO_OPENGL;
			#endif

			// Setamos as flags do display
			al_set_new_display_flags( aux );

			// Criamos o display
			_display = al_create_display( width, height );
	
			// Setamos o allegro para usar bitmao na memoria de video.
			// Isso permite que a mesma utiliza aceleracao por hardware
			al_set_new_bitmap_flags( ALLEGRO_VIDEO_BITMAP );

			if( !_display ) {
				sgl::Exception ex( "Failed to initialize ALLEGRO_DISPLAY.");
				throw ex;
			}

		}//try
		catch( std::exception& ex ) {
			std::cout << ex.what() << std::endl;
			exit ( -1 );
		}//catch

		// Incializamos a instancia da classe
		instance = new VideoManager( _display, al_map_rgb ( 0, 0, 0 ) );

	}//if

	return instance;

}

//---------------------------------------

VideoManager* VideoManager::getVideoManager() {
	return instance;
}

//---------------------------------------

void VideoManager::disableScreenSaver ( bool disable ) {
	al_inhibit_screensaver( disable );
}

//---------------------------------------

VideoManager::operator ALLEGRO_DISPLAY*() const {
	return display;
}

//---------------------------------------

int VideoManager::getDisplayHeight() const {
	return al_get_display_height ( display );
}

//---------------------------------------

int VideoManager::getDisplayWidth() const {
	return al_get_display_width ( display );
}

//---------------------------------------

void VideoManager::setBackgroundColor ( unsigned char r, unsigned char g, unsigned char b ) {
	backGroundColor = al_map_rgb ( r, g, b );
}

//---------------------------------------

void VideoManager::setFitToScreen ( bool fit ) {
	al_set_display_flag ( display, ALLEGRO_FULLSCREEN_WINDOW, fit );
}

//---------------------------------------

void VideoManager::setWindowIcon( const char* fileName ) {

	// Criamos o image resource
	image::ImageResource* img;

	// Carregamos o arquivo de imagem
	img = image::ImageResource::createImageResource( fileName );

	// Setamos a imagem do display
	if( img ) 
		al_set_display_icon( display, *img );

}

//---------------------------------------

void VideoManager::setWindowPosition ( int pos_x, int pos_y ) {
	al_set_window_position ( display, pos_x, pos_y );
}

//---------------------------------------

void VideoManager::getWindowPosition ( int& pos_x, int& pos_y ) {
	al_get_window_position ( display, &pos_x, &pos_y );
}

//---------------------------------------

void VideoManager::setWindowTitle ( const char* title ) {

	if ( title != NULL ) {
		al_set_window_title ( display, title );
	}//if

}

//---------------------------------------

void VideoManager::refreshScreen() {
		
	// Atualizamos a tela
	al_flip_display();
	
	// Limpamos o backbuffer
	al_clear_to_color( backGroundColor );
}

//---------------------------------------

void VideoManager::refreshScreenRegion ( int x, int y, int width, int height ) {
	al_update_display_region ( x, y, width, height );
}

//-------------------------------------------

int VideoManager::getNumDisplayResolutions() {
	return al_get_num_display_modes();
}

//-------------------------------------------

void VideoManager::getResolution( unsigned int index, int& width, int& height ) {

	if( index >= ( unsigned int )al_get_num_display_modes() ) {

		std::string str( "Invalid value of index in method " );
		str += __FUNCTION__;
		str += " ";
		str += __FILE__;

		std::cout << str << std::endl;

		return;
	}

	ALLEGRO_DISPLAY_MODE disp_data;

	//Capturamos as informacoes da tela de acordo com a resolucao
	// escolhida por index
	al_get_display_mode( index, &disp_data );

	width  = disp_data.width;
	height = disp_data.height;

}

//------------------------------------------------------

void VideoManager::destroy() {

	// Verificamos se intance e null
	if( instance )
		delete instance; 	// Deletamos instance
		
}

//------------------------------------------------------
