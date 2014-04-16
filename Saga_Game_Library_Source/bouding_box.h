#pragma once

#include "vector2_d.h"

namespace sgl {

#define VERTICE_I	0
#define VERTICE_F	1

/**
 * @file collision_rect.h
 * @author Michell Stuttgart
 * @date 02/20/14
 * @class CollisionRect
 * @brief
 */
class BoundingBox {

private:

	Vector2D positions[2];
	float w, h;

public:

	/**
	 * @brief
	 */
	BoundingBox(); 

	/**
	 * @brief
	 * @param x
	 * @param y
	 * @param w
	 * @param h
	 */
	BoundingBox( const Vector2D& position, float _w, float _h );

	/**
	 * @brief
	 */
	~BoundingBox();
	
	/**
	 * @brief 
	 * @param position
	 * @param vertice
	 */
	void setPosition( const Vector2D& position );

	/**
	* @brief
	* @param value
	*/
	void setDimension( float w, float h );
	
	/**
	 * @brief
	 * @param dx
	 * @param dy
	 */
	void move( const Vector2D& vec );

	/**
	 * @brief
	 * @return
	 */
	inline int getWidth() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getHeight() const;
	
	
	/**
	 * @brief 
	 * @return 
	 */
	inline const Vector2D& getPosition_i() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	inline const Vector2D& getPosition_f() const;

	/**
	 * @brief
	 * @param r
	 * @return
	 */
	bool checkCollision(const BoundingBox& r) const;
	
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


//------------------------------------------------------------

const Vector2D& BoundingBox::getPosition_i() const {
	return positions[ VERTICE_I ];
}

//------------------------------------------------------------

const Vector2D& BoundingBox::getPosition_f() const {
	return positions[ VERTICE_F ];
}

//------------------------------------------------------------

int BoundingBox::getWidth() const {
	return w;
}

//------------------------------------------------------------

int BoundingBox::getHeight() const {
	return h;
}

//------------------------------------------------------------

} /* namespace */
