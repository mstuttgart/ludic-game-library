#pragma once

#include "layer.h"
#include "image_resource.h"
#include "collision_rect.h"

namespace sgl {
namespace image {

enum class FLIP {
    NONE    = 0,
    H_FLIP  = ALLEGRO_FLIP_HORIZONTAL,
    V_FLIP  = ALLEGRO_FLIP_VERTICAL,
    HV_FLIP = ALLEGRO_FLIP_HORIZONTAL | ALLEGRO_FLIP_VERTICAL
};

enum class ROTATE {
    NONE      = 0,
    _90  = 90,
    _180 = 180,
    _270 = 270
};

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
	int flip;
	float angle;
	int ref_x, ref_y;
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
	 * @param ref_x
	 * @param ref_y
	 */
	void setRotatePoint( int ref_x, int ref_y );

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
	void setAngle( ROTATE angle );

	/**
	 * @brief
	 * @param flag
	 */
	void setFlip( FLIP flag );

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
	int getRefX() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	int getRefY() const;

	/**
	 * @brief
	 * @return
	 */
	float getAngle() const;

	/**
	 * @brief
	 * @return
	 */
	int getFlip() const;

	/**
	 * @brief
	 * @return
	 */
	float getScaleX() const;

	/**
	 * @brief
	 * @return
	 */
	float getScaleY() const;

	/**
	 * @brief
	 * @return
	 */
	virtual bool collidesWith( Sprite* s );

	/**
	 * @brief
	 * @return
	 */
	CollisionRect& getCollisionRect();

};

}
} /* namespace */
