#include "image_resource.h"
#include "resource_manager.h"

using namespace sgl::image;

//------------------------------------------------
ImageResource::ImageResource( const String& fileName, ALLEGRO_BITMAP* bitmap )
	: Resource( fileName, bitmap ) { }

//------------------------------------------------

// Destruimos o ponteiro da sua propria maneira
ImageResource::~ImageResource() {

	// Destruimos o subbitmap
	if( getBitmap() )
		al_destroy_bitmap( getBitmap() );

}

//-------------------------------------------------------------

ImageResource* ImageResource::createImageResource( const String& label,
													int width, int height ) {

	// Inciamos a string com a msg de carregamento
	String str( "ImageResource with label " + label );

	// Pegamos uma instancia do mapa
	ResourceManager* rscMap = ResourceManager::Instance();

	// Verificamos se o recurso ja foi carregado
	ImageResource* rsc =
	    static_cast<ImageResource*> ( rscMap->getResource( label ) ) ;

	// Se for NULL devemos alocar um novo ImageResource e inserir no mapa
	if( !rsc ) {

		// Carregamos o bitmap
		ALLEGRO_BITMAP* bitmap = al_create_bitmap( width, height );

		if( !bitmap ) {
			throw sgl::Exception( "Error to create ImageResource: " + label );
			return nullptr;
		}

		// Criamos um novo recurso
		rsc = new ImageResource( label, bitmap );

		// Adicionamos o resource ao mapa
		rscMap->addResource( label, rsc );

		str += " created successfully!";

	}
	else {
		str += " already exists!";
	}

	// Imprimimos o resultado da criacao da imagem
	std::cout << str << std::endl;

	return rsc;

}//createImageResource

//-------------------------------------------------------------

ImageResource* ImageResource::loadImageResource( const String& fileName ) {

	// Inciamos a string com a msg de carregamento
	String str( "File " + fileName );

	// Pegamos uma instancia do mapa
	ResourceManager* rscMap = ResourceManager::Instance();

	// Verificamos se o recurso ja foi carregado
	ImageResource* rsc = static_cast<ImageResource*> ( rscMap->getResource( fileName ) ) ;

	// Se for NULL devemos alocar um novo ImageResource e inserir no mapa
	if( !rsc ) {

		// Carregamos o bitmap
		ALLEGRO_BITMAP* bitmap = al_load_bitmap( fileName.c_str() );

		if( !bitmap ) {
			throw sgl::Exception( "ERROR: Error to load ImageResource: " + fileName );
			return nullptr;
		}

		// Criamos um novo recurso
		rsc = new ImageResource( fileName, bitmap );

		// Adicionamos o resource ao mapa
		rscMap->addResource( fileName, rsc );

		str += " loaded successfully!";

	}
	else {
		str += " already exists!";
	}

	// Imprimimos o resultado da criacao da imagem
	std::cout << str << std::endl;

	return rsc;

}//createImageResource


//-----------------------------------------------------------

ImageResource* ImageResource::getSubImageResource( int x, int y, int w, int h ) {

	// Criamos o subbitmap
	ALLEGRO_BITMAP* bitmap = al_create_sub_bitmap( *this, x, y, w, h );

	// Criamos o resource
	ImageResource* img = new ImageResource( "isSubBitmap", bitmap );

	// O subImageResource nao leva o nome do pai
	return img;

}

//-----------------------------------------------------------

ALLEGRO_BITMAP* ImageResource::getBitmap() {
	return static_cast<ALLEGRO_BITMAP*>( getResourcePtr() ) ;
}

//-----------------------------------------------------------

void ImageResource::setAsTarger() {
	al_set_target_bitmap( getBitmap() );
}

//-------------------------------------------------------

void ImageResource::setColorKey( Color colorkey ) {
	al_convert_mask_to_alpha( getBitmap(), colorkey );
}

//----------------------------------------------------------

ImageResource::operator ALLEGRO_BITMAP*() {
	return getBitmap();
}

//-----------------------------------------------------------
