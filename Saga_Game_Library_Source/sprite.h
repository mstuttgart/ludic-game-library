#ifndef _SGL_SPRITE_
#define _SGL_SPRITE_

#include "layer.h" // Base class: sgl::image::Layer
#include "animation.h"
#include "image_resource.h"

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
class Sprite : public Layer {

private:

	std::map<int, Animation*> animationMap;
	std::map<int, Animation*>::iterator it;

	Animation* currentAnimation;

public:

	/**
	 * @brief
	 */
	Sprite();

	/**
	 * @brief
	 */
	virtual ~Sprite();

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

};

}
} /* namespace */

#endif // _SGL_SPRITE_
