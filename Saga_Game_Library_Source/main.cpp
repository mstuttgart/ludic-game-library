#include "video_manager.h"
#include "image.h"
#include "resource_map.h"
#include "sprite.h"

using namespace sgl;

using namespace sgl::image;

using namespace std;

int main( int argc, char* argv[] ) {

	VideoManager* video = VideoManager::createVideoManager( 640, 480, sgl::DISPLAY_MODE::WINDOWED );

	video->setWindowTitle( "teste" );

	video->setWindowIcon( "icone.png" );

	Image* img;
	Image* img2;
	Image* img3;

	img  = Image::createImage( "icone.png" );
	img2 = Image::createImage( "icone.png" );
	img3 = Image::createImage( "icone.png" );

	//al_draw_bitmap( img2->getAllegroBitmap(), 0, 0, 0 );

	vector<int> frente;
	/*vector<int> esquerda {4,5,6,7};
	vector<int> direita {8,9,10,11};
	vector<int> tras {12,13,14,15};*/
	
	for( int i=0; i < 16; i++ ) frente.push_back( i );

	Sprite spr;

	spr.addAnimation( 0, Animation::createAnimation( "smurf_sprite.png", frente, 4, 4 ) );
	/*spr.addAnimation( 1, Animation::createAnimation( ch, esquerda, 4, 4 ) );
	spr.addAnimation( 2, Animation::createAnimation( ch, direita, 4, 4 ) );
	spr.addAnimation( 3, Animation::createAnimation( ch, tras, 4, 4 ) );*/

	spr.setPosition( 100, 100 );

	bool sair = false;

	ALLEGRO_KEYBOARD_STATE kbdstate;

	//int anim = 3;

	while( !sair ) {

		spr.draw();
		
		img3->draw();

		video->refreshScreen();

		// Realiza uma tipo de snapshoot no estado das teclas
		al_get_keyboard_state(&kbdstate);

		if (al_key_down(&kbdstate, ALLEGRO_KEY_RIGHT)) spr.setFlip( FLIP::HV_FLIP );

		if (al_key_down(&kbdstate, ALLEGRO_KEY_LEFT)) spr.setFlip( FLIP::RESET );

		/*if (al_key_down(&kbdstate, ALLEGRO_KEY_UP)) anim = 0;

		if (al_key_down(&kbdstate, ALLEGRO_KEY_DOWN)) anim = 3;*/

		if (al_key_down(&kbdstate, ALLEGRO_KEY_ESCAPE)) sair = true;

		al_rest( 0.05 );

	}//while

	//al_rest( 2.0 );
	delete img;
	delete img2;
	delete img3;

	return 0; 

}
