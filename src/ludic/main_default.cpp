#include "video.hpp"
#include "static_sprite.hpp"
#include "animated_sprite.hpp"
#include "keyboard_manager.hpp"
#include "mouse_manager.hpp"
#include "font.hpp"
#include "time_handler.hpp"
#include "color.hpp"
#include "config_file_stream.hpp"
#include "tmx_tile_map.hpp"
#include "util.hpp"
#include "audio_sample.hpp"
#include "audio_stream.hpp"

using namespace Ludic;
using namespace std;

/* Constantes do sprite*/
#define FPS 90

int main() {

	//---------------------------

	Video video( 800, 515 );

	video.setTitle( "Saga Game Library" );
	video.setIcon( "Resource/icone.png" );
	
	video.setBackgroundColor( Color(145,184,60) );

	//-----------------------------------------------

	// Inicializamos os dispositivos de entrada
	KeyboardManager* keyboard = KeyboardManager::Instance();

	//-----------------------------------------------

	AnimatedSprite spr;
	spr.load( "Resource/mapas/personagem.tmx" );

	// Ajustamos posicao do sprite
	spr.setPosition( Vector2D( 100.0f, 100.0f ) );

	// Colocamos o sprite como visible
	spr.setVisible( true );
	
	//------------------------------------------
	
	StaticSprite spr1;
	StaticSprite spr2;
	
	spr1.load( "Resource/icone.png" );
	spr2.load( "Resource/circle.png" );
	
	spr1.setVisible( true );
	spr2.setVisible( true );
	
	spr1.setPosition( Vector2D( 200.0f, 200.0f ) );
	spr2.setPosition( Vector2D( 200.0f, 300.0f ) );

	//------------------------------------------

	AudioStream musica;
	musica.load( "Resource/audio/Lost Frontier.ogg", 4, 1024 );

	AudioSample sample;
	AudioSample sample2;
	sample.load( "Resource/audio/chirp.ogg" );
	sample2.load( "Resource/audio/static.ogg" );

	//-------------------------------------------

	Font texto;
	texto.load( "Resource/Samurai.ttf", 40 );
	texto.setColorFont( Color( 255, 255, 255 ) );

	//-------------------------------------------

	TMXTileMap mapa;

	if( mapa.load( "Resource/rpg/mapa.tmx" ) )
		cout << "Carregou mapa com sucesso" << endl;
		
	mapa.setScreenDimension( video.getWidth(), video.getHeight() );

	//-------------------------------------------

	std::vector<Layer*> layerManager;

	layerManager.push_back( mapa.getLayer( "Piso" ) );
	layerManager.push_back( &spr );
	layerManager.push_back( &spr1 );
	layerManager.push_back( &spr2);
	layerManager.push_back( mapa.getLayer( "Objetos" ) );
	layerManager.push_back( mapa.getLayer( "Arvores" ) );
	layerManager.push_back( mapa.getLayer( "Colisao" ) );

	TiledLayer* l = mapa.getLayer( "Colisao" );
	
	//-----------------------------------------

	int movex = 0;
	int movey = 0;

	//-----------------------------------------

	double div = 1.0 / FPS;
	bool sair  = false;

	TimeHandler fpsTimer;

	//-----------------------------------------

	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_TIMER *timer             = al_create_timer( div );

	al_register_event_source( event_queue, al_get_display_event_source( video ) );
	al_register_event_source( event_queue, al_get_timer_event_source( timer ) );

	bool redraw = false;

	// Capturamos o tempo inicial
	//fpsTimer.start();

	//double cTime;

	Vector2D desloc( 0 , 0 );
	
	al_start_timer(timer);

	while( !sair ) {

		ALLEGRO_EVENT ev;
		
		al_wait_for_event( event_queue, &ev );

		if( ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE ) {
			sair = true;
		}
		else if( ev.type == ALLEGRO_EVENT_TIMER ) {


			// Realiza um tipo de snapshoot no estado das teclas
			keyboard->update();

			// Atualizamoa posicao do personagem de acordo com o sprite
			movex = movey = 0;

			if( keyboard->keyPressed( KeyCode::KEY_RIGHT ) ) {
				spr.setCurrentAnimation( "Direita" );
				movex = 1;
			}
			
			if( keyboard->keyPressed( KeyCode::KEY_LEFT ) ) {
				spr.setCurrentAnimation( "Esquerda" );
				movex = -1;
			}
			
			if( keyboard->keyPressed( KeyCode::KEY_UP ) ) {
				spr.setCurrentAnimation( "Costas" );
				movey = -1;
			}
			
			if( keyboard->keyPressed( KeyCode::KEY_DOWN ) ) {
				spr.setCurrentAnimation( "Frente" );
				movey = 1;
			}
			
			if( keyboard->keyRelease( KeyCode::KEY_ESCAPE ) ) {
				sair = true;
			}

			if( keyboard->keyTyped( KeyCode::KEY_SPACE ) ) {
				musica.play();
				texto.setText( "play" );
			}
			else if( keyboard->keyTyped( KeyCode::KEY_P ) ) {
				musica.pause();
				texto.setText( "pause" );
			}
			else if( keyboard->keyTyped( KeyCode::KEY_S ) ) {
				musica.stop();
				texto.setText( "stop" );
			}

			if( keyboard->keyTyped( KeyCode::KEY_M ) ) {
				sample.play();
				sample2.play();
			}

			if ( keyboard->keyTyped( KeyCode::KEY_V ) ) {
				l->setVisible( !l->isVisible() );
			}

			// Verificamos se podemos nos movimentar no eixo X
			if( l->checkCollision( spr, movex, 0, 2 ) ) {
				movex = 0;
			}

			if( l->checkCollision( spr, 0, movey, 2 ) ) {
				movey = 0;
			}
			
			//------------------------------------------
			
			if( spr.collidesWithPixel( &spr2 ) )
			{
				texto.setText( "Colisao" );
			}
			else{
				texto.setText("");
			}
			
			//------------------------------------------
			
			if( movex || movey ) {
				desloc.setCoordinates( movex, movey );
				spr.move( desloc );
				spr.nextFrame();
				//spr1.move( desloc );
				
			}

			redraw = true;
			
		}//if timer

		if( redraw && al_is_event_queue_empty( event_queue ) ) {

			redraw = false;

			// Desenhamos cada uma das camadas
			al_hold_bitmap_drawing( true );

			for( unsigned int i = 0; i < layerManager.size(); i++ ) {
				layerManager.at( i )->draw();
			}

			texto.drawText();

			al_hold_bitmap_drawing( false );

			// Atualizamos a tela
			video.refresh();

		}

		//cTime = fpsTimer.getTicks();



		//-------------------------------------------------------


		/*if( fpsTimer.getTicks() - cTime < div ) {
			TimeHandler::sleep( div - fpsTimer.getTicks() );
		}*/


	}//while*/
	
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);

	return 0;

}
