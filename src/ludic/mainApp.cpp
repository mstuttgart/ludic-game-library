#include "video.hpp"
#include "scene_manager.hpp"
#include "my_scene.hpp"
#include "vector2_d.hpp"
#include "geometrics.hpp"
#include "time_handler.hpp"

using namespace sgl;
using namespace sgl::image;
using namespace sgl::font;
using namespace sgl::input;

using namespace std;

int main()
{

	//---------------------------
	ALLEGRO_BITMAP* v[5000];
	
	TimeHandler t;
	
	t.start();
	for( int i=0; i < 5000; i++ ){
		v[i] = al_load_bitmap("Resource/sprite.png");
		//v[i] = ImageResource::loadImageResource("Resource/sprite.png");
	}
	
	t.pause();
	cout << t.getTicks() << endl;
		
	al_rest( 10 );
	
	for( int i=0; i < 5000; i++ )
		al_destroy_bitmap(v[i]);

	/*Video video ( 450, 300 );

	video.setTitle ( "Saga Game Library" );
	video.setIcon ( "Resource/icone.png" );

	//-----------------------------------------------

	
	video.refresh();	
	
	al_rest( 10 );*/

	/*MyScene myScene( &video );

	SceneManager evManager( &myScene, &video, 15 );

	evManager.addDisplayListener( &myScene );
	evManager.addKeyListener( &myScene );

	evManager.initialize();
	evManager.execute();
	evManager.finalize();*/

	//-------------------------------------------------

	return 0;

}
