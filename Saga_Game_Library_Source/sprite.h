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
	float angle;
	float scale_x, scale_y;

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
	 * @param angle
	 */
	void setAngle(float angle);

	/**
	 * @brief
	 * @param scale_x
	 * @param scale_y
	 */
	void setScale( float scale_x, float scale_y );

	/**
	 * @brief
	 * @return
	 */
	inline int getX() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getY() const;

	/**
	 * @brief
	 * @return
	 */
	inline float getAngle() const;

	/**
	 * @brief
	 * @return
	 */
	inline float getScaleX() const;

	/**
	 * @brief
	 * @return
	 */
	inline float getScaleY() const;

	/**
	 * @brief
	 * @return
	 */
	virtual bool collidesWith( Sprite* s );

	/**
	 * @brief
	 * @return
	 */
	inline CollisionRect& getCollisionRect();

};


//----------------------------------------------------

int Sprite::getX() const { return x; }
int Sprite::getY() const { return y; }

float Sprite::getAngle() const { return angle; }

float Sprite::getScaleX() const { return scale_x; }
float Sprite::getScaleY() const { return scale_y; }

CollisionRect& Sprite::getCollisionRect() {	return rect; }

}
} /* namespace */
