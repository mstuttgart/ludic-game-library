/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is a FREE SOFTWARE released under the BSD License.              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "key_code.hpp"
#include <memory>

namespace Ludic {

/**
 * @file keyboard_manager.hpp
 * @author Michell Stuttgart
 * @date 03/23/14
 * @class KeyboardManager
 * @brief
 */
class KeyboardManager {

private:

	static std::unique_ptr<KeyboardManager> ms_instance;

	ALLEGRO_KEYBOARD_STATE current_state;
	ALLEGRO_KEYBOARD_STATE last_state;

private:


	/**
	 * @brief
	 */
	KeyboardManager();

public:

	/**
	 * @brief
	 */
	virtual ~KeyboardManager();

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

} /* namespace */
