#include "mouse_manager.hpp"

using namespace Ludic;
using namespace std;


unique_ptr<MouseManager> MouseManager::ms_instance = nullptr;

//////////////////////////////////////////////////////////////

MouseManager::MouseManager( Video* _video ) :
	display( _video ), cursor( nullptr ), visible( true )
{

	// Inciando suporte ao mouse
	if ( !al_install_mouse() ) {
		throw Ludic::Exception( "Failed to initialize ALLEGRO_MOUSE_SUPPORT." );
	}

	// Atribui o cursor padrão do sistema para ser usado
	al_set_system_mouse_cursor(
	    *_video, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT );

	cout << "* MouseManager initialized successfully!" << endl << endl;

}

//////////////////////////////////////////////////////////////

MouseManager::~MouseManager()
{

	cout << "\n* MouseManager was terminated!" << endl;

	if( cursor != nullptr )
		al_destroy_mouse_cursor( cursor );
}

//////////////////////////////////////////////////////////////

void MouseManager::update()
{

	// Setamos o ultimo estado do teclado
	last_state = current_state;

	// Atualizamos o estado atual
	al_get_mouse_state( &current_state );

	// Atualizamos o Point que guarda a antiga posicao do cursor
	lastPosition = currentPosition;

	// Atualizamos a posicao do mouse
	currentPosition = Vector2D( current_state.x, current_state.y );

}

//////////////////////////////////////////////////////////////

MouseManager* MouseManager::Instance( Video* _video )
{

	cout << "\n* Initializing MouseManager... " << endl;

	// Iniciamos a instancia da classe
	if ( ms_instance.get() == nullptr && _video != nullptr )
		ms_instance = unique_ptr<MouseManager>(new MouseManager(_video));

	return ms_instance.get();
}

//////////////////////////////////////////////////////////////

void MouseManager::release()
{

	if ( ms_instance.get() != nullptr )
		ms_instance.release();
}

//////////////////////////////////////////////////////////////

bool MouseManager::buttonDown( int button )
{
	return al_mouse_button_down( &current_state, button );
}

//////////////////////////////////////////////////////////////

bool MouseManager::buttonPressed( int button )
{
	return ( !al_mouse_button_down( &last_state, button )
	         && al_mouse_button_down( &current_state, button ) );
}

//////////////////////////////////////////////////////////////

bool MouseManager::buttonRelease( int button )
{
	return ( al_mouse_button_down( &last_state, button )
	         && !al_mouse_button_down( &current_state, button ) );
}

//////////////////////////////////////////////////////////////

unsigned int MouseManager::getAxesSize() const
{
	return al_get_mouse_num_axes();
}

//////////////////////////////////////////////////////////////

unsigned int MouseManager::getButtonSize() const
{
	return al_get_mouse_num_buttons();
}

//////////////////////////////////////////////////////////////

bool MouseManager::isVisible() const
{
	return visible;
}

//////////////////////////////////////////////////////////////

void MouseManager::setCursorVisible( bool visible )
{

	if( visible )
		al_show_mouse_cursor( *display );
	else
		al_hide_mouse_cursor( *display );

	this->visible = visible;
}

//////////////////////////////////////////////////////////////

bool MouseManager::setMouseCursor( ImageResource* bitmap )
{

	// Se existir um cursor, ele e deletado
	al_destroy_mouse_cursor( cursor );

	// Criamos o cursor
	cursor = al_create_mouse_cursor( *bitmap, 0, 0 );

	// Setamos o novo cursor
	return al_set_mouse_cursor( *display, cursor );
}

//////////////////////////////////////////////////////////////

bool MouseManager::setMousePosition( const Vector2D& vec )
{
	return al_set_mouse_xy( *display, vec.getX(), vec.getY() );
}

//////////////////////////////////////////////////////////////

bool MouseManager::setSystemMouseCursor( SystemCursor cursor )
{
	return al_set_system_mouse_cursor(
	           *display, ( ALLEGRO_SYSTEM_MOUSE_CURSOR ) cursor );
}

//////////////////////////////////////////////////////////////

const Vector2D& MouseManager::getPosition()
{
	return currentPosition;
}

//////////////////////////////////////////////////////////////

Vector2D MouseManager::getWarp()
{
	return ( currentPosition - lastPosition );
}

//////////////////////////////////////////////////////////////
