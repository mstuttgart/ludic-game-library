#pragma once

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
class Layer {

protected:
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
	 * @param flag
	 */
	void setFlip( FLIP flag );


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

