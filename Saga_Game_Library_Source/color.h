#pragma once

#include "sgl.h"
#include <allegro5/allegro_color.h>

namespace sgl
{

/**
 * @file color.h
 * @author Michell Stuttgart
 * @date 03/06/14
 * @class Color
 * @brief
 */
class Color
{

private:

	float r, g, b;

public:

	/**
	 * @brief
	 * @param red
	 * @param green
	 * @param blue
	 */
	Color( float red, float green, float blue );

	/**
	 * @brief
	 * @param html
	 */
	Color( const String& html );

	/**
	 * @brief
	 * @return
	 */
	String getName() const;

	/**
	 * @brief
	 * @return
	 */
	String toHTML() const;

	/**
	 * @brief
	 * @param r
	 * @param g
	 * @param b
	 */
	void toRGB( int& r, int& g, int& b );

	/**
	 * @brief
	 */
	operator ALLEGRO_COLOR();

};

} /* namespace */
