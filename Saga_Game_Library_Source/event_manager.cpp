#include "event_manager.h"
#include "application.h"
#include "video_manager.h"

using namespace sgl::input;

//-----------------------------------------------------------

EventManager::EventManager( Scene& _scene ) : 
scene( _scene ), redraw( false ), done( false ) {

	// Criamos a fila de eventos
	eventQueue = al_create_event_queue();
	timer      = al_create_timer( 1.0 / 60 );

	// Verificamos se a mesma foi iniciada corretamente
	if ( !eventQueue )
		std::cout << "Error to initialize event queue!" << std::endl;
		
	scene.initialize();


	al_register_event_source( eventQueue, al_get_keyboard_event_source() );
	al_register_event_source( eventQueue, al_get_display_event_source(*VideoManager::Instance()));
	al_register_event_source( eventQueue, al_get_timer_event_source( timer ) );
	
	//mapa[ALLEGRO_EVENT_KEY_DOWN] = Scene::finalize();
	//mapa[ALLEGRO_EVENT_KEY_DOWN] = fp;




}

//-----------------------------------------------------------

EventManager::~EventManager() {

	// Destruimos a fila de eventos
	al_destroy_event_queue( eventQueue );
	al_destroy_timer( timer );

}

//-----------------------------------------------------------

bool EventManager::isEmpty() {
	return al_event_queue_is_empty( eventQueue );
}

//-----------------------------------------------------------

void EventManager::execute() {

	al_start_timer( timer );

	while( !done ) {
		
		ALLEGRO_EVENT ev;

		al_wait_for_event( eventQueue, &ev );

		switch( ev.type ) {

			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				done = true;
				break;
				
			case ALLEGRO_EVENT_KEY_DOWN:
				scene.keyDown( ev.keyboard.keycode );
				break;
				
			case ALLEGRO_EVENT_KEY_UP:
				scene.keyRelease( ev.keyboard.keycode );
				break;

			case ALLEGRO_EVENT_TIMER:
				scene.logic();
				redraw = true;
				break;

		}//switch


		if( redraw && al_is_event_queue_empty( eventQueue ) ) {
			redraw = false;
			scene.render();
		}//if

	}//while

}
