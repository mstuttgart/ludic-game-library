#pragma once

#include "listener.h"
#include "key_event.h"

namespace sgl {
namespace event {

/**
 * @class KeyListener
 * @author Michell Stuttgart
 * @date 04/23/14
 * @file key_listener.h
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
	 */
	void callMethods( Event& ev );

	/**
	 * @brief
	 * @param ev
	 */
	virtual void keyDown( const KeyEvent& keyEvent ) = 0;

	/**
	 * @brief
	 * @param ev
	 */
	virtual void keyRelease( const KeyEvent& keyEvent ) = 0;

	/**
	 * @brief
	 * @param ev
	 */
	virtual void keyChar( const KeyEvent& keyEvent ){};

};

}
} /* namespace */
