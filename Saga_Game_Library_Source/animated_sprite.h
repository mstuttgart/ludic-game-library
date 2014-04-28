#pragma once

#include "animation.h"
#include "sprite.h"
#include "tmx_loader.h"

#include <map>
#include <vector>

namespace sgl {
namespace image {

/**
 * @file sprite.h
 * @author Michell Stuttgart
 * @date 01/24/14
 * @class Sprite
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
	 * @param animationIndex
	 */
	void setCurrentAnimation( const String& label );

	/**
	 * @brief
	 * @param animationIndex
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

};

}
} /* namespace */
