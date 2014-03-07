#pragma once

#include <allegro5/allegro_color.h>

namespace sgl {

/**
 * @file color.h
 * @author Michell Stuttgart
 * @date 03/06/14 
 * @class Color
 * @brief 
 */
class Color {

public:

	/**
	 * @brief 
	 * @param html
	 * @return 
	 */
	static ALLEGRO_COLOR getColorOf_HTML( char const* html );

	/**
	 * @brief 
	 * @param r
	 * @param g
	 * @param b
	 * @return 
	 */
	static ALLEGRO_COLOR getColorOf_RGB( char r, char g, char b );

	/**
	 * @brief 
	 * @param name
	 * @return 
	 */
	static ALLEGRO_COLOR getColorOf_Name( char const* name );

	/**
	 * @brief 
	 * @param name
	 * @param r
	 * @param g
	 * @param b
	 * @return 
	 */
	static bool convert_Name_To_RGB( char const *name,
	                                 float *r, float *g, float *b );
	/**
	 * @brief 
	 * @param html
	 * @param r
	 * @param g
	 * @param b
	 */
	static void convert_HTML_To_RGB( char const* html,
	                                 float *r, float *g, float *b );
	
	/**
	 * @brief 
	 * @param r
	 * @param g
	 * @param b
	 * @return 
	 */
	static char const* convert_RGB_To_HTML( float r, float g, float b );
	
	/**
	 * @brief 
	 * @param name
	 * @return 
	 */
	static char const* convert_Name_To_HTML( char const *name );

	/**
	 * @brief 
	 * @param r
	 * @param g
	 * @param b
	 * @return 
	 */
	static char const* convert_RGB_To_Name( float r, float g, float b );
	
	/**
	 * @brief 
	 * @param html
	 * @return 
	 */
	static char const* convert_HTML_To_Name( char const* html );

};

} /* namespace */
