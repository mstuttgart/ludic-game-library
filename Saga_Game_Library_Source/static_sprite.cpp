#include "static_sprite.h"
#include "resource_manager.h"

using namespace sgl::image;
using namespace sgl;

//-----------------------------------------------------------

StaticSprite::StaticSprite() : imgRsc(nullptr), bitmapAux(nullptr) {}

//-----------------------------------------------------------

StaticSprite::StaticSprite( String fileName ) :
	imgRsc(nullptr), bitmapAux(nullptr) {

	// Carregamos o sprite
	load( fileName );
}

//-----------------------------------------------------------


StaticSprite::StaticSprite( ImageResource* resource ) {

	if( resource ) {
		// Inicializamos os atributos da imagem
		imgRsc    = resource;
		bitmapAux = *resource;

		// Ajustamos a dimesao do retangulo de colisao
		rect.setXL( getX() );
		rect.setYU( getY() );
		rect.setW( getWidth()  );
		rect.setH( getHeight() );

	}//if

}


//-----------------------------------------------------------

bool StaticSprite::load( String fileName ) {

	bool rt = false;

	// Verificamos se o filename nao e NULL
	if( !fileName.empty() ) {

		// Criamos o resource
		imgRsc = ImageResource::createImageResource( fileName );

		// Setamos o bitmap. Isso e feito apenas por questoes de desempenho
		// para que nao tenhamos que chamar getBitmap() durante o draw()
		bitmapAux = *imgRsc;

		// Ajustamos a dimesao do retangulo de colisao
		rect.setXL( getX() );
		rect.setYU( getY() );
		rect.setW( getWidth()  );
		rect.setH( getHeight() );

		rt = true;

	}//if

	return rt;
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

	//al_draw_rectangle( rect.getXL(), rect.getYU(), rect.getXR(), rect.getYB(), al_map_rgb(255, 0, 255), 1.0 );
}

//----------------------------------------------------------

const ImageResource* StaticSprite::getImageResource() const {
	return imgRsc;
}

//----------------------------------------------------------
