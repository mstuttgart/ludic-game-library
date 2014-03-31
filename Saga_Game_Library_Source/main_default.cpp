#include "video_manager.h"
#include "static_sprite.h"
#include "animated_sprite.h"
#include "keyboard_manager.h"
#include "mouse_manager.h"
#include "tile_map.h"
#include "color.h"
#include "time_handler.h"
#include "vector2_d.h"

using namespace sgl;
using namespace sgl::image;
using namespace sgl::font;
using namespace sgl::input;

using namespace std;

/* Constantes do sprite*/
const int FRAMES_POR_SEGUNDO = 60;

int main( int argc, char* argv[] ) {

	//---------------------------

	VideoManager* video = VideoManager::createVideoManager(
	                          640, 480, sgl::Display_Mode::WINDOWED );

	video->setWindowTitle( "Saga Game Library" );
	video->setWindowIcon( "Resource/icone.png" );

	//-----------------------------------------------

	// Inicializamos os dispositivos de entrada
	KeyboardManager* keyboard = KeyboardManager::Instance();
	MouseManager*    mouse    = MouseManager::Instance( video );

	//-----------------------------------------------

	// Criamos cada vetor para cada movimento. Cada movimento possui
	// seus respectivos indices nas imagens, entao cada vetor recebe esses indices
	vector<int> frente   {0,1,2,3};
	vector<int> esquerda {4,5,6,7};
	vector<int> direita  {8,9,10,11};
	vector<int> costas   {12,13,14,15};

	// Criamos as contantes para cada Animation. Elas funcionam com uma label
	// que indentifica as animacoes. NAO podemos ter DUAS ou mais animacoes
	// com o MESMO NUMERO/LABEL.
	int FRENTE   = 0;
	int ESQUERDA = 1;
	int DIREITA  = 2;
	int COSTAS   = 3;

	AnimatedSprite spr;

	// Adicionamos cada uma das animacoes
	spr.addAnimation( FRENTE, Animation::createAnimation( "Resource/sprite.png", frente, 4, 4 ) );
	spr.addAnimation( ESQUERDA, Animation::createAnimation( "Resource/sprite.png", esquerda, 4, 4 ) );
	spr.addAnimation( DIREITA, Animation::createAnimation( "Resource/sprite.png", direita, 4, 4 ) );
	spr.addAnimation( COSTAS, Animation::createAnimation( "Resource/sprite.png", costas, 4, 4 ) );

	// Ajustamos posicao do sprite
	//spr.setPosition( 200, 290 );
	spr.setPosition( Vector2D( 200.0f, 200.0f ) );

	// Colocamos o sprite como visible
	spr.setVisible( true );

	//-------------------------------------------

	TileMap* mapa = TileMap::createTileMap( "Resource/lev03_siberia/siberia.tmx" );

	//-------------------------------------------

	std::vector<Layer*> layerManager;

	layerManager.push_back( mapa->getLayer( "Fundo1" ) );
	layerManager.push_back( mapa->getLayer( "Fundo2" ) );
	layerManager.push_back( mapa->getLayer( "Piso1" ) );
	layerManager.push_back( &spr );
	layerManager.push_back( mapa->getLayer( "Piso2" ) );
	layerManager.push_back( mapa->getLayer( "Colisao" ) );

	TiledLayer* l = mapa->getLayer( "Colisao" );

	//-----------------------------------------

	int movex = 0;
	int movey = 0;

	//-----------------------------------------

	double div = 1.0/FRAMES_POR_SEGUNDO;
	bool sair = false;

	TimeHandler fpsTimer;

	//-----------------------------------------

	// Capturamos o tempo inicial
	fpsTimer.start();
	
	double cTime;

	while( !sair ) {
		
		cTime = fpsTimer.getTicks();

		// Desenhamos cada uma das camadas
		al_hold_bitmap_drawing( true );

		for( unsigned int i=0; i<layerManager.size(); i++ ) {
			layerManager.at( i )->draw();
		}

		al_hold_bitmap_drawing( false );

		// Atualizamos a tela
		video->refreshScreen();

		// Realiza um tipo de snapshoot no estado das teclas
		keyboard->update();
		mouse->update();

		// Atualizamoa posicao do personagem de acordo com o sprite
		movex = movey = 0;
		
		//--------------------------------------------------

		if( keyboard->keyPressed( KeyCode::KEY_RIGHT ) ) {
			spr.setCurrentAnimation( DIREITA );
			movex = 5;
		}

		if( keyboard->keyPressed( KeyCode::KEY_LEFT ) ) {
			spr.setCurrentAnimation( ESQUERDA );
			movex = -5;
		}

		if( keyboard->keyPressed( KeyCode::KEY_UP ) ) {
			spr.setCurrentAnimation( COSTAS );
			movey = -5;
		}

		if( keyboard->keyPressed( KeyCode::KEY_DOWN ) ) {
			spr.setCurrentAnimation( FRENTE );
			movey = 5;
		}

		if( keyboard->keyRelease( KeyCode::KEY_ESCAPE ) ) {
			sair = true;
		}

		if ( keyboard->keyTyped( KeyCode::KEY_V ) ) {
			l->setVisible( !l->isVisible() );
		}

		if( mouse->buttonPressed( 2 ) ) {
			cout << mouse->getButtonSize() << endl;
		}

		//-------------------------------------------------------

		// Verificamos se podemos nos movimentar no eixo X
		if( l->checkCollision( spr, movex, 0, 2 ) ) {
			movex = 0;
		}

		if( l->checkCollision( spr, 0, movey, 2 ) ) {
			movey = 0;
		}

		spr.move( Vector2D( movex , movey ) );
		
		

		if( movex || movey )
			spr.nextFrame();

		if( fpsTimer.getTicks() - cTime < div )
			TimeHandler::sleep( div - fpsTimer.getTicks() );

	}//while

	TileMap::destroyTileMap();

	return 0;

}
