#pragma once

#include "sgl.h"
#include "image_resource.h"
#include "tmx_tile_set.h"
#include "frame.h"

#include <vector>

namespace sgl {
namespace image {

/**
 * @file animation.h
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
	Animation( const std::vector< int >& data, ImageResource* baseImages[],
				const std::vector< TMXTileSet* >& tmxTileset );


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
	int getFrameAmount() const;

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

};

}
} /* namespace */
