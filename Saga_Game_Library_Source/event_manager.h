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
	
	/**
	 * @brief 
	 * @return 
	 */
	bool isEmpty();
	
	/**
	 * @brief 
	 * @param source
	 */
	void addEventSource( EventSource& source );
	
	/**
	 * @brief 
	 * @param source
	 */
	void removeEventSource( EventSource& source );
	
	/**
	 * @brief 
	 * @param ret_event
	 */
	void pullEvent( ALLEGRO_EVENT *ret_event );

};

}
} /* namespace */
