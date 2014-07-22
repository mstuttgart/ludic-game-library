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

#include "sprite.hpp"
#include "image_resource.hpp"
#include "collision_box.hpp"

#include <map>
#include <vector>

namespace Ludic
{

/**
 * @file static_sprite.hpp
 * @author Michell Stuttgart
 * @date 01/16/14
 * @class StaticSprite
 * @brief
 */
class StaticSprite : public Sprite
{

private:

	ImageResource*  imgRsc;
	ALLEGRO_BITMAP* bitmapAux;
	CollisionMask mask;

public:

	/**
	 * @brief
	 */
	StaticSprite();

	/**
	 * @brief
	 * @param fileName
	 */
	StaticSprite( const String& fileName );

	/**
	* @brief
	*/
	virtual ~StaticSprite() {};

	/**
	 * @brief
	 * @param fileName
	 * @return
	 */
	bool load( const String& fileName );

	/**
	 * @brief
	 * @return
	 */
	const ImageResource* getImageResource() const;

	/**
	 * @brief
	 * @return
	 */
	virtual float getWidth() const;


	/**
	 * @brief
	 * @return
	 */
	virtual float getHeight() const;

	/**
	 * @brief
	 */
	void draw();

	/**
	 * @brief
	 * @return
	 */
	virtual const CollisionMask& getMask() const;

};

} /* namespaces */
