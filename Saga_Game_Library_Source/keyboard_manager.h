#pragma once

#include "key_code.h"

namespace sgl {
namespace input {

/**
 * @file keyboard_manager.h
 * @author Michell Stuttgart
 * @date 03/23/14
 * @class KeyboardManager
 * @brief
 */
class KeyboardManager {

private:

	static KeyboardManager* ms_instance;

	ALLEGRO_KEYBOARD_STATE current_state;
	ALLEGRO_KEYBOARD_STATE last_state;

private:

	/**
	 * @brief
	 */
	KeyboardManager();

	/**
	 * @brief
	 */
	virtual ~KeyboardManager();

public:

	/**
	 * @brief
	 * @return
	 */
	static KeyboardManager* Instance();

	/**
	 * @brief
	 */
	static void release();


	/**
	 * @brief
	 */
	virtual void update();

	/**
	 * @brief
	 * @param key
	 * @return
	 */
	bool keyPressed( KeyCode key );

	/**
	 * @brief
	 * @param key
	 * @return
	 */
	bool keyTyped( KeyCode key );

	/**
	 * @brief
	 * @param key
	 * @return
	 */
	bool keyRelease( KeyCode key );

};

}
} /* namespace */
