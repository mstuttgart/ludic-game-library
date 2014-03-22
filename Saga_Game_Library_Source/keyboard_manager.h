#pragma once

#include "event_manager.h" // Base class: sgl::input::InputManager
#include "key_code.h"
#include <map>

namespace sgl {
namespace input {
	
enum class KeyState : std::uint8_t { PRESSED, TYPED, RELEASED, INACTIVE };

class KeyboardManager : public EventManager {

	static KeyboardManager* ms_instance;
	KeyState keyVector[ALLEGRO_KEY_MAX];
	
	std::map<int, bool> keyMap;
	std::map<int, bool>::iterator it;
	std::map<int, bool>::iterator itend;
	int aux;

public:

	/**
	 * @brief
	 * @return
	 */
	static KeyboardManager* getInstance();

	/**
	 * @brief
	 */
	static void release();

private:

	/**
	 * @brief
	 * @param _eventQueue
	 */
	KeyboardManager( ALLEGRO_EVENT_QUEUE* _eventQueue );

	/**
	 * @brief
	 */
	virtual ~KeyboardManager();
	
	/**
	 * @brief 
	 */
	void keyStateUpdate();

public:

	/**
	 * @brief
	 */
	virtual void updateEvents();
	
	/**
	 * @brief 
	 * @param key
	 * @return 
	 */
	const KeyState& getKeyState( KeyCode key );
	
};

}
} /* namespace */
