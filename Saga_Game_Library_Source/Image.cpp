#include "Image.h"
#include "ResourceMap.h"

namespace sgl {

namespace image {

//-----------------------------------------------------------

Image::Image( Resource* resource ) {
	ptr_rsc = resource;
	bitmap = (ALLEGRO_BITMAP*) resource->getResorcePtr();
}

//-----------------------------------------------------------

Image::~Image() {

	/** Se for  a ultima instancia que usa o resource
	   nos o destruimos. */
	if( ptr_rsc->getReferenceAmount() == 1 )
		al_destroy_bitmap( ( ALLEGRO_BITMAP* ) ptr_rsc->getResorcePtr() );

	// Damos o comando para destruirmos o resource
	Resource::destroyResource( ptr_rsc );

}


//-----------------------------------------------------------

Image* Image::createImage( const char* fileName ) {

	// Verificamos se o filename nao e NULL
	if( !fileName ) return NULL;

	// Pegamos uma instancia do mapa
	ResourceMap* rscMap = ResourceMap::getInstance();

	// Ponteiro para allegro bitmap
	ALLEGRO_BITMAP* bitmap = nullptr;

	// Se ainda nao foi, rsc sera NULL
	if( !rscMap->isResourcePresent( fileName ) ) {

		try {

			// Carregamos o bitmap
			bitmap = al_load_bitmap( fileName );

			// Lancamos um excecao, caso ocorra
			if( !bitmap ) throw Exception::CREATE_BITMAP;

		}
		catch( Exception::EXCEPTION& ex ) {
			// Saida para log
			std::cout << Exception::getError( ex ) << std::endl;
			LogOutput::printInLogout( Exception::getError( ex ) );

			return NULL;
		}//catch

	}//if

	// Criamos o resource
	Resource* rsc = Resource::createResource( fileName, bitmap );

	// Retornamos a nova imagem
	return ( new Image( rsc ) );

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
	return bitmap;
}

//-----------------------------------------------------------

int Image::getHeight() {
	return al_get_bitmap_height( bitmap );
}

//-----------------------------------------------------------

int Image::getWidth() {
	return al_get_bitmap_width( bitmap );
}

//-----------------------------------------------------------
}
} /* namespace */
