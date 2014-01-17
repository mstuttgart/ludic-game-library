#include "ImageResource.h"
#include "ResourceMap.h"

namespace sgl {

namespace image {

//-----------------------------------------------------------

ImageResource::ImageResource( const char* fileName, ALLEGRO_BITMAP* bitmap )
	: Resource( fileName, bitmap ) {}

//-----------------------------------------------------------

ImageResource::~ImageResource() {

	// destruimos o bitmap
	al_destroy_bitmap( ( ALLEGRO_BITMAP* ) getResorcePtr() );
}

//-----------------------------------------------------------
bool ImageResource::loadAllegroBitmap( ALLEGRO_BITMAP* bitmap, const char* fileName ) {

	try {

		// Carregamos o bitmap
		bitmap = al_load_bitmap( fileName );

		// Lancamos um excecao, caso ocorra
		if( !bitmap ) throw Exception::CREATE_BITMAP;

		// Montamos a mensagem do log em caso do carregamento ter sucesso.
		std::string str( "File " );
		str += fileName;
		str += " loaded successfully!";

		LogOutput::printInLogout( str.c_str() ); // Saida para log

	}
	catch( Exception::EXCEPTION& ex ) {
		std::cout << Exception::getError( ex ) << std::endl;
		LogOutput::printInLogout( Exception::getError( ex ) ); // Saida para log
		return false;
	}//catch

	return true;

}

//-----------------------------------------------------------

ImageResource* ImageResource::loadImageResource( const char* fileName ) {

	// Verificamos se o filename nao e NULL
	if( !fileName ) return NULL;

	// Criamos o bitmap que recebera o ALLEGRO_BITMAP
	ALLEGRO_BITMAP* bitmap = nullptr;

	// Caso retorne false, paramos o processo de carregamento
	if( !loadAllegroBitmap( bitmap, fileName ) ) return NULL;

	// Criamos o resource
	ImageResource* imgResource = new ImageResource( fileName, bitmap );

	// Incrementamos o numero de referências do resource em uma unidade
	imgResource->incReferenceAmount();

	// Pegamos uma instancia do ResourceMap
	ResourceMap* map = ResourceMap::getInstance();

	// Adicionamos o resource do mapa
	map->addResource( imgResource );

	return imgResource;

}

//-----------------------------------------------------------

void ImageResource::destroyImageResource( ImageResource* imgResource ) {

	// Verificamos se resource nao e NULL
	if( !imgResource ) return;

	// Decrementamos o número de referências do resource em uma unidade
	imgResource->decReferenceAmount();

	//Verificamos se o número de referencias e zero
	if( imgResource->getReferenceAmount() == 0 ) {

		// Pegamos uma instancia do ResourceMap
		ResourceMap* map = ResourceMap::getInstance();

		// Removemos o resource do mapa
		map->removeResource( imgResource->getResourceName() );

		// Deletamos o resource
		if( imgResource ) delete imgResource;

	}//if

}

//-----------------------------------------------------------

void ImageResource::draw(  int& x, int& y, int& mirror ) {
	al_draw_bitmap( (ALLEGRO_BITMAP*) getResorcePtr(), x, y, mirror );
}

//-----------------------------------------------------------
}
} /* namespace */
