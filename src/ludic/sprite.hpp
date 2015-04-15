#pragma once

#include "layer.hpp"
#include "image_resource.hpp"
#include "bouding_box.hpp"

namespace sgl {
namespace image {

enum class FLIP : std::uint8_t {
    NONE    = 0,
    H_FLIP  = ALLEGRO_FLIP_HORIZONTAL,
    V_FLIP  = ALLEGRO_FLIP_VERTICAL,
    HV_FLIP = ALLEGRO_FLIP_HORIZONTAL | ALLEGRO_FLIP_VERTICAL
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

	int flip;
	BoundingBox collisionBox;

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
	* @param vec
	*/
	virtual void setPosition( const Vector2D& vec );

	/**
	 * @brief
	 * @param vec
	 */
	virtual void move( const Vector2D& vec );

	/**
	 * @brief
	 * @param flag
	 */
	void setFlip( FLIP flag );

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
	BoundingBox& getBoundingBox();

};

}
} /* namespace */
