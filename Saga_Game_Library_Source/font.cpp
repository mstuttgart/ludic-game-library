#include "font.h"
#include <sstream>
#include <iostream>

using namespace sgl::font;

//--------------------------------------------------

Font::Font( const String& fileName,unsigned int fontSize ) {

    load(fileName,fontSize);
    fontAux = ptr_rsc->getFontPtr();
    alignment = 0;
    posX = 0;
    posY = 0;
    text = "";
    color = al_map_rgb(0,0,0);



}

//---------------------------------------------------

Font::Font(FontResource* rsc){
	if (rsc){
		ptr_rsc = rsc;
		fontAux = rsc->getFontPtr();
		alignment = 0;
		posX = 0;
		posY = 0;
		text = "";
		color = al_map_rgb(0,0,0);

	}

}

//---------------------------------------------------

ostream &operator<<(ostream &out, Font* &fonte){

	fonte->drawText();

}

//--------------------------------------------------

Font::~Font()
{
//    FontResource::destroyFontResource( &ptr_rsc );
}

//-------------------------------------------------

bool Font::load( const String& fileName, unsigned int fontSize ){

    if ( fileName.empty() ) {

		return false;

    }else{

		String name(fileName);
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

void Font::setFontColor( unsigned char r, unsigned char g, unsigned char b){

	color =  al_map_rgb(r,g,b);

}

//-------------------------------------------------

void Font::setStandardFontColor( const String& type ){

	color = al_color_name(type.c_str());

}

//-----------------------------------------------------

void Font::setPosition (unsigned int x, unsigned int y){

	posX = x;
	posY = y;

}

void Font::setText (const String& usrText ){

	text = usrText;

}

//--------------------------------------------------

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
		default: break;

	}

}

//--------------------------------------------------

Font::operator ALLEGRO_FONT*() const {

	return fontAux;

}
