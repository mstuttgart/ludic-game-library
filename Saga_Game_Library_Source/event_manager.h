#pragma once

#include "sgl.h"

namespace sgl {
namespace input {

class EventManager {

protected:

	/* Declaramos uma fila de eventos */
	ALLEGRO_EVENT_QUEUE* eventQueue;
	ALLEGRO_EVENT event;

protected:

	/**
	 * @brief 
	 * @param _eventQueue
	 */
	EventManager( ALLEGRO_EVENT_QUEUE* _eventQueue );
	
	/**
	 * @brief 
	 */
	virtual ~EventManager();

	/**
	 * @brief 
	 */
	virtual void updateEvents() = 0;

};

}
} /* namespace */
