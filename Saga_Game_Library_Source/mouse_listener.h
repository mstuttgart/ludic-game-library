#pragma once

#include "listener.h"
#include "mouse_event.h"

namespace sgl {
namespace event {

/**
 * @class MouseListener
 * @author Michell Stuttgart
 * @date 04/27/14
 * @file mouse_listener.h
 * @brief 
 */
class MouseListener : public Listener {

public:

	/**
	 * @brief 
	 */
	MouseListener();
	
	/**
	 * @brief 
	 */
	~MouseListener();

	/**
	 * @brief 
	 * @param ev
	 */
	void callMethods(Event& ev);

	/**
	 * @brief 
	 * @param ev
	 */
	virtual void buttonDown( const MouseEvent& ev ) = 0;
	
	/**
	 * @brief 
	 * @param ev
	 */
	virtual void buttonUp( const MouseEvent& ev ) = 0;

	/**
	 * @brief 
	 * @param ev
	 */
	virtual void move( const MouseEvent& ev ) {};
	
	/**
	 * @brief 
	 * @param ev
	 */
	virtual void leaveDisplay( const MouseEvent& ev ){};
	/**
	 * @brief 
	 * @param ev
	 */
	virtual void enterDisplay( const MouseEvent& ev ){};
};

}
} /* namespace */
