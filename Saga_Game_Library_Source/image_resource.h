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
	
protected:

	/**
	 * @brief
	 * @return
	 */
	ImageResource( String fileName, ALLEGRO_BITMAP* bitmap );


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
	static ImageResource* createImageResource( String fileName );

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
	void setColorKey( ALLEGRO_COLOR colorkey );

	/**
	 * @brief
	 */
	operator ALLEGRO_BITMAP*();

};

}
} /* namespaces */
