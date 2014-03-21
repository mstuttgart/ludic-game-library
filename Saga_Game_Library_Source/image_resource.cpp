#include "image_resource.h"
#include "resource_manager.h"

using namespace sgl::image;

//------------------------------------------------
ImageResource::ImageResource( const char* fileName, ALLEGRO_BITMAP* bitmap,
                              ImageResource* parentBitmap )
	: Resource( fileName, bitmap ) { };

//------------------------------------------------

// Destruimos o ponteiro da sua propria maneira
ImageResource::~ImageResource() {

	// Destruimos o subbitmap
	al_destroy_bitmap( getBitmap() );
}

//-----------------------------------------------

ImageResource* ImageResource::createImageResource( const char* fileName ) {

	// Verificamos se o filename nao e NULL
	if( !fileName ) {
		std::cout << "Invalid file name " << fileName << std::endl;
		return NULL;
	}

	// Inciamos a string com a msg de carregamento
	std::string str( "File " );

	str += fileName;

	// Pegamos uma instancia do mapa
	ResourceManager* rscMap = ResourceManager::getInstance();

	// Verificamos se o recurso ja foi carregado
	ImageResource* rsc = ( ImageResource* ) rscMap->getResource( fileName );

	// Se nao existe Resource com o nome solicitado
	// o retorno sera NULL
	if( !rsc ) {

		try {

			// Carregamos o bitmap
			ALLEGRO_BITMAP* bitmap = al_load_bitmap( fileName );

			// Lancamos um excecao, caso ocorra
			if( !bitmap ) {
				sgl::Exception ex( "Error to load bitmap in ImageResource." );
				throw ex;
			}

			// Criamos um novo recurso
			rsc = new ImageResource( fileName, bitmap, nullptr );

			// Adicionamos o resource ao mapa
			rscMap->addResource( fileName, rsc );

			// Montamos a mensagem do log em caso do carregamento ter sucesso.
			str += " loaded successfully!";

		}//try
		catch( sgl::Exception& ex ) {
			std::cout << ex.what() << std::endl;
			return NULL;
		}//catch

	}//if
	else {
		// Montamos a mensagem do log em caso do carregamento ter sucesso.
		str += " already exists!";
	}

	// Imprimimos o resultado da criacao da imagem
	std::cout << str << std::endl;

	return rsc;

}//createImageResource


//-----------------------------------------------------------

ImageResource* ImageResource::getSubImageResource( ImageResource* rsc, int x, int y, int w, int h ) {

	if( !rsc ) return NULL;

	// Criamos o subbitmap
	ALLEGRO_BITMAP* bitmap = al_create_sub_bitmap( *rsc, x, y, w, h );

	// Criamos o resource
	ImageResource* img = new ImageResource( "isSubImageResource", bitmap, rsc );

	// O subImageResource nao leva o nome do pai
	return img;

}

//-----------------------------------------------------------

ALLEGRO_BITMAP* ImageResource::getBitmap() {
	return ( ALLEGRO_BITMAP* ) getResorcePtr();
}

//-----------------------------------------------------------

ImageResource::operator ALLEGRO_BITMAP*() {
	return getBitmap();
}

//-----------------------------------------------------------

void ImageResource::setColorKey( ALLEGRO_COLOR colorkey ) {
	al_convert_mask_to_alpha( getBitmap(), colorkey );
}

//----------------------------------------------------------
