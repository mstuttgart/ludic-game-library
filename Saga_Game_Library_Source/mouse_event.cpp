#include "mouse_event.h"

using namespace sgl::event;
using namespace sgl;

//----------------------------------------------------

MouseEvent::MouseEvent( ALLEGRO_EVENT* _event ) :
	Event(_event), vAux(_event->mouse.x, _event->mouse.y) {}

//----------------------------------------------------

MouseEvent::~MouseEvent() {}

//----------------------------------------------------

unsigned MouseEvent::getButton() const {
	return al_event.mouse.button;
}

//----------------------------------------------------

const Vector2D& MouseEvent::getDeslocament() {
	vAux.setCoordenate( al_event.mouse.dx, al_event.mouse.dy );
	return vAux;
}

//----------------------------------------------------

const Vector2D& MouseEvent::getPosition() {
	vAux.setCoordenate( al_event.mouse.x, al_event.mouse.y );
	return vAux;
}

//----------------------------------------------------
