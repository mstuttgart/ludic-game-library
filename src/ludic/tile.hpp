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

#include "ludic.hpp"
#include "image_resource.hpp"
#include "collision_box.hpp"

namespace Ludic {

/**
 * @file tile.hpp
 * @author Michell Stuttgart
 * @date 02/16/14
 * @class Tile
 * @brief
 */
class Tile {

private:

	int id;
	Vector2D position;
	ImageResource* bitmap;
	CollisionBox box;

public:

	/**
	 * @brief
	 * @param _x
	 * @param _y
	 * @param _id
	 * @param w
	 * @param h
	 * @param _bitmap
	 */
	Tile( int& _x, int& _y, const int& _id, int& w, int& h, ImageResource* _bitmap );

	/**
	 * @brief
	 */
	virtual ~Tile();

	/**
	 * @brief
	 * @return
	 */
	operator ALLEGRO_BITMAP*() const;

	/**
	 * @brief
	 * @return
	 */
	int getX() const;

	/**
	 * @brief
	 * @return
	 */
	int getY() const;

	/**
	 * @brief
	 * @return
	 */
	const CollisionBox& getBoundingBox() const;

	/**
	 * @brief
	 * @return
	 */
	const int& getId() const;

	/**
	 * @brief
	 */
	void draw();

	/**
	 * @brief
	 * @param vec
	 */
	void move( const Vector2D& vec );

};

} /* namespace */
