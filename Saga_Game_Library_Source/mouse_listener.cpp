#include "mouse_listener.hpp"

using namespace sgl::event;

//////////////////////////////////////////////////////////////

MouseListener::MouseListener() {
}

//////////////////////////////////////////////////////////////

MouseListener::~MouseListener() {
}

//////////////////////////////////////////////////////////////

void MouseListener::callMethods( Event& ev ) {
	
	// Verificamos o tipo do evento
	switch( ev.getType() ) {
		
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			buttonDown( MouseEvent( ev ) );
			break;
		
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			buttonUp( MouseEvent( ev ) );
			break;
			
		case ALLEGRO_EVENT_MOUSE_AXES:
			move( MouseEvent( ev ) );
			break;
			
		case ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY:
			leaveDisplay( MouseEvent( ev ) );
			break;
			
		case ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY:
			enterDisplay( MouseEvent( ev ) );
			break;
			
		default:
			break;
			
	}//switch
	
}

//////////////////////////////////////////////////////////////