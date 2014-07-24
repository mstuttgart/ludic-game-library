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

#include <vector>

namespace Ludic
{

/**
 * @file collision_mask.hpp
 * @author Michell Stuttgart
 * @date 07/19/14
 * @class CollisionMask
 * @brief
 */
class CollisionMask
{

private:

	int width;
	int height;
	std::vector<bool> bits;

private:

	bool isColorEqual(ALLEGRO_COLOR col1, ALLEGRO_COLOR col2);
	bool isTransparent(ALLEGRO_COLOR col1);

public:

	/**
	 * @brief
	 */
	CollisionMask();

	/**
	 * @brief
	 * @param imgResource
	 */
	CollisionMask( Ludic::ImageResource* imgResource );

	/**
	 * @brief
	 */
	virtual ~CollisionMask();

	/**
	 * @brief
	 * @param imgResource
	 */
	void initMask( Ludic::ImageResource* imgResource );

	/**
	 * @brief
	 * @param mask
	 * @param xoffset
	 * @param yoffset
	 * @return
	 */
	bool collisionVerify( const CollisionMask& mask, int xoffset, int yoffset ) const;

	/**
	 * @brief
	 * @return
	 */
	int getHeigth() const;

	/**
	 * @brief
	 * @return
	 */
	int getWidth() const;

};

} /* namespace */
