#include "keyboard_manager.h"

using namespace sgl::input;
using namespace std;

unique_ptr<KeyboardManager> KeyboardManager::ms_instance;

//-----------------------------------------------------------

KeyboardManager::KeyboardManager(){
	cout << "KeyboardManager initialized successfully!" << endl << endl;
}

//-----------------------------------------------------------

KeyboardManager::~KeyboardManager() {
	cout << "KeyBoardManager was terminated!" << endl;
}

//-----------------------------------------------------------

KeyboardManager* KeyboardManager::Instance() {
	
	cout << "==============================================" << endl;
	cout << "Initializing KeyboardManager... " << endl;
	cout << "==============================================\n" << endl;

	// Iniciamos a instancia da classe
	if ( !ms_instance.get() ) 
		ms_instance = unique_ptr<KeyboardManager>(new KeyboardManager());
		
	return ms_instance.get();
}

//-----------------------------------------------------------

void KeyboardManager::release() {

	if ( ms_instance.get() )
		delete ms_instance.release();
}

//-----------------------------------------------------------

void KeyboardManager::update() {

	// Setamos o ultimo estado do teclado
	last_state = current_state;
	
	// Atualizamos o estado atual
	al_get_keyboard_state( &current_state );

}

//-----------------------------------------------------------

bool KeyboardManager::keyPressed( KeyCode key ) {
	return al_key_down( &current_state, ( int ) key );
}

//-----------------------------------------------------------

bool KeyboardManager::keyTyped( KeyCode key ) {
	return ( !al_key_down( &last_state, ( int ) key ) &&
	         al_key_down( &current_state, ( int ) key ) );
}

//-----------------------------------------------------------

bool KeyboardManager::keyRelease( KeyCode key ) {
	return ( al_key_down( &last_state, ( int ) key ) &&
	         !al_key_down( &current_state, ( int ) key ) );
}

//-----------------------------------------------------------
