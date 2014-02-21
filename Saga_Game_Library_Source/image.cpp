#include "image.h"
#include "resource_map.h"

using namespace sgl::image;
using namespace sgl;

//-----------------------------------------------------------

Image::Image( const char* fileName ) {

	// Verificamos se o filename nao e NULL
	if( fileName ) {

		// Criamos o resource
		ptr_rsc = ImageResource::createImageResource( fileName );

		// Setamos o bitmap. Isso e feito apenas por questoes de desempenho
		// para que nao tenhamos que chamar getBitmap() durante o draw()
		bitmapAux  = ptr_rsc->getBitmap();

		// Ajustamos a dimesao do retangulo de colisao
		cRect.setDimension( getX(), getY(), getWidth(), getHeight() );

	}//if

}

//-----------------------------------------------------------


Image::Image( ImageResource* resource ) {

	if( resource ) {
		// Inicializamos os atributos da imagem
		ptr_rsc    = resource;
		bitmapAux  = resource->getBitmap();

	}

}

//-----------------------------------------------------------

Image::~Image() {

	// Damos o comando para destruirmos o resource
	Resource::destroyResource( ptr_rsc );

}

//-----------------------------------------------------------

ALLEGRO_BITMAP* Image::getAllegroBitmap() {
	return bitmapAux;
}

//-----------------------------------------------------------

int Image::getHeight() {
	return al_get_bitmap_height( bitmapAux );
}

//-----------------------------------------------------------

int Image::getWidth() {
	return al_get_bitmap_width( bitmapAux );
}

//-----------------------------------------------------------

void Image::draw() {
	
	if( isVisible() )
		al_draw_bitmap( bitmapAux, getX(), getY(), getFlip() );
		
}

//-----------------------------------------------------------

const CollisionRect& Image::getCollisionRect() const {
	return cRect;
}

//----------------------------------------------------------
