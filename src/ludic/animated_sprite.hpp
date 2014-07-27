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

namespace Ludic
{

/**
 * @file animated_sprite.hpp
 * @author Michell Stuttgart
 * @date 01/24/14
 * @class AnimatedSprite
 * @brief Class that represents an animated sprite.
 *
 * Allows charging of a tmx file containing the sprite animation settings.
 * Should be used when you want to creatultimoe a sprite with support for
 * animations. The class also allows checking collisions using rectangles
 * and collision per pixel.
 *
 */
class AnimatedSprite : public Sprite
{

private:

	std::map<String, Animation*> animationMap;
	std::map<String, Animation*>::iterator it;

	Animation* currentAnimation;

protected:

	/**
	 * @brief Desallocates all content allocated by the class.
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
	 * @brief Default Construtor.
	 */
	AnimatedSprite();

	/**
	 * @brief Parameter construtor.
	 * Receive the name of the tmx file that contains
	 * the settings of the animated sprite.
	 * @param The name of the tmx file.
	 */
	AnimatedSprite( const String& file );

	/**
	 * @brief Default Destrutor.
	 */
	virtual ~AnimatedSprite();

	/**
	 * @brief Performs loading a tmx file.
	 * The tmx file containing the configuration of
	 * the sprite animations.
	 * @param The name of the tmx file.
	 * @return True if the upload was successful, otherwise False.
	 */
	bool load( const String& file );

	/**
	 * @brief Set de current Animation.
	 * This animation will be drawn on the display. The label parameter
	 * is the name of the layer that is the animation in tmx file.
	 * @param The label of animation.
	 */
	void setCurrentAnimation( const String& label );

	/**
	 * @brief Returns the current animation.
	 * @return The poniter to current Animation.
	 */
	const Animation* getCurrentAnimation() const;

	/**
	 * @brief Returns the current Animatio label.
	 * @return The string with the label of current Animation Object.
	 */
	const String& getCurrentAnimationLabel() const;

	/**
	 * @brief Adjust the repeat of the current animation. 
	 * Indicates whether the current animation will be 
	 * restarted when you reach the end, or if the work in 
	 * question anaimação loop. If you choose not to repeat 
	 * the animation will stop on its last frame.
	 * @param repeat True if the animation run in loop, False otherwise.
	 * The default value is True.
	 * 
	 */
	void setRepeatAnimation( bool repeat );

	/**
	 * @brief Checks if there is an animation with the label passed with parameter.
	 * @param label The label of animation.
	 * @return True if the animaetion exist, False otherwise.
	 */
	bool hasAnimation( const String& label );

	/**
	 * @brief Returns the width of current frame of current Animation.
	 * @return The value of width of frame.
	 */
	virtual float getWidth() const;

	/**
	 * @brief Returns the height of current frame of current Animation
	 * @return The value of height of frame.
	 */
	virtual float getHeight() const;

	/**
	 * @brief Draws the frame of the current animation on the display.
	 *
	 * The animated sprite must be visible to be rendered on the screen.
	 */
	virtual void draw();

	/**
	 * @brief Selects the next frame in the frame sequence of the current animation.
	 *
	 * The frame sequence is considered a loop. If nextFrame() is
	 * called when at the end of the sequence, this method will advance
	 * to the first entry in the sequence.
	 * To prevent the animation function in loop, you must set to
	 * False the setRepeat () method of the object in animation.
	 */

	void nextFrame();

	/**
	 * @brief Selects the previous frame in the frame sequence of the current animation.
	 *
	 * The frame sequence is considered a loop. If previousFrame() is
	 * called when at the begin of the sequence, this method will advance
	 * to the last entry in the sequence.
	 * To prevent the animation function in loop, you must set to
	 * False the setRepeat () method of the object in animation.
	 */
	void previousFrame();

	/**
	 * @brief Return the mount of animations.
	 * @return The number of animation in the animationMap.
	 */
	int size();

	/**
	 * @brief Returns the mask of the current frame. 
	 * Ued to check for pixel collision.
	 * @return Return the pixel Mask Objects of current Frame.
	 */
	virtual const CollisionMask& getMask() const;

};

} /* namespace */
