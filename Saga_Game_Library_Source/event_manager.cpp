#include "event_manager.h"

using namespace sgl::input;

//-----------------------------------------------------------

EventManager::EventManager() {

	// Criamos a fila de eventos
	eventQueue = al_create_event_queue();

	// Verificamos se a mesma foi iniciada corretamente
	if ( !eventQueue )
		std::cout << "Error to initialize event queue!" << std::endl;
		
}

//-----------------------------------------------------------

EventManager::~EventManager() {

	// Destruimos a fila de eventos
	al_destroy_event_queue( eventQueue );

}

//-----------------------------------------------------------

void EventManager::pullEvent( ALLEGRO_EVENT *ret_event ) {
	
	// Retiramos o primeiro evento da fila e
	// guardamos na variavel event
	al_wait_for_event( eventQueue, ret_event );
}

//-----------------------------------------------------------

void EventManager::addEventSource( EventSource& source ) {
	al_register_event_source( eventQueue, source );
}

//-----------------------------------------------------------

void EventManager::removeEventSource( EventSource& source ) {
}

//-----------------------------------------------------------

bool EventManager::isEmpty() {
	return al_event_queue_is_empty( eventQueue );
}

//-----------------------------------------------------------
