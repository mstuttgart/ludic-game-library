#include "keyboard_manager.hpp"

using namespace Ludic;
using namespace std;

unique_ptr<KeyboardManager> KeyboardManager::ms_instance;

//////////////////////////////////////////////////////////////

KeyboardManager::KeyboardManager(){
	cout << "* KeyboardManager initialized successfully!" << endl << endl;
}

//////////////////////////////////////////////////////////////

KeyboardManager::~KeyboardManager() {
	cout << "\n* KeyBoardManager was terminated!" << endl << endl;
}

//////////////////////////////////////////////////////////////

KeyboardManager* KeyboardManager::Instance() {
	
	cout << "\n* Initializing KeyboardManager... " << endl;

	// Iniciamos a instancia da classe
	if ( ms_instance.get() == nullptr ) 
		ms_instance = unique_ptr<KeyboardManager>(new KeyboardManager());
		
	return ms_instance.get();
}

//////////////////////////////////////////////////////////////

void KeyboardManager::release() {

	if ( ms_instance.get() != nullptr )
		delete ms_instance.release();
}

//////////////////////////////////////////////////////////////

void KeyboardManager::update() {

	// Setamos o ultimo estado do teclado
	last_state = current_state;
	
	// Atualizamos o estado atual
	al_get_keyboard_state( &current_state );

}

//////////////////////////////////////////////////////////////

bool KeyboardManager::keyPressed( KeyCode key ) {
	return al_key_down( &current_state, ( int ) key );
}

//////////////////////////////////////////////////////////////

bool KeyboardManager::keyTyped( KeyCode key ) {
	return ( !al_key_down( &last_state, ( int ) key ) &&
	         al_key_down( &current_state, ( int ) key ) );
}

//////////////////////////////////////////////////////////////

bool KeyboardManager::keyRelease( KeyCode key ) {
	return ( al_key_down( &last_state, ( int ) key ) &&
	         !al_key_down( &current_state, ( int ) key ) );
}

//////////////////////////////////////////////////////////////
