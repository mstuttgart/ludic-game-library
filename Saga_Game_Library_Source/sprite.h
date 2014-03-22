#pragma once

#include "layer.h"
#include "image_resource.h"
#include "bouding_box.h"
#include <cstdint>

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
	BoundingBox rect;

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
	virtual void setPosition( int x, int y );

	/**
	 * @brief
	 * @param dx
	 * @param dy
	 */
	virtual void move( int dx, int dy );

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
	virtual int getWidth() = 0;


	/**
	 * @brief
	 * @return
	 */
	virtual int getHeight() = 0;


	/**
	 * @brief 
	 * @return 
	 */
	inline int getXf();

	/**
	 * @brief 
	 * @return 
	 */
	inline int getYf();

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

//----------------------------------------------------

int Sprite::getXf(){
	return getX() + getWidth();
}

//---------------------------------------------------

int Sprite::getYf() {
	return getY() + getHeight();
}

//----------------------------------------------------
}
} /* namespace */
