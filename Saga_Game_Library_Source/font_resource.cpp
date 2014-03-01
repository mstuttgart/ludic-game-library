#include "font_resource.h"
#include "resource_map.h"




namespace sgl {

namespace font {

FontResource::FontResource(const char* fileName, ALLEGRO_FONT* font)
  : Resource( fileName, font ){};

FontResource::~FontResource()
{
    al_destroy_font( ( ALLEGRO_FONT* ) getResorcePtr() );
}


FontResource* FontResource :: createFontResource(const char* fileName){

if(!fileName) return NULL;

std::string str( "File " );
	str += fileName;


	ResourceMap* rscMap = ResourceMap::getInstance();

	FontResource* rsc = ( FontResource* ) rscMap->getResource( fileName );


	if( !rsc ) {

		try {


			ALLEGRO_FONT* font = al_load_font( fileName,40,0 );



			if( !font ){
                sgl::Exception ex( "Error to load font.");
				throw ex;
			}



			rsc = new FontResource( fileName, font );


			rscMap->addResource( fileName, rsc );


			str += " loaded successfully!";

		}
		catch( std::exception ex ) {
			std::cout << ex.what() << std::endl;
			return NULL;
		}

	}
	else {

		str += " already exists!";
	}

	rsc->incReferenceAmount();


	std::cout << str << std::endl;

	return rsc;


}


 ALLEGRO_FONT* FontResource :: getFontPtr(){
  return (ALLEGRO_FONT*) getResorcePtr();

}


    }}
