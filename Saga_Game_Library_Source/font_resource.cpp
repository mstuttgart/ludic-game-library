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


			ALLEGRO_FONT* font = al_load_font( fileName,10,0 );


			if( !font ) throw Exception::LOAD_FONT;



			rsc = new FontResource( fileName, font );


			rscMap->addResource( fileName, rsc );


			str += " loaded successfully!";

		}
		catch( Exception::EXCEPTION& ex ) {
			std::cout << Exception::getError( ex ) << std::endl;
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


const ALLEGRO_FONT* FontResource :: getResourcePtr(){
  return (ALLEGRO_FONT*) getResorcePtr();

}


    }}
