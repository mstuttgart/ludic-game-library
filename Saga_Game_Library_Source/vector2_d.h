#pragma once

#include <cmath>

namespace sgl {

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
	 * @param v
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
	void setCoordenate( float x, float y );
	
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
	 * @param v
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
	 * @param v
	 */
	Vector2D normalize();

	/**
	 * @brief 
	 * @param v
	 */
	Vector2D operator +( const Vector2D& vector ) const;

	/**
	 * @brief 
	 * @param v
	 */
	void operator +=( const Vector2D& vector );

	/**
	 * @brief 
	 * @param v
	 */
	Vector2D operator -( const Vector2D& vector ) const;

	/**
	 * @brief 
	 * @param v
	 */
	void operator -=( const Vector2D& vector );

	/**
	 * @brief 
	 * @param v
	 */
	void operator =( const Vector2D& vector );

	/**
	 * @brief 
	 * @param v
	 */
	bool operator ==( const Vector2D& vector ) const;

	/**
	 * @brief 
	 * @param v
	 */
	bool operator !=( const Vector2D& vector ) const;

	/**
	 * @brief 
	 * @param v
	 */
	Vector2D operator *( float scalar ) const;
	
	/**
	 * @brief 
	 */
	Vector2D operator *( const Vector2D& vec ) const;

	/**
	 * @brief 
	 * @param v
	 */
	void operator *=( float scalar );

	/**
	 * @brief 
	 * @param v
	 */
	Vector2D operator /( float scalar ) const;
	
	/**
	 * @brief 
	 * @param vec
	 */
	Vector2D operator /( const Vector2D& vec ) const;

	/**
	 * @brief 
	 * @param v
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
