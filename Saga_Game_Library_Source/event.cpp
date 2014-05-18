#include "event.hpp"

using namespace sgl::event;

//------------------------------------------

Event::Event( ALLEGRO_EVENT* _event ):al_event(*_event){}

//------------------------------------------

Event::~Event() {}

//------------------------------------------

unsigned int Event::getType() const {
	return al_event.type;
}

//------------------------------------------

Event::operator ALLEGRO_EVENT*() {
	return &al_event;
}

//------------------------------------------
