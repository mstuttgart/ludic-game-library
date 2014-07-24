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

namespace Ludic {


/**
 * @file animation.hpp
 * @author Michell Stuttgart
 * @date 01/24/14
 * @class Animation
 * @brief
 */
class Animation {

private:

	unsigned int currentFrame;
	bool repeat;
	std::vector<Frame*> frames;

public:

	/**
	 * @brief
	 * @param data
	 * @param baseImages
	 * @param tmxTileset
	 */
	Animation( const std::vector< TMXTileSet* >& tmxTileset,
				const std::vector< TMXLayer::DataInfo >& data,
				ImageResource* baseImages[] );


	/**
	 * @brief
	 */
	virtual ~Animation();

	/**
	 * @brief
	 */
	void nextFrame();

	/**
	 * @brief
	 */
	void previusFrame();

	/**
	 * @brief
	 * @return
	 */
	int getCurrentFrameIndex() const;

	/**
	* @brief
	* @return
	*/
	Frame* getCurrentFrame() const;

	/**
	* @brief
	* @return
	*/
	int getFrameWidth() const;

	/**
	 * @brief
	 * @return
	 */
	int getFrameHeight() const;

	/**
	 * @brief
	 */
	void resetAnimation();

	/**
	 * @brief
	 * @param repeat
	 */
	void setRepeat( bool repeat );

	/**
	 * @brief
	 * @return
	 */
	bool isRepeat();

	/**
	 * @brief
	 * @return
	 */
	int lenght() const;

};

}
