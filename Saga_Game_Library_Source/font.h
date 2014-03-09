#ifndef _SGL_FONT_
#define _SGL_FONT_

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
        std::string text;
        ALLEGRO_COLOR color;

    protected:




    public:
        Font( const char* fileName,unsigned int fontSize );

        enum COLOR_MODE {
         Black, Red, Blue, Yellow, Green, Orange,
         Purple, Pink, Grey, Brown, Gold, White
        };
        enum ALIGNMENT_TYPE {
        Left, Right, Center
        };
        virtual ~Font();
        bool load( const char* fileName, unsigned int fontSize );
        void drawText();
        void setColorFont( unsigned char r, unsigned char g, unsigned char b);
        void setStandardColorFont( COLOR_MODE type );
        void setPosition (unsigned int x, unsigned int y);
        void setText (std::string usrText);
        void setAlignment(ALIGNMENT_TYPE align);
        ALLEGRO_FONT* getAllegroFont();





};

}} // end namespaces

#endif // _SGL_FONT_
