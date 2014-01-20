#ifndef _SGL_LAYER_
#define _SGL_LAYER_

#include "SGL.h"

namespace sgl {

namespace image {

class Layer {

private:

	int x;
	int y;
	bool visible;


public:

	/**
	 * @brief 
	 */
	Layer();
	
	
	/**
	 * @brief 
	 * @return 
	 */
	virtual ~Layer(){};
	
	/**
	 * @brief 
	 * @param dx
	 * @param dy
	 */
	void setPosition( int x, int y );
	
	/**
	 * @brief 
	 * @param dx
	 * @param dy
	 */
	void move( int dx, int dy );
	
	/**
	 * @brief 
	 * @param visible
	 */
	void setVisible( bool visible );
	
	
	/**
	 * @brief 
	 * @return 
	 */
	bool isVisible() const;
	
	
	/**
	 * @brief 
	 * @return 
	 */
	virtual int getWidth() = 0;
	
	
	/**
	 * @brief 
	 * @return 
	 */
	virtual int getHeight() = 0;
	
	
	/**
	 * @brief 
	 */
	virtual void draw() = 0;

};

}
} /* namespace */

#endif // _SGL_LAYER_
