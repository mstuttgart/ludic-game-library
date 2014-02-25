#pragma once

#include "layer.h"
#include "image_resource.h"
#include "collision_rect.h"

namespace sgl {
namespace image {

/**
 * @file sprite.h
 * @author Michell Stuttgart
 * @date 02/25/14
 * @class Sprite
 * @brief
 */
class Sprite : public Layer {

protected:
	int x, y;
	CollisionRect rect;

public:

	/**
	 * @brief
	 */
	Sprite();

	/**
	 * @brief
	 */
	virtual ~Sprite() {};

	/**
	* @brief
	* @param dx
	* @param dy
	*/
	void setPosition( int x, int y );

	/**
	 * @brief
	 * @param dx
	 * @param dy
	 */
	void move( int dx, int dy );

	/**
	 * @brief
	 * @return
	 */
	int getX() const;

	/**
	 * @brief
	 * @return
	 */
	int getY() const;


	/**
	 * @brief
	 * @return
	 */
	bool collidesWith( Sprite* s );

	/**
	 * @brief
	 * @return
	 */
	CollisionRect& getCollisionRect();

};

}
} /* namespace */
