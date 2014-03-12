#include "font.h"
#include "resource_manager.h"
#include <sstream>
#include <iostream>



namespace sgl{

namespace font{

//--------------------------------------------------

Font::Font( const char* fileName,unsigned int fontSize ) {

    load(fileName,fontSize);
    fontAux = ptr_rsc->getFontPtr();
    alignment = 0;
    posX = 0;
    posY = 0;
    text = "";
    color = al_map_rgb(0,0,0);



}

ostream &operator<<(ostream &out, Font* &fonte){

fonte->drawText();


}

//--------------------------------------------------

Font::~Font()
{
//    FontResource::destroyFontResource( &ptr_rsc );
}

//-------------------------------------------------

bool Font::load( const char* fileName,unsigned int fontSize ){

    if ( !fileName ) {

    return false;

    }else{

    std::string name(fileName);
    name += " - size ";
    std::stringstream aux;
    aux << fontSize;
    name += aux.str();
    const char* rscName = name.c_str();

    ptr_rsc = FontResource::createFontResource( fileName, rscName, fontSize );

    return true;

    }



}

//----------------------------------------------

void Font::drawText(){

al_draw_text(fontAux, color, posX, posY, alignment, text.c_str());



}
//-------------------------------------------------

void Font::setColorFont( unsigned char r, unsigned char g, unsigned char b){
color =  al_map_rgb(r,g,b);


}

//-------------------------------------------------

void Font::setStandardColorFont( COLOR_MODE type ){


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


}

//-----------------------------------------------------

void Font::setPosition (unsigned int x, unsigned int y){

posX = x;
posY = y;


}

void Font::setText (std::string usrText ){

text = usrText;

}

//--------------------------------------------------

ALLEGRO_FONT* Font::getAllegroFont(){
return fontAux;

}

void Font::setAlignment(  ALIGNMENT_TYPE align ){

switch (align){
case Left:
    alignment = ALLEGRO_ALIGN_LEFT;
    break;
case Right:
    alignment = ALLEGRO_ALIGN_RIGHT;
    break;
case Center:
    alignment = ALLEGRO_ALIGN_CENTRE;
    break;

}

}

//--------------------------------------------------


}} // end namespaces
