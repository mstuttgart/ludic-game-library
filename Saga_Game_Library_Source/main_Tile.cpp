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
#include "time_handler.hpp"

using namespace sgl;
using namespace sgl::image;
using namespace sgl::font;
using namespace sgl::input;
using namespace sgl::core;
using namespace sgl::audio;

using namespace std;

/* Constantes do sprite*/
#define FPS 15

int main()
{

	//---------------------------

	Video video ( 800, 515 );

	video.setTitle ( "Saga Game Library" );
	video.setIcon ( "Resource/icone.png" );

	video.setBackgroundColor ( Color ( 145,184,60 ) );

	//-----------------------------------------------

	// Inicializamos os dispositivos de entrada
	KeyboardManager* keyboard = KeyboardManager::Instance();
	MouseManager* mouse       = MouseManager::Instance ( &video );

	//-----------------------------------------------

	AnimatedSprite spr;
	spr.load ( "Resource/mapas/personagem.tmx" );

	// Ajustamos posicao do sprite
	spr.setPosition ( Vector2D ( 150.0f, 100.0f ) );

	// Colocamos o sprite como visible
	spr.setVisible ( true );

	AnimatedSprite enemy;
	enemy.load ( "Resource/mapas/death.tmx" );
	enemy.setPosition ( Vector2D ( 550.0f, 300.0f ) );
	enemy.setVisible ( true );

	AnimatedSprite explosion;
	explosion.load ( "Resource/mapas/explosion.tmx" );
	explosion.setVisible ( false );

	AudioSample splExp;
	splExp.load ( "Resource/mapas/spl.wav" );
	splExp.setGain ( 0.4 );

	//------------------------------------------

	AudioStream musica;
	musica.load ( "Resource/audio/Artifact.ogg", 4, 1024 );

	//--------------------------------------- ----

	Font texto;
	texto.load ( "Resource/ALGER.TTF", 40 );
	texto.setColorFont ( Color ( 255, 255, 255 ) );

	//-------------------------------------------

	TimeHandler t;
	t.start();
	
	TMXTileMap mapa;
	mapa.load ( "Resource/rpg/mapa.tmx" );
	t.pause();
	cout << t.getTicks() << endl;

	/*if ( mapa.load ( "Resource/rpg/mapa.tmx" ) )
		cout << "Carregou mapa com sucesso" << endl;*/

	mapa.setScreenDimension ( video.getWidth(), video.getHeight() );

	//-------------------------------------------

	std::vector<Layer*> layerManager;

	layerManager.push_back ( mapa.getLayer ( "Piso" ) );
	layerManager.push_back ( &spr );
	layerManager.push_back ( &enemy );
	layerManager.push_back ( &explosion );
	layerManager.push_back ( mapa.getLayer ( "Objetos" ) );
	layerManager.push_back ( mapa.getLayer ( "Arvores" ) );
	layerManager.push_back ( mapa.getLayer ( "Colisao" ) );

	TiledLayer* l = mapa.getLayer ( "Colisao" );

	//-----------------------------------------

	int movex = 0;
	int movey = 0;

	int x = 0, j = 0, colFlag = 0;

	int varCtr = 0;

	BoundingBox bb;

	//-----------------------------------------

	double div = 1.0 / FPS;
	bool sair  = false;

	TimeHandler fpsTimer;

	//-----------------------------------------

	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_TIMER *timer             = al_create_timer ( div );

	al_register_event_source ( event_queue, al_get_display_event_source ( video ) );
	al_register_event_source ( event_queue, al_get_timer_event_source ( timer ) );

	bool redraw = false;

	//double cTime;
	Vector2D desloc ( 0 , 0 );
	Vector2D desloc_enemy ( 0,0 );

	al_start_timer ( timer );

	while ( !sair )
	{

		ALLEGRO_EVENT ev;

		al_wait_for_event ( event_queue, &ev );

		if ( ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE )
		{
			sair = true;
		}
		else if ( ev.type == ALLEGRO_EVENT_TIMER )
		{

			// Realiza um tipo de snapshoot no estado das teclas
			keyboard->update();
			mouse->update();

			// Atualizamoa posicao do personagem de acordo com o sprite
			movex   = 0;
			movey   = 0;
			varCtr +=1;

			if ( keyboard->keyPressed ( KeyCode::KEY_RIGHT ) )
			{
				spr.setCurrentAnimation ( "Direita" );
				movex = 5;
			}

			if ( keyboard->keyPressed ( KeyCode::KEY_LEFT ) )
			{
				spr.setCurrentAnimation ( "Esquerda" );
				movex = -5;
			}

			if ( keyboard->keyPressed ( KeyCode::KEY_UP ) )
			{
				spr.setCurrentAnimation ( "Costas" );
				movey = -5;
			}

			if ( keyboard->keyPressed ( KeyCode::KEY_DOWN ) )
			{
				spr.setCurrentAnimation ( "Frente" );
				movey = 5;
			}

			if ( keyboard->keyRelease ( KeyCode::KEY_ESCAPE ) )
			{
				sair = true;
			}

			if ( keyboard->keyTyped ( KeyCode::KEY_SPACE ) )
			{
				musica.play();
				texto.setText ( "play" );
			}
			else if ( keyboard->keyTyped ( KeyCode::KEY_P ) )
			{
				musica.pause();
				texto.setText ( "pause" );
			}
			else if ( keyboard->keyTyped ( KeyCode::KEY_S ) )
			{
				musica.stop();
				texto.setText ( "stop" );
			}

			if ( keyboard->keyTyped ( KeyCode::KEY_V ) )
			{
				l->setVisible ( !l->isVisible() );
			}


			if ( varCtr < 30 )
			{
				enemy.setCurrentAnimation ( "Esquerda" );
				x = -5;
			}
			else
			{
				enemy.setCurrentAnimation ( "Direita" );
				x = +5;

				if ( varCtr > 60 )
					varCtr = 0;
			}

			desloc_enemy.setCoordinates ( x,0 );
			enemy.move ( desloc_enemy );
			enemy.nextFrame();

			if ( ( colFlag > 0 ) && ( colFlag < 9 ) )
			{
				explosion.nextFrame();
				colFlag+=1;
			}
			else if ( colFlag == 9 )
			{
				explosion.setVisible ( false );
				colFlag = 0;
			}

			if ( spr.collidesWith ( &enemy ) )
			{

				texto.setText ( "Game Over" );
				float xTexto = video.getWidth() * 0.5  - texto.getTextWidth() * 0.5;
				float yTexto = video.getHeight() * 0.5 - texto.getLineHeight() * 0.5;
				texto.setPosition ( Vector2D ( xTexto, yTexto ) );

				Vector2D v = spr.getPosition();
				v.setCoordinates ( v.getX() - 32, v.getY() - 48 );

				explosion.setPosition ( v );
				explosion.setVisible ( true );

				splExp.play();
				musica.pause();

				colFlag = 1;

				spr.setPosition ( Vector2D ( -1.0f, -1.0f ) );
				spr.setVisible ( false );

			}//if


			if ( mouse->buttonPressed ( 1 ) )
			{

				Vector2D v1 = mouse->getPosition();
				bb = enemy.getBoundingBox();
				BoundingBox teste ( v1,0,0 );

				if ( bb.checkCollision ( teste ) )
				{
					Vector2D v = enemy.getPosition();
					v.setCoordinates ( v.getX() - 32, v.getY() - 48 );

					explosion.setPosition ( v );
					explosion.setVisible ( true );

					colFlag = 1;

					if ( j == 0 )
						splExp.play();

					explosion.nextFrame();

					enemy.setPosition ( Vector2D ( -100.0f, -100.0f ) );
					enemy.setVisible ( false );

				}//if
			}//if

			// Verificamos se podemos nos movimentar no eixo X
			if ( l->checkCollision ( spr, movex, 0, 2 ) )
			{
				movex = 0;
			}

			if ( l->checkCollision ( spr, 0, movey, 2 ) )
			{
				movey = 0;
			}

			if ( movex || movey )
			{
				desloc.setCoordinates ( movex, movey );
				spr.move ( desloc );
				spr.nextFrame();
			}

			redraw = true;

		}//if timer

		if ( redraw && al_is_event_queue_empty ( event_queue ) )
		{

			redraw = false;

			// Desenhamos cada uma das camadas
			al_hold_bitmap_drawing ( true );

			for ( unsigned int i = 0; i < layerManager.size(); i++ )
			{
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
