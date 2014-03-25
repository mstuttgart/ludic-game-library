#include "font_resource.h"
#include "resource_manager.h"
#include <iostream>

using namespace sgl::font;

//--------------------------------------------------------

FontResource::FontResource(String fileName,
                           ALLEGRO_FONT* font, unsigned int fSize):
	Resource( fileName, font ), rscSize( fSize ) {};

//--------------------------------------------------------
FontResource::~FontResource() {
	al_destroy_font( ( ALLEGRO_FONT* ) getResorcePtr() );
}

//--------------------------------------------------------

FontResource* FontResource :: createFontResource(String fileName, String rscName, unsigned int fontSize) {



	std::string str( "File " );
	str += rscName;


	ResourceManager* rscMap = ResourceManager::getResourceManager();
	FontResource* rsc = ( FontResource* ) rscMap->getResource( rscName );



	if (!rscMap->hasResource(rscName)) {


		try {


			ALLEGRO_FONT* font = al_load_font( fileName.c_str(), fontSize, 0 );



			if( !font ) {
				sgl::Exception ex( "Error to load font.");
				throw ex;
			}



			rsc = new FontResource( rscName, font, fontSize );


			rscMap->addResource( rscName, rsc );


			str += " loaded successfully!";


		}
		catch( sgl::Exception ex ) {
			std::cout << ex.what() << std::endl;
			return NULL;
		}

	}
	else {

		str += " already exists!";

	}


	std::cout << str << std::endl;


	return rsc;


}

//--------------------------------------------------------

ALLEGRO_FONT* FontResource :: getFontPtr() {
	return (ALLEGRO_FONT*) getResorcePtr();

}

//--------------------------------------------------------

unsigned int FontResource::getSizeResource() {

	return rscSize;


}

//--------------------------------------------------------
