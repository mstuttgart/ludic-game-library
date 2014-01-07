#include "VideoManager.h"
#include "HardwareException.h"

namespace sgl {

// Declarando as variaveis static
VideoManager* VideoManager::instance  = nullptr;
ALLEGRO_DISPLAY* VideoManager::display = nullptr;
ALLEGRO_EVENT_QUEUE* VideoManager::eventQueue = nullptr;
ALLEGRO_COLOR VideoManager::backGroundColor = al_map_rgb ( 0, 0, 0 );

//---------------------------------------

VideoManager::~VideoManager() {

	if ( display != nullptr ) al_destroy_display ( display );

	if( eventQueue != nullptr ) al_destroy_event_queue( eventQueue );

	delete instance;
}

//---------------------------------------
VideoManager* VideoManager::createVideoManager ( unsigned int dWidth, unsigned int dHeight, DISPLAY_MODE dMode ) {

	// Vericamos se instance ja foi instanciada
	if( instance != nullptr ) {

		// Incializamos o display
		try {
			al_set_new_display_flags( ALLEGRO_RESIZABLE | ( int ) dMode );
			display = al_create_display( dWidth, dHeight );
			
			if( !display )
			{
				HardwareException ex;
				throw ex;
			}//if
		}
		catch( HardwareException& ex ) {
			std::cout << "Error occured in VideoManager. Display not init" << ex.what() << std::endl;
			exit ( -1 );
		}
		catch( std::exception& ex ) {
			std::cout << ex.what() << std::endl;
			exit ( -1 );
		}
		
		// Inicializamos a fila de eventos do display
		al_register_event_source( eventQueue, al_get_display_event_source( display ) );
		
		if( !eventQueue )
		{
			std::cout << "Error occured in VideoManager. Init of Event Queue." 
			<< " You not catch the display events" << std::endl;
		}

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

void VideoManager::setWindowIcon() {

}

//---------------------------------------

void VideoManager::setWindowPosition ( int pos_x, int pos_y ) {
	al_set_window_position ( display, pos_x, pos_y );
}

//---------------------------------------

void VideoManager::getWindowPosition ( int* pos_x, int* pos_y ) {
	al_get_window_position ( display, pos_x, pos_y );
}

//---------------------------------------

void VideoManager::setWindowDimension ( unsigned int w, unsigned int h ) {
	if ( al_acknowledge_resize ( display ) ) al_resize_display ( display, w, h );
}

//---------------------------------------

void VideoManager::setWindowTitle ( const char* title ) {
	if ( title != NULL ) al_set_window_title ( display, title );
}

//---------------------------------------

void VideoManager::refreshScreen() {
	al_flip_display();
}

//---------------------------------------

void VideoManager::updateScreenRegion ( int x, int y, int width, int height ) {
	al_update_display_region ( x, y, width, height );
}

//--------------------------------------

bool VideoManager::getDisplayStatus( DISPLAY_EVENT event ) {
	
	while( !al_is_event_queue_empty( eventQueue ) ) {		
		
		ALLEGRO_EVENT ev;
		
		al_wait_for_event( eventQueue, &ev );
		
		if( ev.type == ( int ) event ) return true;
			
	}//while

	return false;
	
}

//-------------------------------------------

}// namespace
