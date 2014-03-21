#pragma once

#include "input_manager.h" // Base class: sgl::input::InputManager
#include <map>

namespace sgl {
namespace input {
	
enum class KeyState { PRESSED, TYPED, RELEASED, INACTIVE };

class KeyboardManager : public InputManager {

	static KeyboardManager* ms_instance;
	KeyState keyVector[ALLEGRO_KEY_MAX];
	
	std::map<int, bool> keyMap;
	std::map<int, bool>::iterator it;

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
	virtual void update();
	
	/**
	 * @brief 
	 * @param key
	 * @return 
	 */
	const KeyState& getKeyState( int key );
	
};

}
} /* namespace */
