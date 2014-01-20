#ifndef _SGL_IMAGE_
#define _SGL_IMAGE_

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
class Image {

private:

	Resource* ptr_rsc;
	ALLEGRO_BITMAP* bitmap;

protected:
	
	/**
	 * @brief 
	 * @param resource
	 */
	Image( Resource* resource );

public:

	/**
		 * @brief
		 */
	virtual ~Image();

	/**
	 * @brief
	 * @param fileName
	 * @return
	 */
	static Image* createImage( const char* fileName );


	/**
	 * @brief
	 * @param img
	 * @param x
	 * @param y
	 * @param width
	 * @param height
	 * @return
	 */
	static Image* createImage( Image* img, int x, int y, int width, int height );


	/**
	 * @brief
	 * @param width
	 * @param height
	 * @return
	 */
	static Image* createImage( int width, int height );


	/**
	 * @brief
	 */
	ALLEGRO_BITMAP* getAllegroBitmap();


	/**
	 * @brief
	 * @return
	 */
	int getWidth();


	/**
	 * @brief
	 * @return
	 */
	int getHeight();

};

}
} /* namespaces */

#endif // _SGL_IMAGE_RESOURCE_
