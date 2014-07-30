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
 * @brief Create a bit mask of base image.
 *
 * This class is used to verify pixel-perfect collision.
 */
class CollisionMask
{

private:

	int width;
	int height;
	std::vector<bool> bits;

private:

	bool isColorEqual(ALLEGRO_COLOR col1, ALLEGRO_COLOR col2);

public:

	/**
	 * @brief Default Constructor.
	 */
	CollisionMask();

	/**
	 * @brief Parameter Constructor.
	 * @param imgResource The ImageResource object containing the image 
	 * to be used as the basis for the creation of the mask bit.  
	 */
	CollisionMask( Ludic::ImageResource* imgResource );

	/**
	 * @brief Default Destructor.
	 */
	virtual ~CollisionMask();

	/**
	 * @brief Create a mask bit of ImageResource object.
	 * @param imgResource The ImageResource object containing the image 
	 * to be used as the basis for the creation of the mask bit.  
	 */
	void initMask( Ludic::ImageResource* imgResource );

	/**
	 * @brief Verify if occurred collision between two CollisionMask objects
	 * @param mask The CollsionMask which will be checked for collision
	 * @param xoffset The difference of coordinates of two masks.
	 * @param yoffset The difference of coordinates of two masks.
	 * @return
	 */
	bool collisionVerify( const CollisionMask& mask, int xoffset, int yoffset ) const;

	/**
	 * @brief Get the height of bit mask. 
	 *
	 * This weight is a same value of width of base image.
	 * @return The height of bit mask.
	 */
	int getHeigth() const;

	/**
	 * @brief Get the width of bit mask.
	 *
	 * This height is a same value of height of base image.
	 * @return The height of bit mask.
	 */
	int getWidth() const;

};

} /* namespace */
