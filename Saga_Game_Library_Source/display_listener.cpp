#include "display_listener.h"

using namespace sgl::event;

//-----------------------------------------------------

DisplayListener::DisplayListener() : Listener() {}

//-----------------------------------------------------

DisplayListener::~DisplayListener() {}

//-----------------------------------------------------

void DisplayListener::callMethods(Event& ev) {

	// Analisamos o tipo de evento e chamamos seu respectivo metodo
	switch( ev.getType() ) {

	case ALLEGRO_EVENT_DISPLAY_CLOSE:
		displayClose();
		break;

	case ALLEGRO_EVENT_DISPLAY_EXPOSE:
		displayExpose( DisplayEvent(ev) );
		break;

	case ALLEGRO_EVENT_DISPLAY_RESIZE:
		displayResize( DisplayEvent(ev) );
		break;

	case ALLEGRO_EVENT_DISPLAY_LOST:
		displayLost();
		break;

	case ALLEGRO_EVENT_DISPLAY_FOUND:
		displayFound();
		break;

	case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
		displaySwitchOut();
		break;

	case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
		displaySwitchIn();
		break;

	default:
		break;

	}//switch
}
//-----------------------------------------------------
