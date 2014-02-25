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
class CollisionRect {

private:
	std::vector<Point*> vertices;
	int w, h;

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
	CollisionRect(int _x, int _y, int _w, int _h);
	
	/**
	 * @brief 
	 */
	~CollisionRect();

	/**
	 * @brief 
	 * @param x
	 */
	void setXi( int x );
	
	/**
	 * @brief 
	 * @param y
	 */
	void setYi( int y );

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
	int getXi() const;

	/**
	 * @brief
	 * @return
	 */
	int getYi() const;

	/**
	 * @brief
	 * @return
	 */
	int getXf() const;

	/**
	 * @brief
	 * @return
	 */
	int getYf() const;


	/**
	 * @brief 
	 * @param r
	 * @return 
	 */
	bool checkCollision(const CollisionRect& r) const;

};
}
