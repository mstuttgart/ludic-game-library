#ifndef ANIMATION_H
#define ANIMATION_H

#include "SGL.h"
#include "Image.h"
#include <vector>

namespace sgl {

namespace image {

class Animation {

private:
	
	unsigned int currentFrame;	
	bool repeat;
	bool ended;
	
	std::vector<ALLEGRO_BITMAP*> v_bitmap;
	
public:

	/**
	 * @brief 
	 * @param baseImg
	 * @param v_index
	 * @param rows
	 * @param colums
	 */
	Animation( Image* baseImg, int* v_index, int rows, int colums );
	
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
