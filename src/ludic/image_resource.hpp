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

#include "resource.hpp" // Base class: sgl::Resource
#include "color.hpp"

namespace Ludic {

/**
 * @file image_resource.hpp
 * @author Michell Stuttgart
 * @date 01/16/14
 * @class ImageResource
 * @brief
 */
class ImageResource : public Resource {

private:

	 Color colorkey;

private:

	/**
	 * @brief
	 */
	ImageResource( const String& fileName, ALLEGRO_BITMAP* bitmap );


	/**
	 * @brief
	 * @return
	 */
	ALLEGRO_BITMAP* getBitmap();

public:

	/**
	 * @brief
	 */
	virtual ~ImageResource();

	/**
	 * @brief
	 * @return
	 */
	static ImageResource* createImageResource( const String& label, int width, int height );

	/**
	 * @brief
	 * @return
	 */
	static ImageResource* loadImageResource( const String& fileName );

	/**
	 * @brief
	 * @param rsc
	 * @param x
	 * @param y
	 * @param w
	 * @param h
	 * @return
	 */
	ImageResource* getSubImageResource( int x, int y, int w, int h );

	/**
	 * @brief
	 * @param colorkey
	 */
	void setColorKey( const Color& colorkey );

	/**
	 * @brief
	 */
	void setAsTarger();

	/**
	 * @brief
	 * @return
	 */
	operator ALLEGRO_BITMAP*();

};

} /* namespaces */
