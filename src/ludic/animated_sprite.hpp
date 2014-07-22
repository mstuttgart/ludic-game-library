/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos			           //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is a FREE SOFTWARE released under the BSD License.              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "animation.hpp"
#include "sprite.hpp"
#include "tmx_loader.hpp"

#include <map>
#include <vector>

namespace Ludic {

/**
 * @file animated_sprite.hpp
 * @author Michell Stuttgart
 * @date 01/24/14
 * @class AnimatedSprite
 * @brief
 */
class AnimatedSprite : public Sprite {

private:

	std::map<String, Animation*> animationMap;
	std::map<String, Animation*>::iterator it;

	Animation* currentAnimation;

protected:

	/**
	 * @brief
	 */
	virtual void release();

private:

	/**
	 * @brief
	 * @param loader
	 */
	void initAnimations( const TMXLoader& loader );

public:

	/**
	 * @brief
	 */
	AnimatedSprite();

	/**
	 * @brief
	 * @param file
	 */
	AnimatedSprite( const String& file );

	/**
	 * @brief
	 */
	virtual ~AnimatedSprite();

	/**
	 * @brief
	 * @param file
	 * @return
	 */
	bool load( const String& file );

	/**
	 * @brief
	 * @param label
	 */
	void setCurrentAnimation( const String& label );

	/**
	 * @brief
	 * @param label
	 * @return
	 */
	bool hasAnimation( const String& label );

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
	virtual void draw();

	/**
	 * @brief
	 */
	void nextFrame();

	/**
	 * @brief
	 * @return
	 */
	int size();

	/**
	 * @brief
	 * @return
	 */
	virtual const CollisionMask& getMask() const;

};

} /* namespace */
