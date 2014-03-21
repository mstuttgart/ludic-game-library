#include "keyboard_manager.h"

using namespace sgl::input;

KeyboardManager* KeyboardManager::ms_instance = nullptr;

//-----------------------------------------------------------

KeyboardManager::KeyboardManager( ALLEGRO_EVENT_QUEUE* _eventQueue ) :
	InputManager( _eventQueue ) {

	// Registramos o teclado como fonte de eventos
	al_register_event_source( _eventQueue, al_get_keyboard_event_source() );

	// Inicializamos o vetor de estados
	for( int i=0; i<ALLEGRO_KEY_MAX; i++ )
		keyVector[ i ] = KeyState::INACTIVE;

}

//-----------------------------------------------------------

KeyboardManager::~KeyboardManager() {
	std::cout << "KeyBoardManager was terminated!" << std::endl;
}

//-----------------------------------------------------------

KeyboardManager* KeyboardManager::getInstance() {

	if ( !ms_instance ) {

		// Iniciamos a fila de eventos
		ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

		if( !event_queue ) {
			std::cout << "Error at create ALLEGRO_EVENT_QUEUE "
			          << "in KeyboardManager. " << std::endl;

			return nullptr;
		}//if

		// Iniciamos a instancia da classe
		ms_instance = new KeyboardManager( event_queue );

	}//if

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

	// Ficamos no loop ate que a fila esteja vazia
	while( !al_event_queue_is_empty( eventQueue ) ) {

		// Retiramos o primeiro evento da fila e guardamos na variavel event
		al_wait_for_event( eventQueue, &event );

		// Atualizamos o eventos da tecla
		switch( event.type ) {

			case ALLEGRO_EVENT_KEY_DOWN:
				keyMap[ event.keyboard.keycode ] = true;
				break;

			case ALLEGRO_EVENT_KEY_UP:
				keyMap[ event.keyboard.keycode ] = false;
				break;

			default:
				break;

		}//switch

	}//while

	// Atualizamos a maquina de estado das teclas
	keyStateUpdate();

}
//-----------------------------------------------------------

void KeyboardManager::keyStateUpdate() {

	for( it = keyMap.begin(); it != keyMap.end(); ++it ) {

		if( it->second ) {

			// Esse switch funciona como uma maquina de estados
			switch( keyVector[ it->first ] ) {

				case KeyState::INACTIVE:
					keyVector[ it->first ] = KeyState::TYPED;
					break;

				case KeyState::TYPED:
					keyVector[ it->first ] = KeyState::PRESSED;
					break;

				case KeyState::RELEASED:
					keyVector[ it->first ] = KeyState::INACTIVE;
					break;

				default:
					break;

			}//switch

		}//if
		else {

			// Verificamos o tipo de evento
			switch( keyVector[ it->first ] ) {

				case KeyState::RELEASED: // Tecla inativa
					keyVector[ it->first ] = KeyState::INACTIVE;
					break;

				default:
					keyVector[ it->first ] = KeyState::RELEASED;
					break;

			}//switch

		}//else if

	}//for map

}

//-----------------------------------------------------------

const KeyState& KeyboardManager::getKeyState( int key ) {

	if( key < ALLEGRO_KEY_MAX )
		return keyVector[ key ];

	return KeyState::INACTIVE;
}

//-----------------------------------------------------------

//-----------------------------------------------------------
