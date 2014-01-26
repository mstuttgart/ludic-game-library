#include "image.h"
#include "resource_map.h"

namespace sgl {

namespace image {

//-----------------------------------------------------------

Image::Image( ImageResource* resource ) {
	ptr_rsc    = resource;
	bitmapAux  = resource->getBitmap();
}

//-----------------------------------------------------------

Image::~Image() {

	// Damos o comando para destruirmos o resource
	Resource::destroyResource( ptr_rsc );

}

//-----------------------------------------------------------

Image* Image::createImage( const char* fileName ) {

	// Verificamos se o filename nao e NULL
	if( !fileName ) return NULL;

	// Criamos o resource
	ImageResource* rsc = ImageResource::createImageResource( fileName );

	// Retornamos a nova imagem
	return ( new Image( rsc ) );

}


//-----------------------------------------------------------

Image* Image::createImage( ImageResource* imgResource ) {

	return imgResource == NULL ? NULL : new Image( imgResource );
}

//-----------------------------------------------------------

Image* Image::createImage( Image* img, int x, int y, int width, int height ) {

	/*// Verificamos se o filename nao e NULL
	if( !img ) return NULL;

	// Criamos o bitmap que recebera o ALLEGRO_BITMAP
	ALLEGRO_BITMAP* bitmap = al_create_sub_bitmap( img->getAllegroBitmap(), x, y, width, height );

	// Criamos o resource
	Resource* rsc = Resource::createResource( fileName, bitmap );

	// Caso retorne false, paramos o processo de carregamento
	if( !bitmap ) return NULL;

	Image* img2 = new Image( img->getResorce() );*/

	return nullptr;

}

//-----------------------------------------------------------

Image* Image::createImage( int width, int height ) {
	return NULL;
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

}
} /* namespace */
