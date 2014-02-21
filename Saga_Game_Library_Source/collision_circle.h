#pragma once
#include "point.h"
#include "collision_rect.h"
namespace sgl {

/**
 * @file circle.h
 * @author Michell Stuttgart
 * @date 02/20/14
 * @class Circle
 * @brief
 */
class CollisionCircle: public Point {
	
private:
	int r;
	
	public:

	/**
	 * @brief 
	 * @return 
	 */
	int getR() const;
	
	
	/**
	 * @brief 
	 * @return 
	 */
	CollisionCircle(); // mudei aqui
	
	/**
	 * @brief 
	 * @param x
	 * @param y
	 * @param r
	 */
	CollisionCircle(int x, int y, int r);
	
	/**
	 * @brief 
	 * @return 
	 */
	virtual ~CollisionCircle() {};
	
	/**
	 * @brief 
	 * @param value
	 */
	void setR(int value);
	
	public:

	/**
	 * @brief 
	 * @param c
	 * @return 
	 */
	bool checkCollision(int x, int y) const;
	
	/**
	 * @brief 
	 * @param c
	 * @return 
	 */
	bool checkCollision(const CollisionCircle& c) const;
	
	/**
	 * @brief 
	 * @param r
	 * @return 
	 */
	bool checkCollision(const CollisionRect& r) const;
};
}
