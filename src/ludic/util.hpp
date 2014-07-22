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

#include "sgl.hpp"

namespace Ludic {

/**
 * @file util.hpp
 * @author Michell Stuttgart
 * @date 02/20/14
 * @class Util
 * @brief
 */
class Util {

public:

	/**
	 * @brief
	 * @param str
	 * @return
	 */
	static String toLower( const String& str );

	/**
	 * @brief
	 * @param str
	 * @return
	 */
	static String toUpper( const String& str );

	/**
	 * @brief
	 * @param strIn
	 * @param strOut
	 */
	static void decodeBase64( const String& strIn, String& strOut );

	/**
	 * @brief
	 * @param strIn
	 * @param strOut
	 */
	static void decompressZLIB( const String& strIn, String& strOut );

	/**
	 * @brief
	 * @param strIn
	 * @param strOut
	 */
	static void decompressGZIP( const String& strIn, String& strOut );

	/**
	 * @brief
	 * @param value
	 * @return
	 */
	static float ceilFloat( float value );

	/**
	 * @brief
	 * @param value
	 * @return
	 */
	static float floorFloat( float value );

};
}
