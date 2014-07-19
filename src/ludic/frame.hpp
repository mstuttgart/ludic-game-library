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

#include "sgl.hpp"
#include "image_resource.hpp"
#include "collision_mask.hpp"

namespace Ludic
{

/**
 * @file frame.h
 * @author Michell Stuttgart
 * @date 04/15/14
 * @class Frame
 * @brief
 */
class Frame
{

private:

	int id;
	int width;
	int height;
	ImageResource* bitmap;
	CollisionMask mask;

public:

	/**
	 * @brief
	 * @param _id
	 * @param w
	 * @param h
	 * @param _bitmap
	 */
	Frame( const int& _id, const int& w, const int& h, ImageResource* _bitmap );

	/**
	 * @brief
	 */
	virtual ~Frame();

	/**
	 * @brief
	 * @return
	 */
	operator ALLEGRO_BITMAP*() const;

	/**
	 * @brief
	 * @return
	 */
	const int& getId() const;

	/**
	 * @brief
	 * @return
	 */
	int getHeight() const;

	/**
	 * @brief
	 * @return
	 */
	int getWidth() const;

	const CollisionMask& getMask() const {
		return mask;
	}

};

} /* namespace */
