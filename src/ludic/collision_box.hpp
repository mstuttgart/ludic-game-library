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

#include "vector2_d.hpp"

namespace Ludic {

#define VERTEX_I	0
#define VERTEX_F	1

/**
 * @file collisionBox.hpp
 * @author Michell Stuttgart
 * @date 02/20/14
 * @class CollisionBox
 * @brief
 */
class CollisionBox {

private:

	Vector2D positions[2];
	float w, h;

public:

	/**
	 * @brief
	 */
	CollisionBox();

	/**
	 * @brief
	 * @param x
	 * @param y
	 * @param w
	 * @param h
	 */
	CollisionBox( const Vector2D& position, float _w, float _h );

	/**
	 * @brief
	 */
	~CollisionBox();

	/**
	 * @brief
	 * @param position
	 */
	void setPosition( const Vector2D& position );

	/**
	* @brief
	* @param w
	* @param h
	*/
	void setDimension( float w, float h );

	/**
	 * @brief
	 * @param vec
	 */
	void move( const Vector2D& vec );

	/**
	 * @brief
	 * @return
	 */
	int getWidth() const;

	/**
	 * @brief
	 * @return
	 */
	int getHeight() const;


	/**
	 * @brief
	 * @return
	 */
	const Vector2D& getPosition_i() const;

	/**
	 * @brief
	 * @return
	 */
	const Vector2D& getPosition_f() const;

	/**
	 * @brief
	 * @param r
	 * @return
	 */
	bool checkCollision(const CollisionBox& r) const;

	/**
	 * @brief
	 * @param x
	 * @param y
	 * @param w
	 * @param h
	 * @return
	 */
	bool checkCollision( int x, int y, int w, int h ) const;

};

} /* namespace */
