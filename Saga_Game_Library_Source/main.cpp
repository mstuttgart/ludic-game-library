#include "VideoManager.h"
#include "Image.h"
#include "ResourceMap.h"

using namespace sgl;

using namespace sgl::image;

using namespace std;

int main( int argc, char* argv[] ) {

	std::cout << "Hello Eita!" << std::endl;

	//al_rest( 8.0 );

	VideoManager* video = VideoManager::createVideoManager( 640, 480, sgl::DISPLAY_MODE::WINDOWED );

	video->setWindowTitle( "teste" );

	video->setWindowIcon( "icone.png" );

	video->setBackgroundColor( 220, 0, 0 );

	Image* img;
	Image* img2;
	Image* img3;
	
	img  = Image::createImage( "icone.png" );	
	img2 = Image::createImage( "icone.png" );
	img3 = Image::createImage( "icone.png" );
	
	al_draw_bitmap( img2->getAllegroBitmap(), 0, 0, 0 );

	al_flip_display();

	al_rest( 2.0 );
	
	delete img;
	delete img2;
	delete img3;

	return 0;

}
