#include "key_listener.hpp"

using namespace sgl::event;

//--------------------------------------------------------

KeyListener::KeyListener() : Listener(){}

//-------------------------------------------------------

KeyListener::~KeyListener() {}

//--------------------------------------------------------

void KeyListener::callMethods( Event& ev ) {
	
	// Verificamos o tipo do evento
	switch( ev.getType() ) {
		
		case ALLEGRO_EVENT_KEY_DOWN:
			keyDown( KeyEvent( ev ) );
			break;
		
		case ALLEGRO_EVENT_KEY_UP:
			keyRelease( KeyEvent( ev ) );
			break;
			
		case ALLEGRO_EVENT_KEY_CHAR:
			keyChar( KeyEvent( ev ) );
			break;
			
		default:
			break;
			
	}//switch
	
}

//--------------------------------------------------------
