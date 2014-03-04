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
	 * @param flag
	 */
	void setFlip( FLIP flag );

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
	int getFlip() const;

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
