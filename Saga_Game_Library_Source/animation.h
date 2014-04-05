#pragma once

#include "sgl.h"
#include "image_resource.h"
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
	int frameW;
	int frameH;
	bool repeat;
	std::vector<ImageResource*> v_bitmaps;

	/**
	 * @brief
	 * @param baseImg
	 * @param v_index
	 * @param rows
	 * @param colums
	 */
	Animation( ImageResource* imgRsc, std::vector<int> &v_index,
	           unsigned int& rows, unsigned int& columns );

public:

	/**
	 * @brief
	 * @param imgRsc
	 * @param v_index
	 * @param rows
	 * @param columns
	 * @return
	 */
	static Animation* createAnimation( ImageResource* imgRsc, std::vector<int> &v_index,
	                                   unsigned int rows, unsigned int columns );


	static Animation* createAnimation( const char* fileName, std::vector<int> &v_index,
	                                   unsigned int rows, unsigned int columns );

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
	ImageResource* getCurrentFrame() const;

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
