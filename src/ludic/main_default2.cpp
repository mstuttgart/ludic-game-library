#include "video.hpp"
#include "font.hpp"
#include "color.hpp"

using namespace sgl;
using namespace sgl::font;
using namespace std;

int main() {

	//---------------------------

	Video video( 640, 480 );
	video.setTitle( "Saga Game Library" );

	//-------------------------------------------

	Font texto;
	texto.load( "Resource/Samurai.ttf", 45 );
	texto.setColorFont( Color(255,255,255) );
	texto.setText( "Minions" );
	texto.drawText();

	//-------------------------------------------
	
	// Atualizamos a tela
	video.refresh();
	
	al_rest(4.0);
	 
	return 0;

}
  
