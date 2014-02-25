#pragma once

#include "animation.h"
#include "sprite.h"

#include <map>

namespace sgl {
namespace image {

/**
 * @file sprite.h
 * @author Michell Stuttgart
 * @date 01/24/14
 * @class Sprite
 * @brief
 */
class AnimatedSprite : public Sprite{

private:

	std::map<int, Animation*> animationMap;
	std::map<int, Animation*>::iterator it;

	Animation* currentAnimation;

public:

	/**
	 * @brief
	 */
	AnimatedSprite();

	/**
	 * @brief
	 */
	virtual ~AnimatedSprite();

	/**
	 * @brief
	 * @param animationIndex
	 * @param anim
	 */
	void addAnimation( int animationIndex, Animation* anim );

	/**
	* @brief
	* @param animationIndex
	*/
	bool removeAnimation( int animationIndex );

	/**
	 * @brief
	 * @param animationIndex
	 */
	void setCurrentAnimation( int animationIndex );

	/**
	 * @brief
	 * @param animationIndex
	 * @return
	 */
	bool isAnimationPresent( int animationIndex );

	/**
	 * @brief
	 * @return
	 */
	virtual int getWidth();

	/**
	 * @brief
	 * @return
	 */
	virtual int getHeight();

	/**
	 * @brief
	 */
	virtual void draw();

	/**
	 * @brief
	 */
	void nextFrame();

};

}
} /* namespace */
