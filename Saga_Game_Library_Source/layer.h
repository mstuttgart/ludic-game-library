#pragma once

#include "sgl.h"

namespace sgl {
namespace image {

/**
 * @file layer.h
 * @author Michell Stuttgart
 * @date 01/24/14
 * @class Layer
 * @brief
 */
class Layer {

private:

	int x, y;
	bool visible;

protected:

	/**
	* @brief
	* @param dx
	* @param dy
	*/
	virtual void setPosition( int& x, int& y );

	/**
	 * @brief
	 * @param dx
	 * @param dy
	 */
	virtual void move( int& dx, int& dy );

public:

	/**
	 * @brief
	 */
	Layer();

	/**
	 * @brief
	 * @return
	 */
	virtual ~Layer() {};

	/**
	 * @brief
	 * @return
	 */
	inline int getX() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getY() const;
	
	/**
	* @brief
	* @param visible
	*/
	void setVisible( bool visible );

	/**
	 * @brief
	 * @return
	 */
	inline bool isVisible() const;

	/**
	 * @brief
	 */
	virtual void draw() = 0;

};

//==========================================================

int Layer::getX() const {
	return x;
}

//-----------------------------------------------------------

int Layer::getY() const {
	return y;
}

//-----------------------------------------------------------

bool Layer::isVisible() const {
	return visible;
}

//----------------------------------------------------------

}
} /* namespace */
