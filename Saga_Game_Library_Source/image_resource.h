#pragma once

#include "resource.h" // Base class: sgl::Resource

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

	// Indica se a imageresource e uma subbitmao
	ImageResource* parent;

protected:


	/**
	 * @brief
	 * @return
	 */ 
	ImageResource( const char* fileName, ALLEGRO_BITMAP* bitmap, ImageResource* parentBitmap );


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

	/**
	 * @brief
	 * @param rsc
	 * @param x
	 * @param y
	 * @param w
	 * @param h
	 * @return
	 */
	static ImageResource* getSubImageResource( ImageResource* rsc, int x, int y, int w, int h );

	/**
	 * @brief
	 * @return
	 */
	ALLEGRO_BITMAP* getBitmap();

	/**
	 * @brief
	 * @return
	 */
	ALLEGRO_BITMAP* getSubBitmap( int x, int y, int w, int h );


	/**
	 * @brief 
	 * @param colorkey
	 */
	void setColorKey( ALLEGRO_COLOR colorkey );

};

}
} /* namespaces */

