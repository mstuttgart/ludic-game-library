#include "font.h"

namespace sgl{

namespace font{

//--------------------------------------------------

Font::Font( FontResource* resource ) {

    ptr_rsc = resource;
    fontAux = resource->getFontPtr();
    alignLeft= ALLEGRO_ALIGN_LEFT;
    alignRight= ALLEGRO_ALIGN_RIGHT;
    alignCenter= ALLEGRO_ALIGN_CENTRE;


}

//--------------------------------------------------

Font::~Font()
{
    Resource::destroyResource( ptr_rsc );
}

//-------------------------------------------------

Font* Font::createFont( const char* fileName, const char* text ){

    if ( !fileName ) return NULL;


    FontResource* rsc = FontResource::createFontResource( fileName );


    return (new Font(rsc));

}

//-------------------------------------------------

bool Font::setColorFont( unsigned char r, unsigned char g, unsigned char b)
{



}

//-------------------------------------------------

/*bool Font::setStandardColorFont( COLOR_MODE type ){




}*/

//--------------------------------------------------

ALLEGRO_FONT* Font::getAllegroFont(){}
int Font::getAlignLeft(){
return alignLeft;
}
int Font::getAlignRight(){
return alignRight;
}
int Font::getAlignCenter(){
return alignCenter;
}


}} // end namespaces
