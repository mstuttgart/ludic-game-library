#ifndef _SGL_IMAGE_RESOURCE_
#define _SGL_IMAGE_RESOURCE_

#include "Resource.h" // Base class: sgl::Resource

namespace sgl {

namespace image {

/**
 * @file ImageResource.h
 * @author Michell Stuttgart
 * @date 01/16/14
 * @class ImageResource
 * @brief
 */
class ImageResource : public Resource {

protected:


	/**
	 * @brief
	 * @return
	 */
	ImageResource( const char* fileName, ALLEGRO_BITMAP* bitmap );


	/**
	 * @brief
	 */
	virtual ~ImageResource();
	
public:

	/**
	 * @brief 
	 * @return 
	 */
	static ImageResource* createImageResource( const char* fileName );

};

}
} /* namespaces */

#endif // _SGL_IMAGE_RESOURCE_
