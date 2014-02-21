#ifndef _SGL_FONT_RESOURCE_
#define _SGL_FONT_RESOURCE_

#include "resource.h"

namespace sgl{

namespace font{

class FontResource : public Resource
{
    protected:

        FontResource(const char* fileName, ALLEGRO_FONT* font);
        virtual ~FontResource();
      //  void setSizeFont(unsigned int SizeFont);
    public:

        FontResource* createResource(const char* fileName);
        const ALLEGRO_FONT* getResourcePtr();
      //  unsigned int const getSizeFont();


};

}} //end namespaces

#endif // _SGL_FONT_RESOURCE_
