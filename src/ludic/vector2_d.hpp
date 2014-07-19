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

#include <cmath>

namespace Ludic {

/**
 * @file vector2_d.h
 * @author Michell Stuttgart
 * @date 03/29/14
 * @class Vector2D
 * @brief
 */
class Vector2D {

private:

	float x;
	float y;

public:

	/**
	 * @brief
	 */
	Vector2D();


	/**
	 * @brief
	 * @param fx
	 * @param fy
	 */
	Vector2D( float fx, float fy );

	/**
	 * @brief
	 * @param _x
	 * @param _y
	 */
	Vector2D( int _x, int _y );

	/**
	 * @brief
	 * @param vector
	 */
	Vector2D( const Vector2D& vector );

	/**
	 * @brief
	 */
	virtual ~Vector2D();

	/**
	 * @brief
	 * @param x
	 * @param y
	 */
	void setCoordinates( float x, float y );

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
	 * @param magnitude
	 * @param angle
	 * @return
	 */
	static Vector2D generateVector2D( float magnitude, float angle );

	/**
	 * @brief
	 * @param vector
	 * @return
	 */
	float dotProduct( const Vector2D& vector ) const;

	/**
	 * @brief
	 * @return
	 */
	float magnitude() const;

	/**
	 * @brief
     * @return
	 */
	Vector2D normalize();

	/**
	 * @brief
	 * @param vector
	 * @return
	 */
	Vector2D operator +( const Vector2D& vector ) const;

	/**
	 * @brief
	 * @param vector
	 * @return
	 */
	void operator +=( const Vector2D& vector );

	/**
	 * @brief
	 * @param vector
	 * @return
	 */
	Vector2D operator -( const Vector2D& vector ) const;

	/**
	 * @brief
	 * @param vector
	 * @return
	 */
	void operator -=( const Vector2D& vector );

	/**
	 * @brief
	 * @param vector
	 * @return
	 */
	void operator =( const Vector2D& vector );

	/**
	 * @brief
	 * @param vector
	 * @return
	 */
	bool operator ==( const Vector2D& vector ) const;

	/**
	 * @brief
	 * @param vector
	 * @return
	 */
	bool operator !=( const Vector2D& vector ) const;

	/**
	 * @brief
	 * @param scalar
	 * @return
	 */
	Vector2D operator *( float scalar ) const;

	/**
	 * @brief
     * @param vec
	 * @return
	 */
	Vector2D operator *( const Vector2D& vec ) const;

	/**
	 * @brief
	 * @param scalar
	 * @return
	 */
	void operator *=( float scalar );

	/**
	 * @brief
	 * @param scalar
	 * @return
	 */
	Vector2D operator /( float scalar ) const;

	/**
	 * @brief
	 * @param vec
	 * @return
	 */
	Vector2D operator /( const Vector2D& vec ) const;

	/**
	 * @brief
	 * @param scalar
	 * @return
	 */
	void operator /=( float scalar );

	/**
	 * @brief
	 */
	void floor();

	/**
	 * @brief
	 */
	void ceil();

};

} /* namespace */
