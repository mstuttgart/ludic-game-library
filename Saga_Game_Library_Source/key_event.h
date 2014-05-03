#pragma once

#include "event.h" // Base class: sgl::event::Event

namespace sgl {
namespace event {

/**
 * @file key_event.h
 * @author Michell Stuttgart
 * @date 04/26/14
 * @class KeyEvent
 * @brief
 */
class KeyEvent : public Event {

public:

	/**
	 * @brief
	 * @param _event
	 */
	KeyEvent( ALLEGRO_EVENT* _event );

	/**
	 * @brief
	 */
	~KeyEvent();

	/**
	 * @brief
	 * @return
	 */
	int getKeyCode() const;

	/**
	 * @brief
	 * @return
	 */
	int getKeyChar() const;

	/**
	 * @brief
	 * @return
	 */
	unsigned getModifiKey() const;

	/**
	 * @brief
	 * @return
	 */
	bool isKeyRepeat() const;

};

}
} /* namespace */
