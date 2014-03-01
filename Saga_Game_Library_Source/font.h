#ifndef _SGL_FONT_
#define _SGL_FONT_

#include "font_resource.h"

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
    private:

        FontResource* ptr_rsc;
        ALLEGRO_FONT* fontAux;
        int alignLeft; // ALEGRO_ALIGN_LEFT;
        int alignRight; // ALLEGRO_ALIGN_RIGHT;
        int alignCenter; // ALLEGRO_ALIGN_CENTRE;

    protected:

        Font( FontResource* resource );


    public:

         enum COLOR_MODE {
         Red, Green, Blue, Violet,
         Grey, Brown, Pink
        };
        virtual ~Font();
        static Font* createFont ( const char* fileName);
        bool drawText(int x, int y, ALLEGRO_COLOR color,int flag, const char* text);
        ALLEGRO_COLOR setColorFont( unsigned char r, unsigned char g, unsigned char b);
        ALLEGRO_COLOR setStandardColorFont( COLOR_MODE type );
        ALLEGRO_FONT* getAllegroFont();
        int getAlignLeft();
        int getAlignRight();
        int getAlignCenter();




};

}} // end namespaces

#endif // _SGL_FONT_
