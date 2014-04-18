#pragma once

#include "resource.h" // Base class: sgl::Resource
#include "color.h"

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
	 * @return
	 */
	ImageResource( const String& fileName, ALLEGRO_BITMAP* bitmap );


	/**
	 * @brief
	 * @return
	 */
	ALLEGRO_BITMAP* getBitmap();

public:

	/**
	 * @brief
	 */
	virtual ~ImageResource();

	/**
	 * @brief
	 * @return
	 */
	static ImageResource* createImageResource( const String& fileName );

	/**
	 * @brief
	 * @param rsc
	 * @param x
	 * @param y
	 * @param w
	 * @param h
	 * @return
	 */
	static ImageResource* getSubImageResource(
	    ImageResource* rsc, int x, int y, int w, int h );

	/**
	 * @brief
	 * @param colorkey
	 */
	void setColorKey( Color colorkey );

	/**
	 * @brief
	 */
	operator ALLEGRO_BITMAP*();

};

}
} /* namespaces */
