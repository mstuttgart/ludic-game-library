/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is a FREE SOFTWARE released under the BSD License.              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "ludic.hpp"

namespace Ludic
{

/**
 * @file color.hpp
 * @author Michell Stuttgart
 * @date 03/06/14
 * @class Color
 * @brief Represents a ALLEGRO_COLOR like object.
 * 
 * class allows you to create colors using the RGB system 
 * or by hexadecimal notation in the HTML colors used, 
 * or the format "#EE22BB", for example.
 * 
 */
class Color
{

private:

	unsigned char red;
	unsigned char green;
	unsigned char blue;

public:

	/** 
	* @brief default Contructor
	*
	*/
	Color();

	/**
	 * @brief Criate a color using RGB format color.
	 * Only values between 0 and 255 are valids for the three parameters red, green, blue.
	 *
	 * @param red The value of red color component. 
	 * @param green The value of green color component.
	 * @param blue The value of blur color component.
	 */
	Color( unsigned char _red, unsigned char _green, unsigned char _blue );

	/**
	 * @brief  Criate a color using the classic web' notation.
	 * @param html The string containing the hexadecimal code representing the colors.
	 */
	Color( const String& html );

	/**
	 * @brief Set the color using the RGB color format.
	 * Only values between 0 and 255 are valids for the three parameters red, green, blue.
	 *
	 * @param red The new value of red color component.
	 * @param green The new value of green color component.
	 * @param blue The new value of blue color component.
	 */
	void setRGB( unsigned char red, unsigned char green, unsigned char blue );

	/**
	 * @brief Return the name of color. For example, "darkgreen", "cyan" and etc.
	 * @return A string containing the name of color.
	 */
	String getName() const;

	/**
	 * @brief Convert the actual RGB values of Color to HTML web notation.
	 * @return A string containing the color in HTML web notation.
	 */
	String toHTML() const;

	/**
	 * @brief Get ou convert Color to RGB color format.
	 * 
	 * @param r The variable will receive a red color component of Color object.
	 * @param g The variable will receive a green color component of Color object.
	 * @param b The variable will receive a blue color component of Color object.
	 */
	void toRGB( unsigned char& red, unsigned char& green, unsigned char& blue );

	/**
	 * @brief 
	 * Internal use: It automatically convert an object of type color to an 
	 * object of type ALLEGRO_COLOR. This conversion is automatic when it expects 
	 * ALLEGRO_COLOR object and should not be stressed in any way.
	 * @return The ALLEGRO_COLOR pointer.
	 */
	operator ALLEGRO_COLOR() const;

};

} /* namespace */
