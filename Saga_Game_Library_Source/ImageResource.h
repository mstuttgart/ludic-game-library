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

private:

	/**
	 * @brief 
	 * @param bitmap
	 * @param fileName
	 * @return 
	 */
	static bool loadAllegroBitmap( ALLEGRO_BITMAP* bitmap, const char* fileName );

protected:

	/**
	 * @brief 
	 * @param fileName
	 * @param bitmap
	 */
	ImageResource( const char* fileName, ALLEGRO_BITMAP* bitmap );
	
	
	/**
	 * @brief 
	 */
	virtual ~ImageResource();

public:

	/**
	 * @brief 
	 * @param fileName
	 * @return 
	 */
	static ImageResource* loadImageResource( const char* fileName );
	
	
	/**
	 * @brief 
	 * @param imgResource
	 */
	static void destroyImageResource( ImageResource* imgResource );
	
	/**
	 * @brief 
	 * @param x
	 * @param y
	 * @param mirror
	 */
	virtual void draw( int& x, int& y, int& mirror );

};

}
} /* namespaces */

#endif // _SGL_IMAGE_RESOURCE_
