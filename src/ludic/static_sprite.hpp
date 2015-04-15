#pragma once

#include "sprite.hpp"
#include "image_resource.hpp"
#include "bouding_box.hpp"
#include "collision_mask.hpp"

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
	CollisionMask mask;

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
	 * @return
	 */
	//virtual bool collidesWith( Sprite* s, bool pixelLevel );

	/**
	 * @brief
	 */
	void draw();

};

}
} /* namespaces */
