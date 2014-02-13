#ifndef _SGL_SURFACE_
#define _SGL_SURFACE_

#include "sgl.h"

namespace sgl {

namespace image {

enum class FLIP {
	NONE    = 0,
    H_FLIP  = ALLEGRO_FLIP_HORIZONTAL,
    V_FLIP  = ALLEGRO_FLIP_VERTICAL,
	HV_FLIP = ALLEGRO_FLIP_HORIZONTAL | ALLEGRO_FLIP_VERTICAL
};

/**
 * @file layer.h
 * @author Michell Stuttgart
 * @date 01/24/14
 * @class Layer
 * @brief
 */
class Surface {

private:

	int x;
	int y;
	int flip;
	bool visible;

protected:

	/**
	 * @brief
	 * @return
	 */
	int getFlip() const;

public:

	/**
	 * @brief
	 */
	Surface();


	/**
	 * @brief
	 * @return
	 */
	virtual ~Surface() {};

	/**
	 * @brief
	 * @param dx
	 * @param dy
	 */
	void setPosition( int x, int y );

	/**
	 * @brief
	 * @return
	 */
	int getX() const;

	/**
	 * @brief
	 * @return
	 */
	int getY() const;


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
	 * @param flag
	 */
	void setFlip( FLIP flag );


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
