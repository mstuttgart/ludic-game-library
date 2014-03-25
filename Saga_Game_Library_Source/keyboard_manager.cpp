#include "keyboard_manager.h"

using namespace sgl::input;
using namespace std;

KeyboardManager* KeyboardManager::ms_instance = nullptr;

//-----------------------------------------------------------

KeyboardManager::KeyboardManager(){
	cout << "KeyboardManager initialized successfully!" << endl << endl;
}

//-----------------------------------------------------------

KeyboardManager::~KeyboardManager() {
	cout << "KeyBoardManager was terminated!" << endl;
}

//-----------------------------------------------------------

KeyboardManager* KeyboardManager::getInstance() {
	
	cout << "==============================================" << endl;
	cout << "Initializing KeyboardManager... " << endl;
	cout << "==============================================\n" << endl;

	// Iniciamos a instancia da classe
	if ( !ms_instance ) 
		ms_instance = new KeyboardManager();

	return ms_instance;
}

//-----------------------------------------------------------

void KeyboardManager::release() {

	if ( ms_instance )
		delete ms_instance;

	ms_instance = nullptr;
}

//-----------------------------------------------------------

void KeyboardManager::update() {

	// Setamos o ultimo estado do teclado
	last_state = current_state;
	
	// Atualizamos o estado atual
	al_get_keyboard_state( &current_state );

}

//-----------------------------------------------------------

bool KeyboardManager::keyDown( KeyCode key ) {
	return al_key_down( &current_state, ( int ) key );
}

//-----------------------------------------------------------

bool KeyboardManager::keyPressed( KeyCode key ) {
	return ( !al_key_down( &last_state, ( int ) key ) &&
	         al_key_down( &current_state, ( int ) key ) );
}

//-----------------------------------------------------------

bool KeyboardManager::keyRelease( KeyCode key ) {
	return ( al_key_down( &last_state, ( int ) key ) &&
	         !al_key_down( &current_state, ( int ) key ) );
}

//-----------------------------------------------------------
