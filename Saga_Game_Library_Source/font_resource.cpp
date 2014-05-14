#include "font_resource.h"
#include "resource_manager.h"

#include <sstream>

using namespace sgl::font;
using namespace std;

//--------------------------------------------------------

FontResource::FontResource(
    const String& fileName, ALLEGRO_FONT* font, unsigned int fSize ):
	Resource( fileName, font ), rscSize( fSize ) {}

//--------------------------------------------------------

FontResource::~FontResource() {

	if( getFontPtr() )
    	al_destroy_font( getFontPtr() );



}

//--------------------------------------------------------

FontResource* FontResource :: createFontResource( const String& fileName,
													unsigned int fontSize ) {

	// String  = filename + fontSize
	// Podemos ter a mesma fonte com tamanho de fontes diferentes
	stringstream fontSizeStr;
	fontSizeStr << fontSize;
	
	String aux;	
	aux = fileName + " " + fontSizeStr.str();

	// Criamos a string com a mensagem de carregamento
	String str( "File " + aux );

	// Instancia do ResourceManager
	ResourceManager* rscMap = ResourceManager::Instance();

	// Verificamos se o resource esta no manager. Restorna NULL se
	// o resource nao estiver presente no mapa de resources.
	FontResource* rsc =
	    static_cast<FontResource*>( rscMap->getResource( aux ) );

	// Se o resource for NULL
	if ( !rsc ) {

		// Criamos uma nova Font
		ALLEGRO_FONT* font = al_load_font( fileName.c_str(), fontSize, 0 );

		// Se ocorreu falha no carregamento da font, nos lancamos excecao
		if( !font )
		{
			throw sgl::Exception( "ERROR: Error to load font." );
			return nullptr;
		}

		// Criamos uma nova FontResource
		rsc = new FontResource( aux, font, fontSize );

		// Adicionamos o resource no mapa de resources
		rscMap->addResource( aux, rsc );

		str += " loaded successfully!";

	}
	else {
		str += " already exists!";
	}

	// Imprimimos a saida
	cout << str << endl;

	return rsc;
}

//--------------------------------------------------------

ALLEGRO_FONT* FontResource :: getFontPtr() {
	return static_cast<ALLEGRO_FONT*> ( getResourcePtr() );

}

//--------------------------------------------------------

unsigned int FontResource::getSizeResource() {
	return rscSize;
}

//--------------------------------------------------------

FontResource::operator ALLEGRO_FONT*() {
	return getFontPtr();
}

//--------------------------------------------------------
