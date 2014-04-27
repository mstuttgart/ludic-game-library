#pragma once

#include "listener.h"
#include "display_event.h"

namespace sgl {
namespace event {

/**
 * @class DisplayListener
 * @author Michell Stuttgart
 * @date 04/25/14
 * @file display_listener.h
 * @brief
 */
class DisplayListener : public Listener {

public:

	/**
	 * @brief 
	 */
	DisplayListener();

	/**
	 * @brief
	 */
	~DisplayListener();

	/**
	 * @brief
	 */
	virtual void callMethods(Event& ev);

	/**
	 * @brief 
	 * @param ev
	 */
	virtual void displayExpose( const DisplayEvent& ev ) {};

	/**
	 * @brief 
	 * @param ev
	 */
	virtual void displayResize( const DisplayEvent& ev ) {};

	/**
	 * @brief 
	 */
	virtual void displayClose() = 0;

	/**
	 * @brief 
	 */
	virtual void displayLost() {};

	/**
	 * @brief 
	 */
	virtual void displayFound() {};

	/**
	 * @brief 
	 */
	virtual void displaySwitchOut() {};

	/**
	 * @brief 
	 */
	virtual void displaySwitchIn() {};
	
};

}
} /* namespace */
