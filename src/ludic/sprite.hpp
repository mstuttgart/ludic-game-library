/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is a FREE SOFTWARE released under the BSD License.              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "layer.hpp"
#include "image_resource.hpp"
#include "collision_box.hpp"
#include "collision_mask.hpp"

namespace Ludic {

enum class FLIP : std::uint8_t {
    NONE    = 0,
    H_FLIP  = ALLEGRO_FLIP_HORIZONTAL,
    V_FLIP  = ALLEGRO_FLIP_VERTICAL,
    HV_FLIP = ALLEGRO_FLIP_HORIZONTAL | ALLEGRO_FLIP_VERTICAL
};

/**
 * @file sprite.hpp
 * @author Michell Stuttgart
 * @date 02/25/14
 * @class Sprite
 * @brief
 */
class Sprite : public Layer {

protected:

	int flip;
	CollisionBox collisionBox;

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
	virtual bool collidesWithBox( Sprite* s );

	/**
	 * @brief
	 * @param s
	 * @return
	 */
	virtual bool collidesWithPixel( Sprite* s ) const;

	/**
	 * @brief
	 * @return
	 */
	CollisionBox& getBoundingBox();

	/**
	 * @brief
	 * @return
	 */
	virtual const CollisionMask& getMask() const = 0;

};

} /* namespace */
