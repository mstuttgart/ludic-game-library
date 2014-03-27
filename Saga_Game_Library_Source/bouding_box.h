#pragma once

#include "point.h"
#include <vector>

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

	std::vector<Point*> vertices;
	int w, h;

public:

	/**
	 * @brief
	 */
	BoundingBox(); // Eu mudei aqui

	/**
	 * @brief
	 * @param x
	 * @param y
	 * @param w
	 * @param h
	 */
	BoundingBox(int _x, int _y, int _w, int _h);

	/**
	 * @brief
	 */
	~BoundingBox();

	/**
	 * @brief
	 * @param x
	 */
	void setXL( int x );

	/**
	 * @brief
	 * @param y
	 */
	void setYU( int y );

	/**
	* @brief
	* @param value
	*/
	void setW(int value);

	/**
	 * @brief
	 * @param value
	 */
	void setH(int value);

	/**
	 * @brief
	 * @param dx
	 * @param dy
	 */
	void moveRectangle( int dx, int dy );

	/**
	 * @brief
	 * @return
	 */
	inline int getW() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getH() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getXL() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getYU() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getXR() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getYB() const;

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

	/**
	 * @brief 
	 * @param r
	 * @return 
	 */
	bool checkHorizontalCollision( const BoundingBox& r );
	
	/**
	 * @brief 
	 * @param r
	 * @return 
	 */
	bool checkHorizontalCollision( int x, int w );
	
	/**
	 * @brief 
	 * @param y
	 * @param h
	 * @return 
	 */
	bool checkVerticalCollision( const BoundingBox& r );
	
	/**
	 * @brief 
	 * @param y
	 * @param h
	 * @return 
	 */
	bool checkVerticalCollision( int y, int h );

};

//---------------------------------------

int BoundingBox::getW() const {
	return w;
}

//---------------------------------------

int BoundingBox::getH() const {
	return h;
}

//---------------------------------------

int BoundingBox::getXL() const {
	return vertices[VERTICE_I]->getX();
}

//---------------------------------------

int BoundingBox::getYU() const {
	return vertices[VERTICE_I]->getY();
}

//---------------------------------------

int BoundingBox::getXR() const {
	return vertices[VERTICE_F]->getX();
}

//---------------------------------------

int BoundingBox::getYB() const {
	return vertices[VERTICE_F]->getY();
}

//---------------------------------------

} /* namespace */
