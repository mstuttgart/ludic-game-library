#include "video_manager.h"
#include "image.h"
#include "resource_map.h"
#include "sprite.h"

using namespace sgl;

using namespace sgl::image;

using namespace std;

int main( int argc, char* argv[] ) {
	
	//---------------------------

	VideoManager* video = VideoManager::createVideoManager( 640, 480, sgl::DISPLAY_MODE::WINDOWED );

	video->setWindowTitle( "Saga Game Library" );

	video->setWindowIcon( "../Imagens/icone.png" );
	
	//----------------------------

	Image* img = Image::createImage( "../Imagens/icone.png" );
	img->setVisible( true );
	
	//---------------------------

	vector<int> frente;
	
	for( int i=0; i < 16; i++ ) frente.push_back( i );

	Sprite spr;

	spr.addAnimation( 0, Animation::createAnimation( "../Imagens/smurf_sprite.png", frente, 4, 4 ) );

	spr.setPosition( 100, 100 );
	
	spr.setVisible( true );
	
	//--------------------------

	bool sair = false;

	ALLEGRO_KEYBOARD_STATE kbdstate;
	
	while( !sair ) {

		spr.draw();
		
		img->draw();

		video->refreshScreen();

		// Realiza um tipo de snapshoot no estado das teclas
		al_get_keyboard_state(&kbdstate);

		if (al_key_down(&kbdstate, ALLEGRO_KEY_RIGHT)) spr.setFlip( FLIP::HV_FLIP );

		if (al_key_down(&kbdstate, ALLEGRO_KEY_LEFT)) spr.setFlip( FLIP::NONE );

		if (al_key_down(&kbdstate, ALLEGRO_KEY_ESCAPE)) sair = true;

		al_rest( 0.05 );

	}//while

	delete img;

	return 0; 

}
