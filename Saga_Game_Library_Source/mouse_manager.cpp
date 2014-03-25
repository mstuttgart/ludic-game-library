#include "mouse_manager.h"

using namespace sgl::input;
using namespace std;

MouseManager* MouseManager::instance = nullptr;

//--------------------------------------------------

MouseManager::MouseManager( VideoManager* _videoManager ) :
	videoManager( _videoManager ), cursor( nullptr ), visible( true ) {

	// Atribui o cursor padrão do sistema para ser usado
	al_set_system_mouse_cursor(
	    *_videoManager, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT );
	
	cout << "MouseManager initialized successfully!" << endl << endl;

}

//--------------------------------------------------

MouseManager::~MouseManager() {
	
	cout << "MouseManager was terminated!" << endl;

	if( cursor )
		al_destroy_mouse_cursor( cursor );
}

//--------------------------------------------------

void MouseManager::update() {

	// Setamos o ultimo estado do teclado
	last_state = current_state;

	// Atualizamos o estado atual
	al_get_mouse_state( &current_state );

	// Atualizamos o Point que guarda a antiga posicao do cursor
	lastPoint.setX( currentPoint.getX() );
	lastPoint.setY( currentPoint.getY() );

	// Atualizamos a posicao do mouse
	currentPoint.setX( current_state.x );
	currentPoint.setY( current_state.y );

}

//--------------------------------------------------

MouseManager* MouseManager::getInstance( VideoManager* _videoManager ) {
	
	cout << "==============================================" << endl;
	cout << "Initializing MouseManager... " << endl;
	cout << "==============================================\n" << endl;

	// Iniciamos a instancia da classe
	if ( !instance && _videoManager )
		instance = new MouseManager( _videoManager );

	return instance;
}

//--------------------------------------------------

void MouseManager::release() {

	if ( instance )
		delete instance;

	instance = nullptr;
}

//--------------------------------------------------

bool MouseManager::buttonDown( int button ) {
	return al_mouse_button_down( &current_state, button );
}

//--------------------------------------------------

bool MouseManager::buttonPressed( int button ) {
	return ( !al_mouse_button_down( &last_state, button )
	         && al_mouse_button_down( &current_state, button ) );
}

//--------------------------------------------------

bool MouseManager::buttonRelease( int button ) {
	return ( al_mouse_button_down( &last_state, button )
	         && !al_mouse_button_down( &current_state, button ) );
}

//--------------------------------------------------

unsigned int MouseManager::getAxesSize() const {
	return al_get_mouse_num_axes();
}

//--------------------------------------------------

unsigned int MouseManager::getButtonSize() const {
	return al_get_mouse_num_buttons();
}

//--------------------------------------------------

bool MouseManager::isVisible() const {
	return visible;
}

//--------------------------------------------------

void MouseManager::setCursorVisible( bool visible ) {

	if( visible )
		al_show_mouse_cursor( *videoManager );
	else
		al_hide_mouse_cursor( *videoManager );

	this->visible = visible;
}

//--------------------------------------------------

bool MouseManager::setMouseCursor( ImageResource* bitmap ) {

	// Se existir um cursor, ele e deletado
	al_destroy_mouse_cursor( cursor );

	// Criamos o cursor
	cursor = al_create_mouse_cursor( *bitmap, 0, 0 );

	// Setamos o novo cursor
	return al_set_mouse_cursor( *videoManager, cursor );
}

//--------------------------------------------------

bool MouseManager::setMousePosition( int x, int y ) {
	return al_set_mouse_xy( *videoManager, x, y );
}

//--------------------------------------------------

bool MouseManager::setSystemMouseCursor( SystemCursor cursor ) {
	return al_set_system_mouse_cursor(
	           *videoManager, ( ALLEGRO_SYSTEM_MOUSE_CURSOR ) cursor );
}

//--------------------------------------------------

const Point& MouseManager::getPosition() {
	return currentPoint;
}

void MouseManager::getWarp( int* dx, int* dy ) {
	*dx = currentPoint.getX() - lastPoint.getX();
	*dy = currentPoint.getY() - lastPoint.getY();
}
