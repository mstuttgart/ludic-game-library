#pragma once

#include "event.h" // Base class: sgl::event::Event
#include "vector2_d.h"

namespace sgl {
namespace event {

/**
 * @file display_event.h
 * @author Michell Stuttgart
 * @date 04/26/14
 * @class DisplayEvent
 * @brief
 */
class DisplayEvent : public Event {

public:

	/**
	 * @brief
	 * @param _event
	 */
	DisplayEvent( ALLEGRO_EVENT* _event );

	/**
	 * @brief
	 */
	~DisplayEvent();

	/**
	 * @brief
	 * @return
	 */
	sgl::Vector2D getPosition();

	/**
	 * @brief
	 * @return
	 */
	sgl::Vector2D getDimension();

};

}} /* namespace */
