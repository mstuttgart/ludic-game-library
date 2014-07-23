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

#include "resource.hpp"

namespace Ludic {

/**
 * @file font_resource.hpp
 * @author Paulo Vicente
 * @date 02/22/14
 * @class FontResource
 * @brief
 */
class FontResource : public Resource {

private:

	unsigned int rscSize;

protected:

	/**
	 * @brief
	 * @param fileName
	 * @param font
	 * @param fSize
	 */
	FontResource( const String& fileName, ALLEGRO_FONT* font, unsigned int fSize );

	/**
	 * @brief
	 */
	virtual ~FontResource();

	/**
	 * @brief
	 * @return
	 */
	ALLEGRO_FONT* getFontPtr();

public:

	/**
	 * @brief
	 * @param fileName
	 * @param fontSize
	 * @return
	 */
	static FontResource* createFontResource(
	    const String& fileName, unsigned int fontSize );

	/**
	 * @brief
	 * @return
	 */
	unsigned int getSizeResource();

	/**
	 * @brief
	 * @return
	 */
	operator ALLEGRO_FONT*();

};

} //end namespaces
