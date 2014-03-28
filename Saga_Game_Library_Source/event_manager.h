#pragma once

#include "sgl.h"
#include "event_source.h"

namespace sgl {
namespace input {

/**
 * @file event_manager.h
 * @author Michell Stuttgart
 * @date 03/23/14
 * @class EventManager
 * @brief
 */
class EventManager {

protected:

	// Declaramos uma fila de eventos 
	ALLEGRO_EVENT_QUEUE* eventQueue;

public:


	/**
	 * @brief
	 * @param _queue
	 * @param source
	 */
	EventManager();

	/**
	 * @brief
	 */
	virtual ~EventManager();
	
	bool isEmpty();
	
	void addEventSource( EventSource& source );
	
	void removeEventSource( EventSource& source );
	
	void pullEvent( ALLEGRO_EVENT *ret_event );

};

}
} /* namespace */
