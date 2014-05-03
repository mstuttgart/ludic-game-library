#pragma once

#include "sprite.h"
#include "image_resource.h"
#include "bouding_box.h"

#include <map>
#include <vector>

namespace sgl {
namespace image {

/**
 * @file static_sprite.h
 * @author Michell Stuttgart
 * @date 01/16/14
 * @class StaticSprite
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
	StaticSprite( const String& fileName );

	/**
	* @brief
	*/
	virtual ~StaticSprite(){};

	/**
	 * @brief
	 * @param fileName
	 * @return
	 */
	bool load( const String& fileName );

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
