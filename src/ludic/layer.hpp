/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is FREE SOFTWARE released under the BSD License.                //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "sgl.hpp"
#include "vector2_d.hpp"

namespace Ludic {

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
	 * @return
	 */
	Vector2D getPosition() const;

	/**
	 * @brief
	 * @return
	 */
	float getX() const;

	/**
	 * @brief
	 * @return
	 */
	float getY() const;

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
	bool isVisible() const;

	/**
	 * @brief
	 */
	virtual void draw() = 0;

};

} /* namespace */
