#include "ImageResource.h"
#include "ResourceMap.h"

namespace sgl {

namespace image {

//------------------------------------------------
ImageResource::ImageResource( const char* fileName, ALLEGRO_BITMAP* bitmap )
	: Resource( fileName, bitmap ) {};

//------------------------------------------------

// Destruimos o ponteiro da sua propria maneira
ImageResource::~ImageResource() {
	al_destroy_bitmap( ( ALLEGRO_BITMAP* ) getResorcePtr() );
}

//-----------------------------------------------

ImageResource* ImageResource::createImageResource( const char* fileName ) {
	
	// Inciamos a string com a msg de carregamento
	std::string str( "File " );
	str += fileName;

	// Pegamos uma instancia do mapa
	ResourceMap* rscMap = ResourceMap::getInstance();

	// Verificamos se o recurso ja foi carregado
	ImageResource* rsc = (ImageResource*) rscMap->getResource( fileName );

	// Se ainda nao foi, rsc sera NULL
	if( !rsc ) {

		try {

			// Carregamos o bitmap
			ALLEGRO_BITMAP* bitmap = al_load_bitmap( fileName );

			// Lancamos um excecao, caso ocorra
			if( !bitmap ) throw Exception::CREATE_BITMAP;
			
			// Criamos um novo recurso
			rsc = new ImageResource( fileName, bitmap );

			// Adicionamos o resource ao mapa
			rscMap->addResource( fileName, rsc );

			// Montamos a mensagem do log em caso do carregamento ter sucesso.
			str += " loaded successfully!";

		}//try
		catch( Exception::EXCEPTION& ex ) {
			// Saida para log
			std::cout << Exception::getError( ex ) << std::endl;
			LogOutput::printInLogout( Exception::getError( ex ) );

			return NULL;
		}//catch

	}//if
	else {
		// Montamos a mensagem do log em caso do carregamento ter sucesso.
		str += " already exists!";
	}

	// Aumentamos o numero de referencias em uma unidade
	rsc->incReferenceAmount();

	std::cout << str << std::endl;
	LogOutput::printInLogout( str.c_str() ); // Saida para log

	return rsc;

}//createImageResource

}
} /* namespace */
