#ifndef _SGL_FONT_RESOURCE_
#define _SGL_FONT_RESOURCE_

#include "resource.h"

namespace sgl{

namespace font{

/**
 * @file FontResource.h
 * @author Paulo Vicente
 * @date 02/22/14
 * @class FontResource
 * @brief
 */
class FontResource : public Resource
{
    private:

    unsigned int rscSize;

    protected:

        FontResource(const char* fileName, ALLEGRO_FONT* font, unsigned int fSize);
        virtual ~FontResource();

    public:

        static FontResource* createFontResource(const char* fileName, const char* rscName, unsigned int fontSize);
        unsigned int getSizeResource();
        ALLEGRO_FONT* getFontPtr();



};

}} //end namespaces

#endif // _SGL_FONT_RESOURCE_
