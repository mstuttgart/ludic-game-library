#pragma once

#include "event.h"
#include "vector2_d.h"

namespace sgl {
namespace event {

/**
 * @class MouseEvent
 * @author Michell Stuttgart
 * @date 04/27/14
 * @file mouse_event.h
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
