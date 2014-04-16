#pragma once

#include "font_resource.h"
#include <iostream>

using std::ostream;

namespace sgl{

namespace font{

/**
 * @file Font.h
 * @author Paulo Vicente
 * @date 02/22/14
 * @class Font
 * @brief
 */

class Font
{
    friend ostream &operator<< ( ostream &, Font* &);

    private:

        FontResource* ptr_rsc;
        ALLEGRO_FONT* fontAux;
        const char* file;
        int alignment;
        unsigned int posX; // Vertical Position
        unsigned int posY; // Horizontal Position
        String text;
        ALLEGRO_COLOR color;


    public:

        enum ALIGNMENT_TYPE {
			Left, Right, Center
        };
        Font( const String& fileName, unsigned int fontSize );
        Font(FontResource* rsc);
        virtual ~Font();
        bool load( const String& fileName, unsigned int fontSize );
        void drawText();
        void setFontColor( unsigned char r, unsigned char g, unsigned char b);
        void setStandardFontColor( const String& type );
        void setPosition (unsigned int x, unsigned int y);
        void setText (const String& usrText);
        void setAlignment(ALIGNMENT_TYPE align);
		operator ALLEGRO_FONT*() const;


};

}} // end namespaces
