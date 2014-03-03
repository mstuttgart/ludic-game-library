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
	virtual ~Layer() {};
	
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

