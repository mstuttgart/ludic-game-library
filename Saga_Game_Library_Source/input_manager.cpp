#include "input_manager.h"

using namespace sgl::input;

//-----------------------------------------------------------

InputManager::InputManager( ALLEGRO_EVENT_QUEUE* _eventQueue ) : 
eventQueue(_eventQueue) {}

//-----------------------------------------------------------

InputManager::~InputManager() {
	
	// Destruimos a fila de eventos
	al_destroy_event_queue( eventQueue );
	
}

//-----------------------------------------------------------