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
	StaticSprite(){};

	/**
	 * @brief
	 * @param fileName
	 */
	StaticSprite( const char* fileName );

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
	bool load( const char* fileName );

	/**
	 * @brief
	 */
	ALLEGRO_BITMAP* getAllegroBitmap();
	
	/**
	 * @brief 
	 * @return 
	 */
	ImageResource* getImageResource() const;

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
