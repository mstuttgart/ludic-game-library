#pragma once

#include "sgl.h"

#include <vector>

namespace sgl {

/**
 * @file util.h
 * @author Michell Stuttgart
 * @date 02/20/14
 * @class Util
 * @brief
 */
class Util {

public:

	/**
	 * @brief
	 * @param value
	 * @return
	 */
	static int squarePow(int value);
	
	/**
	 * @brief 
	 * @param value
	 * @return 
	 */
	static int squareRoot(int value);
	
	/**
	 * @brief 
	 * @param strIn
	 * @param strOut
	 */
	static void decodeBase64( const String& strIn, String& strOut );
	
	/**
	 * @brief 
	 * @param source
	 * @param dest
	 */
	static void decompressZLIB( const String& strIn, String& strOut );

};
}
