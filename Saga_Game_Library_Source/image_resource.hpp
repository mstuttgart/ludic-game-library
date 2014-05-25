#pragma once

#include "resource.hpp" // Base class: sgl::Resource
#include "color.hpp"

namespace sgl {
namespace image {

/**
 * @file image_resource.h
 * @author Michell Stuttgart
 * @date 01/16/14
 * @class ImageResource
 * @brief
 */
class ImageResource : public Resource {

private:

	/**
	 * @brief
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
	static ImageResource* createImageResource(
	    const String& label, int width, int height );

	/**
	 * @brief
	 * @return
	 */
	static ImageResource* loadImageResource( const String& fileName );

	/**
	 * @brief
	 * @param rsc
	 * @param x
	 * @param y
	 * @param w
	 * @param h
	 * @return
	 */
	ImageResource* getSubImageResource( int x, int y, int w, int h );

	/**
	 * @brief
	 * @param colorkey
	 */
	void setColorKey( const Color& colorkey );
	
	/**
	 * @brief
	 */
	void setAsTarger();

	/**
	 * @brief
	 * @return
	 */
	operator ALLEGRO_BITMAP*();

};

}
} /* namespaces */
