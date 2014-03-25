#include "event_manager.h"

using namespace sgl::input;

//-----------------------------------------------------------

EventManager::EventManager(
    ALLEGRO_EVENT_QUEUE* _queue, ALLEGRO_EVENT_SOURCE *source ) :
	eventQueue( _queue ) {
		
	// Registramos source como finte de eventos
	// e _queue como a fila que recebera esses eventos
	al_register_event_source( _queue, source );
}

//-----------------------------------------------------------

EventManager::~EventManager() {

	// Destruimos a fila de eventos
	al_destroy_event_queue( eventQueue );
}

//-----------------------------------------------------------

/*void EventManager::pullEvent(Event* eventClass)
{
	// Retiramos o primeiro evento da fila e guardamos na variavel event
	al_wait_for_event( eventQueue, *eventClass );
}*/
