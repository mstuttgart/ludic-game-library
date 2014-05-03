#pragma once

#include "listener.h"
#include "key_event.h"

namespace sgl {
namespace event {

/**
 * @file key_listener.h
 * @author Michell Stuttgart
 * @date 04/23/14
 * @class KeyListener
 * @brief
 */
class KeyListener : public Listener {

public:

	/**
	 * @brief
	 */
	KeyListener();

	/**
	 * @brief
	 */
	virtual ~KeyListener();

	/**
	 * @brief
	 * @param ev
	 */
	void callMethods( Event& ev );

	/**
	 * @brief
	 * @param keyEvent
	 */
	virtual void keyDown( const KeyEvent& keyEvent ) = 0;

	/**
	 * @brief
	 * @param keyEvent
	 */
	virtual void keyRelease( const KeyEvent& keyEvent ) = 0;

	/**
	 * @brief
	 * @param keyEvent
	 */
	virtual void keyChar( const KeyEvent& keyEvent ){};

};

}
} /* namespace */
