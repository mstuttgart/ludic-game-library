#pragma once

#include "sprite.h"
#include "image_resource.h"
#include "bouding_box.h"

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
class StaticSprite : public Sprite {

private:

	ImageResource*  imgRsc;
	ALLEGRO_BITMAP* bitmapAux;

public:

	/**
	 * @brief 
	 */
	StaticSprite();

	/**
	 * @brief
	 * @param fileName
	 */
	StaticSprite( String fileName );

	/**
	 * @brief
	 * @param resource
	 */
	StaticSprite( ImageResource* resource );

	/**
	* @brief
	*/
	virtual ~StaticSprite(){};

	/**
	 * @brief 
	 * @param fileName
	 * @return 
	 */
	bool load( String fileName );
	
	/**
	 * @brief 
	 * @return 
	 */
	const ImageResource* getImageResource() const;

	/**
	 * @brief
	 * @return
	 */
	virtual float getWidth() const;


	/**
	 * @brief
	 * @return
	 */
	virtual float getHeight() const;


	/**
	 * @brief
	 */
	void draw();

};

}
} /* namespaces */
