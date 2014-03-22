#include "event_manager.h"

using namespace sgl::input;

//-----------------------------------------------------------

EventManager::EventManager( ALLEGRO_EVENT_QUEUE* _eventQueue ) : 
eventQueue(_eventQueue) {}

//-----------------------------------------------------------

EventManager::~EventManager() {	
	
	// Destruimos a fila de eventos
	al_destroy_event_queue( eventQueue ); 
}

//-----------------------------------------------------------