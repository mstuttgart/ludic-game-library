#include "video_manager.h"
#include "image_resource.h"

namespace sgl {

// Declarando as variaveis static
VideoManager* VideoManager::instance  = nullptr;
ALLEGRO_DISPLAY* VideoManager::display = nullptr;
ALLEGRO_COLOR VideoManager::backGroundColor = al_map_rgb ( 0, 0, 0 );

//---------------------------------------

VideoManager::~VideoManager() {

	if( display ) al_destroy_display ( display );
	instance = NULL;
}

//---------------------------------------
VideoManager* VideoManager::createVideoManager ( unsigned int width,
        unsigned int height,
        DISPLAY_MODE mode ) {

	// Vericamos se instance ja foi instanciada
	if( instance == nullptr ) {

		// Incializamos o display
		try {

			al_set_new_display_flags( ( int ) mode );

			display = al_create_display( width, height );

			if( !display  ) throw Exception::CREATE_DISPLAY;

		}
		catch( Exception::EXCEPTION& ex ) {

			std::cout << Exception::getError( ex ) << std::endl;
			exit ( -1 );

		}//catch

		// Incializamos a instancia da classe
		instance = new VideoManager;

	}//if

	return instance;

}

//---------------------------------------

VideoManager* VideoManager::getVideoManager() {

	return createVideoManager( 640, 480 );
}

//---------------------------------------

void VideoManager::disableScreenSaver ( bool disable ) {
	al_inhibit_screensaver( disable );
}

//---------------------------------------

ALLEGRO_DISPLAY* VideoManager::getDisplay() const {
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

	image::ImageResource* img;

	img = image::ImageResource::createImageResource( fileName );

	if( img ) al_set_display_icon( display, img->getBitmap() );

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

void VideoManager::setWindowDimension ( unsigned int w, unsigned int h ) {

	if ( al_acknowledge_resize ( display ) ) {
		al_resize_display ( display, w, h );
	}//if

}

//---------------------------------------

void VideoManager::setWindowTitle ( const char* title ) {

	if ( title != NULL ) {
		al_set_window_title ( display, title );
	}//if

}

//---------------------------------------

void VideoManager::refreshScreen() {
	al_flip_display();
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

void VideoManager::destroyVideoManager() {
	
	delete instance;

}

}// namespace
