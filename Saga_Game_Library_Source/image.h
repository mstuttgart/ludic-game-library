#ifndef _SGL_IMAGE_
#define _SGL_IMAGE_

#include "image_resource.h" // Base class: sgl::Resource
#include "layer.h"

#include <map>
#include <vector>

namespace sgl {

namespace image {

/**
 * @file ImageResource.h
 * @author Michell Stuttgart
 * @date 01/16/14
 * @class ImageResource
 * @brief
 */
class Image : public Layer {

private:

	ImageResource* ptr_rsc;
	ALLEGRO_BITMAP* bitmapAux;

protected:

	/**
	 * @brief
	 * @param resource
	 */
	Image( ImageResource* resource );

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
	 * @param imgResource
	 * @return
	 */
	static Image* createImage( ImageResource* imgResource );


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
	virtual int getWidth();


	/**
	 * @brief
	 * @return
	 */
	virtual int getHeight();



	/**
	 * @brief
	 */
	virtual void draw();


};

}
} /* namespaces */

#endif // _SGL_IMAGE_RESOURCE_
