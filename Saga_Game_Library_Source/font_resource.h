#pragma once

#include "resource.h"

namespace sgl {
namespace font {

/**
 * @file FontResource.h
 * @author Paulo Vicente
 * @date 02/22/14
 * @class FontResource
 * @brief
 */
class FontResource : public Resource {
	
private:

	unsigned int rscSize;

protected:

	FontResource(String fileName, ALLEGRO_FONT* font, unsigned int fSize);
	virtual ~FontResource();

public:

	static FontResource* createFontResource(String fileName, String rscName, unsigned int fontSize);
	unsigned int getSizeResource();
	ALLEGRO_FONT* getFontPtr();



};

}
} //end namespaces
