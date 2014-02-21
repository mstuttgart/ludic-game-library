#pragma once

#include "point.h"

namespace sgl {

class CollisionCircle;

/**
 * @file collision_rect.h
 * @author Michell Stuttgart
 * @date 02/20/14 
 * @class CollisionRect
 * @brief 
 */
class CollisionRect: public Point {

private:
	int w, h;

public:
	/**
	 * @brief
	 * @return
	 */
	int getW() const;

	/**
	 * @brief
	 * @return
	 */
	int getH() const;

	/**
	 * @brief
	 * @return
	 */
	int getXI() const;

	/**
	 * @brief
	 * @return
	 */
	int getYI() const;

	/**
	 * @brief
	 * @return
	 */
	int getXF() const;

	/**
	 * @brief
	 * @return
	 */
	int getYF() const;

public:
	/**
	 * @brief
	 */
	CollisionRect(); // Eu mudei aqui

	/**
	 * @brief
	 * @param x
	 * @param y
	 * @param w
	 * @param h
	 */
	CollisionRect(int x, int y, int w, int h);

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
	 * @param x
	 * @param y
	 * @param w
	 * @param h
	 */
	void setDimension( int x, int y, int w, int h );

public:

	/**
	 * @brief
	 * @param x
	 * @param y
	 * @return
	 */
	bool checkIntersection(int x, int y) const;
	
	/**
	 * @brief 
	 * @param c
	 * @return 
	 */
	bool checkIntersection(const CollisionRect& r) const;
	
	/**
	 * @brief 
	 * @param c
	 * @return 
	 */
	bool checkIntersection(const CollisionCircle& c) const;
};
}
