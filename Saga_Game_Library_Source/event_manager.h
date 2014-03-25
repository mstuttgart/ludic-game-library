#pragma once

#include "sgl.h"

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

	/* Declaramos uma fila de eventos */
	ALLEGRO_EVENT_QUEUE* eventQueue;
	ALLEGRO_EVENT event;

public:


	/**
	 * @brief
	 * @param _queue
	 * @param source
	 */
	EventManager( ALLEGRO_EVENT_QUEUE* _queue, ALLEGRO_EVENT_SOURCE *source );

	/**
	 * @brief
	 */
	virtual ~EventManager();

	/**
	 * @brief
	 */
	virtual void updateEvents() = 0;
	
	bool isEmpty(){
		return al_event_queue_is_empty( eventQueue );
	}
	
	//void pullEvent( Event* eventClass );

};

}
} /* namespace */
