#include "image_resource.h"
#include "resource_map.h"

using namespace sgl::image;

//------------------------------------------------
ImageResource::ImageResource( const char* fileName, ALLEGRO_BITMAP* bitmap,  ImageResource* parentBitmap )
	: Resource( fileName, bitmap ) {
	this->parent = parentBitmap;

};

//------------------------------------------------

// Destruimos o ponteiro da sua propria maneira
ImageResource::~ImageResource() {

	// Avisamos ao ImageResource pai
	// que ele perdeu uma referencia
	if( parent )
		parent->decReferenceAmount();

	// Destruimos o subbitmap
	al_destroy_bitmap( getBitmap() );

}

//-----------------------------------------------

ImageResource* ImageResource::createImageResource( const char* fileName ) {

	if( !fileName ) return NULL;

	// Inciamos a string com a msg de carregamento
	std::string str( "File " );
	str += fileName;

	// Pegamos uma instancia do mapa
	ResourceMap* rscMap = ResourceMap::getInstance();

	// Verificamos se o recurso ja foi carregado
	ImageResource* rsc = ( ImageResource* ) rscMap->getResource( fileName );

	// Se ainda nao foi, rsc sera NULL
	if( !rsc ) {

		try {

			// Carregamos o bitmap
			ALLEGRO_BITMAP* bitmap = al_load_bitmap( fileName );

			// Lancamos um excecao, caso ocorra
			if( !bitmap ){
				sgl::Exception ex( "Error to load bitmap in ImageResource.");
				throw ex;
			}
			
			// Criamos um novo recurso
			rsc = new ImageResource( fileName, bitmap, nullptr );

			// Adicionamos o resource ao mapa
			rscMap->addResource( fileName, rsc );

			// Montamos a mensagem do log em caso do carregamento ter sucesso.
			str += " loaded successfully!";

		}//try
		catch( sgl::Exception ex ) {
			std::cout << ex.what() << std::endl;
			return NULL;
		}//catch

	}//if
	else {
		// Montamos a mensagem do log em caso do carregamento ter sucesso.
		str += " already exists!";
	}

	// Aumentamos o numero de referencias em uma unidade
	rsc->decReferenceAmount();

	// Imprimimos o resultado da criacao da imagem
	std::cout << str << std::endl;

	return rsc;

}//createImageResource

//-----------------------------------------------------------

ImageResource* ImageResource::getSubImageResource( ImageResource* rsc, int x, int y, int w, int h) {

	if( !rsc ) return NULL;

	// Criamos o subbitmap
	ALLEGRO_BITMAP* bitmap = rsc->getSubBitmap( x, y, w, h );

	// Criamos o resource
	ImageResource* img = new ImageResource( "isSubImageResource", bitmap, rsc );

	// Aumentamos a referencia em uma unidade
	img->incReferenceAmount();

	// O subImageResource nao leva o nome do pai
	return img;

}

//-----------------------------------------------------------

ALLEGRO_BITMAP* ImageResource::getBitmap() {
	return ( ALLEGRO_BITMAP* ) getResorcePtr();
}

//-----------------------------------------------------------

ALLEGRO_BITMAP* ImageResource::getSubBitmap( int x, int y, int w, int h ) {
	return al_create_sub_bitmap( getBitmap(), x, y, w, h );
}

//-----------------------------------------------------------

void ImageResource::setColorKey( unsigned char r, unsigned char g, unsigned char b ) {
	al_convert_mask_to_alpha( getBitmap(), al_map_rgb( r, g, b ) );
}

//----------------------------------------------------------

