#pragma once

#include "event.hpp"
#include "vector2_d.hpp"

namespace sgl {
namespace event {

/**
 * @file mouse_event.h
 * @author Michell Stuttgart
 * @date 04/27/14
 * @class MouseEvent
 * @brief
 */
class MouseEvent : public Event {

	Vector2D vAux;

public:

	/**
	 * @brief
	 * @param _event
	 */
	MouseEvent( ALLEGRO_EVENT* _event );

	/**
	 * @brief
	 */
	~MouseEvent();

	/**
	 * @brief
	 * @return
	 */
	const Vector2D& getPosition();

	/**
	 * @brief
	 * @return
	 */
	const Vector2D& getDeslocament();

	/**
	 * @brief
	 * @return
	 */
	unsigned getButton() const;

};

}
} /* namespace */
