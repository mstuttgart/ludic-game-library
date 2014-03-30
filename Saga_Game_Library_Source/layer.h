#pragma once

#include "sgl.h"
#include "vector2_d.h"

namespace sgl {
namespace image {

/**
 * @file layer.h
 * @author Michell Stuttgart
 * @date 01/24/14
 * @class Layer
 * @brief
 */
class Layer {

private:

	Vector2D position;
	bool visible;

public:

	/**
	 * @brief
	 */
	Layer();

	/**
	 * @brief
	 * @return
	 */
	virtual ~Layer() {};

	/**
	* @brief
	* @param dx
	* @param dy
	*/
	virtual void setPosition( const Vector2D& vec );

	/**
	 * @brief
	 * @param dx
	 * @param dy
	 */
	virtual void move( const Vector2D& vec );

	/**
	 * @brief
	 */
	inline Vector2D getPosition() const;

	/**
	 * @brief
	 * @return
	 */
	inline float getX() const;

	/**
	 * @brief
	 * @return
	 */
	inline float getY() const;

	/**
	 * @brief
	 * @return
	 */
	virtual float getWidth() const = 0;


	/**
	 * @brief
	 * @return
	 */
	virtual float getHeight() const = 0;

	/**
	* @brief
	* @param visible
	*/
	void setVisible( bool visible );

	/**
	 * @brief
	 * @return
	 */
	inline bool isVisible() const;

	/**
	 * @brief
	 */
	virtual void draw() = 0;

};

//==========================================================

Vector2D Layer::getPosition() const {
	return position;
}

//-----------------------------------------------------------

float Layer::getX() const {
	return position.getX();
}

//-----------------------------------------------------------

float Layer::getY() const {
	return position.getY();
}

//-----------------------------------------------------------

bool Layer::isVisible() const {
	return visible;
}

//----------------------------------------------------------

}
} /* namespace */
