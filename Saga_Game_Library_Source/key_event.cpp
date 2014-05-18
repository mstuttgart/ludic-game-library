#include "key_event.hpp"

using namespace sgl::event;

//----------------------------------------

KeyEvent::KeyEvent( ALLEGRO_EVENT* _event ) : Event(_event) {}

//----------------------------------------

KeyEvent::~KeyEvent() {}

//-------------------------------------------------

int KeyEvent::getKeyChar() const {
	return al_event.keyboard.unichar;
}

//-------------------------------------------------

int KeyEvent::getKeyCode() const {
	return al_event.keyboard.keycode;
}
//-------------------------------------------------

unsigned KeyEvent::getModifiKey() const {
	return al_event.keyboard.modifiers;
}

//-------------------------------------------------

bool KeyEvent::isKeyRepeat() const {
	return al_event.keyboard.repeat;
}

//-------------------------------------------------