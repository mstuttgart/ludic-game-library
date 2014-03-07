#include "static_sprite.h"
#include "resource_map.h"

using namespace sgl::image;
using namespace sgl;

//-----------------------------------------------------------

StaticSprite::StaticSprite( const char* fileName ) {
	
	// Carregamos o sprite
	load( fileName );	
}

//-----------------------------------------------------------


StaticSprite::StaticSprite( ImageResource* resource ) {

	if( resource ) {
		// Inicializamos os atributos da imagem
		ptr_rsc    = resource;
		bitmapAux  = resource->getBitmap();
		
		// Ajustamos a dimesao do retangulo de colisao
		rect.setXi( getX() );
		rect.setYi( getY() );
		rect.setW( getWidth()  );
		rect.setH( getHeight() );
		
	}//if

}

//-----------------------------------------------------------

StaticSprite::~StaticSprite() {

	// Damos o comando para destruirmos o resource
	Resource::destroyResource( ptr_rsc );

}

//-----------------------------------------------------------

bool StaticSprite::load(const char* fileName) {
	
	bool rt = false;
	
	// Verificamos se o filename nao e NULL
	if( fileName ) {

		// Criamos o resource
		ptr_rsc = ImageResource::createImageResource( fileName );

		// Setamos o bitmap. Isso e feito apenas por questoes de desempenho
		// para que nao tenhamos que chamar getBitmap() durante o draw()
		bitmapAux = ptr_rsc->getBitmap();
		
		// Ajustamos a dimesao do retangulo de colisao
		rect.setXi( getX() );
		rect.setYi( getY() );
		rect.setW( getWidth()  );
		rect.setH( getHeight() );
		
		rt = true;

	}//if
	
	return rt;
}

//-----------------------------------------------------------

ALLEGRO_BITMAP* StaticSprite::getAllegroBitmap() {
	return bitmapAux;
}

//-----------------------------------------------------------

int StaticSprite::getHeight() {
	return al_get_bitmap_height( bitmapAux );
}

//-----------------------------------------------------------

int StaticSprite::getWidth() {
	return al_get_bitmap_width( bitmapAux );
}

//-----------------------------------------------------------

void StaticSprite::draw() {

	if( isVisible() )
		al_draw_bitmap( bitmapAux, getX(), getY(), getFlip() );
		/*al_draw_scaled_rotated_bitmap( bitmapAux, getRefX(), getRefY(), 
		getX(), getY(), getScaleX(), getScaleY(), getAngle(), getFlip());*/
		
	al_draw_rectangle( rect.getXi(), rect.getYi(), rect.getXf(), rect.getYf(), al_map_rgb(255, 0, 255), 1.0 );
}

//----------------------------------------------------------
