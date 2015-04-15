#include "display_event.hpp"

using namespace sgl::event;
using namespace sgl;

//-------------------------------------------

DisplayEvent::DisplayEvent( ALLEGRO_EVENT* _event ) : Event(_event) {}

//-------------------------------------------

DisplayEvent::~DisplayEvent() {}

//-------------------------------------------

Vector2D DisplayEvent::getDimension() {
	return Vector2D( al_event.display.x, al_event.display.y );
}

//-------------------------------------------

Vector2D DisplayEvent::getPosition() {
	return Vector2D( al_event.display.width, al_event.display.height );
}

//-------------------------------------------
