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
#include "tmx_tile_set.hpp"
#include "tmx_layer.hpp"
#include "frame.hpp"

#include <vector>

namespace Ludic
{


/**
 * @file animation.hpp
 * @author Michell Stuttgart
 * @date 01/24/14
 * @class Animation
 * @brief The animation class is the base of AnimatedSprite class. Each 
 * instance of this class have a sequence of Frame class objects used to
 * create a animated sequence. This is the use intern of AnimatedSprite Class.
 */
class Animation
{

private:

	unsigned int currentFrame;
	bool repeat;
	std::vector<Frame*> frames;
	String label;

public:

	/**
	 * @brief Parameter Contrutor. This construtor is to intern use for Ludic Library.
	 * @param data Vector of DataInfo. 
	 * @param baseImages base images used in tileset.
	 * @param tmxTileset the tilesets privide in tmx file.
	 * @param _label the label of animation.
	 */
	Animation( const std::vector< TMXTileSet* >& tmxTileset,
	           const std::vector< TMXLayer::DataInfo >& data,
	           ImageResource* baseImages[], const String& _label );


	/**
	 * @brief Default destrutor
	 */
	virtual ~Animation();

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
	void previusFrame();

	/**
	 * @brief Return the current index of frame sequence.
	 * @return The index of currente frame.
	 */
	int getCurrentFrameIndex() const;

	/**
	* @brief Return the currente Frame object of animation sequence.
	* @return The pointer to current Frame object.
	*/
	const Frame* getCurrentFrame() const;

	/**
	* @brief Return the current frame width.
	* @return The frame width. 
	*/
	int getFrameWidth() const;

	/**
	 * @brief Return the current frame height.
	 * @return The frame height
	 */
	int getFrameHeight() const;

	/**
	 * @brief Return the label of animation. This label must be define in tmx file.
	 * @return The string with label of this animation.
	 */
	const String& getLabel() const;

	/**
	 * @brief Reset animation, i.e, the animation back to begin with index value equal a 0.
	 */
	void reset();

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
	void setRepeat( bool repeat );

	/**
	 * @brief Verify if animation work in loop.
	 * @return True is the animation run in loop, False otherwise.
	 */
	bool isRepeat();

	/**
	 * @brief Return the lenght of animation, i.e, the number of frames
	 * in the animation sequence.
	 * @return The mount of frames.
	 */
	int lenght() const;

};

}
