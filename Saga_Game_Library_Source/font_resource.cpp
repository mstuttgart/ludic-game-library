#include "font_resource.h"
#include "resource_map.h"
#include <iostream>






namespace sgl {

namespace font {

//--------------------------------------------------------

FontResource::FontResource(const char* fileName, ALLEGRO_FONT* font, unsigned int fSize)
  : Resource( fileName, font ){
  rscSize = fSize;
  };

//--------------------------------------------------------
FontResource::~FontResource()
{
    al_destroy_font( ( ALLEGRO_FONT* ) getResorcePtr() );
}

//--------------------------------------------------------

FontResource* FontResource :: createFontResource(const char* fileName, const char* rscName, unsigned int fontSize){



std::string str( "File " );
str += rscName;


	ResourceMap* rscMap = ResourceMap::getInstance();
	FontResource* rsc = ( FontResource* ) rscMap->getResource( rscName );



	if (!rscMap->hasResource(rscName)){


		try {


			ALLEGRO_FONT* font = al_load_font( fileName, fontSize, 0 );


			if( !font ){
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

    rsc->incReferenceAmount();

	std::cout << str << std::endl;
	std::cout << "referamount"<<rsc->getReferenceAmount() << "\n" ;


	return rsc;


}

//--------------------------------------------------------


 ALLEGRO_FONT* FontResource :: getFontPtr(){
  return (ALLEGRO_FONT*) getResorcePtr();

}

//--------------------------------------------------------

unsigned int FontResource::getSizeResource(){

return rscSize;


}

//--------------------------------------------------------


    }}
