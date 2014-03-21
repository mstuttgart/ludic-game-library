#pragma once

#include "sgl.h"

namespace sgl {
namespace input {

class InputManager {

protected:

	/* Declaramos uma fila de eventos */
	ALLEGRO_EVENT_QUEUE* eventQueue;
	ALLEGRO_EVENT event;

protected:

	InputManager( ALLEGRO_EVENT_QUEUE* _eventQueue );
	virtual ~InputManager();

	virtual void update() = 0;

};

}
} /* namespace */
