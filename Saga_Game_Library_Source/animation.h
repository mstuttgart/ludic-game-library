#ifndef ANIMATION_H
#define ANIMATION_H

#include "sgl.h"
#include "image_resource.h"
#include <vector>

namespace sgl {

namespace image {

class Animation {

private:

	int frameW;
	int frameH;
	int currentFrame;
	bool repeat;
	bool ended;
	
	std::vector<ALLEGRO_BITMAP*> v_bitmap;
	
	/**
	 * @brief
	 * @param baseImg
	 * @param v_index
	 * @param rows
	 * @param colums
	 */
	Animation( ALLEGRO_BITMAP* bitmap, int* v_index, unsigned int& rows, unsigned int& columns );

public:	
	
	/**
	 * @brief 
	 * @param imgRsc
	 * @param v_index
	 * @param rows
	 * @param columns
	 * @return 
	 */
	static Animation* createAnimation(  ImageResource* imgRsc, int* v_index, unsigned int rows, unsigned int columns );

	/**
	 * @brief
	 */
	virtual ~Animation(){};


	/**
	 * @brief
	 */
	void nextFrame();

	/**
	 * @brief
	 * @return
	 */
	int getCurrentFrame() const;
	
	
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

	/**
	 * @brief
	 * @return
	 */
	bool isEnded();


	/**
	 * @brief
	 * @param x
	 * @param y
	 * @param mirror
	 */
	void draw( int& x, int& y, int& mirror );

};

}
} /* namespace */

#endif // ANIMATION_H
