#include "font.h"
#include "resource_map.h"
#include <iostream>


namespace sgl{

namespace font{

//--------------------------------------------------

Font::Font( FontResource* resource, const char* fileName ) {

    ptr_rsc = resource;
    fontAux = resource->getFontPtr();
    file = fileName;
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

Font* Font::createFont( const char* fileName,unsigned int size){

    if ( !fileName ) return NULL;


    FontResource* rsc = FontResource::createFontResource( fileName, size );


    return (new Font(rsc,fileName));

}

//----------------------------------------------

bool Font::drawText(int x, int y, ALLEGRO_COLOR color, int flag, const char* text){

al_draw_text(fontAux, color, x, y,flag, text);

return true;



}
//-------------------------------------------------

/*bool Font::drawTextf(int x, int y, ALLEGRO_COLOR color,int flag, const char* text,...){

al_draw_textf(fontAux, color, x, y, flag, text);

return true;


}*/

//---------------------------------------------------


ALLEGRO_COLOR Font::setColorFont( unsigned char r, unsigned char g, unsigned char b){
return al_map_rgb(r,g,b);


}

//-------------------------------------------------

ALLEGRO_COLOR Font::setStandardColorFont( COLOR_MODE type ){

ALLEGRO_COLOR color = al_map_rgb(0,0,0);

 switch (type){
    case Black:
        color = al_map_rgb(0,0,0);
        break;

    case Red:
        color = al_map_rgb(255,0,0);
        break;

    case Blue:
        color = al_map_rgb(0,0,255);
        break;

    case Yellow:
        color = al_map_rgb(255,255,0);
        break;

    case Green:
        color = al_map_rgb(0,255,0);
        break;

    case Orange:
        color = al_map_rgb(255,165,0);
        break;

    case Purple:
        color = al_map_rgb(160,32,240);
        break;

    case Pink:
       color = al_map_rgb(255,20,147);
       break;

    case Grey:
       color = al_map_rgb(190,190,190);
       break;

    case Brown:
       color = al_map_rgb(139,69,19);
       break;

    case Gold:
       color = al_map_rgb(255,215,0);
       break;

    case White:
       color = al_map_rgb(255,255,255);
       break;

    }
return color;

}

//--------------------------------------------------

ALLEGRO_FONT* Font::getAllegroFont(){
return fontAux;

}

//--------------------------------------------------
int Font::getAlignLeft(){
return alignLeft;
}

//--------------------------------------------------
int Font::getAlignRight(){
return alignRight;
}

//--------------------------------------------------
int Font::getAlignCenter(){
return alignCenter;
}

//--------------------------------------------------

}} // end namespaces
