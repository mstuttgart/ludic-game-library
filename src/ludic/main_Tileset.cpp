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
#include "display_event.hpp"
#include "display_listener.hpp"
#include "bouding_box.hpp"

using namespace sgl;
using namespace sgl::image;
using namespace sgl::font;
using namespace sgl::input;
using namespace sgl::core;
using namespace sgl::audio;
using namespace sgl::event;

using namespace std;

/* Constantes do sprite*/
#define FPS 10

int main()
{

	//---------------------------

	Video video ( 650, 515 );

	video.setTitle ( "Saga Game Library" );

	video.setBackgroundColor ( Color ( 145,184,60 ) );

	//-----------------------------------------------

	// Inicializamos os dispositivos de entrada
	KeyboardManager* keyboard = KeyboardManager::Instance();
	MouseManager* mouse       = MouseManager::Instance ( &video );

	//-----------------------------------------------

	AnimatedSprite spr;
	spr.load ( "Resource/mapas/personagem.tmx" );
	spr.setPosition ( Vector2D ( 100.0f, 100.0f ) );
	spr.setVisible ( true );

	AnimatedSprite enemy;
	enemy.load ( "Resource/mapas/enemy.tmx" );
	enemy.setPosition ( Vector2D ( 350.0f, 150.0f ) );
	enemy.setVisible ( true );

	AnimatedSprite explosion;
	explosion.load ( "Resource/mapas/explosion.tmx" );
	explosion.setCurrentAnimation ( "exp" );
	explosion.setVisible ( false );

	AudioSample splExp;
	splExp.load ( "Resource/mapas/spl.wav" );
	splExp.setGain ( 0.4 );


	//-------------------------------------------

	Font texto;
	texto.load ( "Resource/mapas/ALGER.TTF", 40 );
	texto.setColorFont ( Color ( 255, 255, 255 ) );

	//-------------------------------------------

	TMXTileMap mapa;

	if ( mapa.load ( "Resource/mapas/mapatesteanim.tmx" ) )
		cout << "Carregou mapa com sucesso" << endl;

	mapa.setScreenDimension ( video.getWidth(), video.getHeight() );

	//-------------------------------------------

	std::vector<Layer*> layerManager;

	layerManager.push_back ( mapa.getLayer ( "Piso" ) );
	layerManager.push_back ( &spr );
	layerManager.push_back ( &enemy );
	layerManager.push_back ( &explosion );



	int movex = 0;
	int movey = 0;
	int x = 0;
	int i=0,j=0;

	int varCtr = 0;
	BoundingBox bb;

	//-----------------------------------------

	double div = 1.0 / FPS;
	bool sair  = false;

	TimeHandler fpsTimer;

	//========================================================================

	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_TIMER *timer             = al_create_timer ( div );

	al_register_event_source ( event_queue, al_get_display_event_source ( video ) );
	al_register_event_source ( event_queue, al_get_timer_event_source ( timer ) );

	bool redraw = false;

	Vector2D desloc ( 0 , 0 );
	Vector2D desloc_enemy ( 0,0 );

	al_start_timer ( timer );

	while ( !sair ) {

		ALLEGRO_EVENT ev;

		al_wait_for_event ( event_queue, &ev );

		if ( ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE ) {

			sair = true;
		}
		else if ( ev.type == ALLEGRO_EVENT_TIMER ) {


			// Realiza um tipo de snapshoot no estado das teclas
			varCtr +=1;
			keyboard->update();
			mouse->update();


			if ( keyboard->keyRelease ( KeyCode::KEY_ESCAPE ) ) {
				sair = true;
			}

			movex = movey = 0;

			if ( keyboard->keyPressed ( KeyCode::KEY_RIGHT ) ) {
				spr.setCurrentAnimation ( "Direita" );
				movex = 5;
			}

			if ( keyboard->keyPressed ( KeyCode::KEY_LEFT ) ) {
				spr.setCurrentAnimation ( "Esquerda" );
				movex = -5;
			}

			if ( keyboard->keyPressed ( KeyCode::KEY_UP ) ) {
				spr.setCurrentAnimation ( "Costas" );
				movey = -5;
			}

			if ( keyboard->keyPressed ( KeyCode::KEY_DOWN ) ) {
				spr.setCurrentAnimation ( "Frente" );
				movey = 5;
			}

			if ( keyboard->keyRelease ( KeyCode::KEY_ESCAPE ) ) {
				sair = true;
			}

// =======================================================
			if ( varCtr < 50 ) {
				enemy.setCurrentAnimation ( "Esquerda" );
				x = -5;
			}
			else {
				enemy.setCurrentAnimation ( "Direita" );
				x = +5;

				if ( varCtr > 100 ) varCtr = 0;
			}

			desloc_enemy.setCoordinates ( x,0 );
			enemy.move ( desloc_enemy );
			enemy.nextFrame();



			if ( spr.collidesWith ( &enemy ) ) {
				texto.setText ( "Game Over" );
				Vector2D v = spr.getPosition();
				v.setCoordinates ( v.getX() - 32, v.getY() - 48 );

				explosion.setPosition ( v );
				explosion.setVisible ( true );

				if ( i<9 ) {
					if ( i==0 ) splExp.play();

					explosion.nextFrame();

				}
				else {
					explosion.setVisible ( false );
					spr.setPosition ( Vector2D ( -1.0f, -1.0f ) );

				}

				i++;
				spr.setVisible ( false );


			}


			if ( mouse->buttonPressed ( 1 ) ) {

				Vector2D v1 = mouse->getPosition();
				bb = enemy.getBoundingBox();
				BoundingBox teste ( v1,0,0 );

				if ( bb.checkCollision ( teste ) ) {
					Vector2D v = enemy.getPosition();
					v.setCoordinates ( v.getX() - 32, v.getY() - 48 );

					explosion.setPosition ( v );
					explosion.setVisible ( true );

					if ( j<9 ) {
						if ( j==0 ) splExp.play();

						explosion.nextFrame();

					}
					else {
						explosion.setVisible ( false );
						enemy.setPosition ( Vector2D ( -1.0f, -1.0f ) );

					}

					enemy.setPosition ( Vector2D ( -1.0f, -1.0f ) );
					enemy.setVisible ( false );
					j++;

				}


			}

//===============================================================



			if ( movex || movey ) {
				desloc.setCoordinates ( movex, movey );
				spr.move ( desloc );
				spr.nextFrame();
			}


			redraw = true;

		}//if timer

		if ( redraw && al_is_event_queue_empty ( event_queue ) ) {

			redraw = false;

			// Desenhamos cada uma das camadas
			al_hold_bitmap_drawing ( true );

			for ( unsigned int i = 0; i < layerManager.size(); i++ ) {
				layerManager.at ( i )->draw();
			}

			texto.drawText();

			al_hold_bitmap_drawing ( false );

			// Atualizamos a tela
			video.refresh();

		}



	}//while

	al_destroy_event_queue ( event_queue );
	al_destroy_timer ( timer );

	return 0;

}
