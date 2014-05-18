#include "scene_manager.hpp"
#include "event.hpp"

using namespace sgl::input;
using namespace sgl::event;

//-----------------------------------------------------------

SceneManager::SceneManager( Scene* _scene, sgl::Video* _video, int FPS ) :
	video( _video ), scene( _scene ), redraw( false ), done( false )
{

	// Criamos a fila de eventos
	eventQueue = al_create_event_queue();
	timer      = al_create_timer( 1.0 / FPS );

	// Verificamos se a mesma foi iniciada corretamente
	if ( !eventQueue )
		throw sgl::Exception( "Error to initialize event queue!" );

	al_register_event_source( eventQueue, al_get_display_event_source( *video ));
	al_register_event_source( eventQueue, al_get_timer_event_source( timer ) );

}

//-----------------------------------------------------------

SceneManager::~SceneManager()
{
	// Destruimos a fila de eventos
	al_destroy_event_queue( eventQueue );
	al_destroy_timer( timer );
}

//----------------------------------------------------------

void SceneManager::addDisplayListener(DisplayListener* dListener)
{
	listeners.push_back( dListener );
}

//----------------------------------------------------------

void SceneManager::addKeyListener(KeyListener* kListener)
{
	listeners.push_back( kListener );
	al_register_event_source( eventQueue, al_get_keyboard_event_source() );
}

//-----------------------------------------------------------

bool SceneManager::isEmpty()
{
	return al_event_queue_is_empty( eventQueue );
}

//-----------------------------------------------------------

void SceneManager::initialize()
{
	scene->initialize();
}

//-----------------------------------------------------------

void SceneManager::execute()
{
	// Iniciamos o timer
	al_start_timer( timer );
	
	// Variavel que recebe o evento
	Event al_event;

	while( !done ) {

		// Retiramos um elemento da fila
		al_wait_for_event( eventQueue, al_event );
		
		// Verificamos se o evento foi causado pelo timer
		if( al_event.getType() == ALLEGRO_EVENT_TIMER )
		{
			// Executamos a logica de scene
			scene->logic();
			
			// Habilitamos a atualizacao do display 
			redraw = true;
		}
		else{
			
			// Chamamos cada uma das entradas e atualizamo seus eventos
			for( unsigned int i=0; i < listeners.size(); i++ ) {
				listeners[i]->callMethods( al_event );
			}			
		}

		// Atualizamos o conteudo da tela
		if( redraw && al_is_event_queue_empty( eventQueue ) ) {
			
			redraw = false;
			
			// Travamos o desenho na memoria de video
			al_hold_bitmap_drawing( true );
			
			// Chamamos o metodo de desenho
			scene->render();
			
			// Liberamos o conteudo para ser desenhado no display
			al_hold_bitmap_drawing( false );
			
			// Atualizamos o display
			video->refresh();
			
		}//if
		
		// Vefiricamos se devemos continuar no loop
		if( scene->isExitLoop() )
			done = true;

	}//while

}

//------------------------------------------------------------

void SceneManager::finalize()
{
	scene->finalize();
}

//------------------------------------------------------------