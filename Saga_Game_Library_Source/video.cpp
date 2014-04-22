#include "video.h"
#include "image_resource.h"

#include <allegro5/allegro_opengl.h>

using namespace sgl;
using namespace std;

//-----------------------------------------------------

Video::Video() : backGroundColor( Color ( 0, 0, 0 ) ) {

	// Recebera as dimensoes da resoulucao minima
	int w, h;

	// Recebemos a resoulucao 0 ou minima
	Video::getResolution(
	    Video::sizeResolutions() - 1, w, h );

	// Incializamos o display
	int aux = ALLEGRO_WINDOWED;

#if UNIX
	aux = aux | ALLEGRO_OPENGL;
#endif

	// Setamos as flags do display
	al_set_new_display_flags( aux );

	// Criamos o display
	display = al_create_display( w, h );

	// Setamos o allegro para usar bitmao na memoria de video.
	// Isso permite que a mesma utiliza aceleracao por hardware
	al_set_new_bitmap_flags( ALLEGRO_VIDEO_BITMAP );

	if( !display )
		throw sgl::Exception( "* Failed to initialize ALLEGRO_DISPLAY." );


}

//-----------------------------------------------------

Video::Video( unsigned int width, unsigned int height, DisplayMode mode ) :
									backGroundColor( Color ( 0, 0, 0 ) ) {

	// Incializamos o display
	int aux = ( int ) mode;

#if UNIX
	aux = aux | ALLEGRO_OPENGL;
#endif

	// Setamos as flags do display
	al_set_new_display_flags( aux );

	// Criamos o display
	display = al_create_display( width, height );

	// Setamos o allegro para usar bitmao na memoria de video.
	// Isso permite que a mesma utiliza aceleracao por hardware
	al_set_new_bitmap_flags( ALLEGRO_VIDEO_BITMAP );

	if( !display )
		throw sgl::Exception( "* Failed to initialize ALLEGRO_DISPLAY." );

}

//---------------------------------------

Video::~Video() {
	// Destruimos o display da Allegro
	if( display )
		al_destroy_display ( display );
}

//---------------------------------------

void Video::disableScreenSaver ( bool disable ) {
	al_inhibit_screensaver( disable );
}

//---------------------------------------

Video::operator ALLEGRO_DISPLAY * () {
	return display;
}

//---------------------------------------

int Video::getHeight() const {
	return al_get_display_height ( display );
}

//---------------------------------------

int Video::getWidth() const {
	return al_get_display_width ( display );
}

//---------------------------------------

void Video::setBackgroundColor ( const Color& color ) {
	backGroundColor = color;
}

//---------------------------------------

void Video::setFitToScreen ( bool fit ) {
	al_set_display_flag ( display, ALLEGRO_FULLSCREEN_WINDOW, fit );
}

//---------------------------------------

void Video::setIcon( const String& fileName ) {

	// Criamos o image resource
	image::ImageResource* img;

	// Carregamos o arquivo de imagem
	img = image::ImageResource::createImageResource( fileName.c_str() );

	// Setamos a imagem do display
	if( img )
		al_set_display_icon( display, *img );

}

//---------------------------------------

void Video::setPosition ( int pos_x, int pos_y ) {
	al_set_window_position ( display, pos_x, pos_y );
}

//---------------------------------------

Vector2D Video::getPosition () {
	
	// Variaveis auxiliar
	int x, y;

	// Pegamos a posicao do display
	al_get_window_position ( display, &x, &y );

	// Retornamos o vetor com a posicao
	return Vector2D( x, y );
}

//---------------------------------------

void Video::setTitle ( const String& title ) {
	al_set_window_title ( display, title.c_str() );
}

//---------------------------------------

void Video::refresh() {
	
	// Atualizamos a tela
	al_flip_display();

	// Limpamos o backbuffer
	al_clear_to_color( backGroundColor );
}

//---------------------------------------

void Video::refreshRegion ( const Vector2D& xy, int width, int height ) {
	
	// Atualiza apenas uma região
	al_update_display_region ( xy.getX(), xy.getY(), width, height );
	
	// Limpamos o backbuffer
	al_clear_to_color( backGroundColor );
	
}

//-------------------------------------------

int Video::sizeResolutions() {
	return al_get_num_display_modes();
}

//-------------------------------------------

void Video::getResolution( unsigned int index, int& width, int& height ) {

	if( index >= ( unsigned int ) al_get_num_display_modes() ) {

		String str( "Invalid value of index in method getResolution()." );
		std::cout << str << std::endl;

		return;
	}

	ALLEGRO_DISPLAY_MODE disp_data;

	//Capturamos as informacoes da tela de acordo com a resolucao
	// escolhida por index
	al_get_display_mode( index, &disp_data );

	width  = disp_data.width;
	height = disp_data.height;

}

//------------------------------------------------------

void Video::setAsTarger() {
	// Tiramos o display de foco para que possamos deleta-lo
	al_set_target_backbuffer( display );
}

//-------------------------------------------------------
