/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is FREE SOFTWARE released under the BSD License.                //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "font_resource.hpp"
#include "vector2_d.hpp"
#include "color.hpp"
#include "collision_box.hpp"

namespace Ludic {

enum class FontAlignment : std::uint8_t {
    LEFT    = ALLEGRO_ALIGN_LEFT,
    CENTRE  = ALLEGRO_ALIGN_CENTRE,
    RIGHT   = ALLEGRO_ALIGN_RIGHT,
    INTEGER = ALLEGRO_ALIGN_INTEGER
};

/**
 * @file font.h
 * @author Paulo Vicente
 * @date 02/22/14
 * @class Font
 * @brief
 */
class Font {

private:

	FontResource* fontResource;
	FontAlignment alignment;
	Vector2D position;
	String text;
	Color color;

public:

	Font();

	/**
	 * @brief
	 * @param fileName
	 * @param fontSize
	 */
	Font( const String& fileName, unsigned int fontSize );

	/**
	 * @brief
	 */
	virtual ~Font();

	/**
	 * @brief
	 * @param fileName
	 * @param fontSize
	 * @return
	 */
	bool load( const String& fileName, unsigned int fontSize );

	/**
	 * @brief
	 */
	void drawText();

	/**
	 * @brief
	 * @param color
	 */
	void setColorFont( const Color& color );

	/**
	 * @brief
	 * @param position
	 */
	void setPosition ( const Vector2D& position );

	/**
	 * @brief
	 * @param usrText
	 */
	void setText ( const String& usrText );

	/**
	 * @brief
	 * @param align
	 */
	void setAlignment( FontAlignment align );

	/**
	 * @brief
	 * @return
	 */
	int getTextWidth() const;

	/**
	 * @brief
	 * @param strText
	 * @return
	 */
	int getTextWidth( const String& strText ) const;

	/**
	 * @brief
	 * @return
	 */
	int getLineHeight() const;

	/**
	 * @brief
	 * @return
	 */
	CollisionBox getTextDimension();

	/**
	 * @brief
	 * @param str
	 * @return
	 */
	CollisionBox getTextDimension( const String& str );

	/**
	 * @brief
	 * @return
	 */
	const FontAlignment& getAlignment() const;

	/**
	 * @brief
	 * @return
	 */
	const Color& getColor() const;

	/**
	 * @brief
	 * @return
	 */
	const FontResource* getFontResource();

	/**
	 * @brief
	 * @return
	 */
	const Vector2D& getPosition() const;

	/**
	 * @brief
	 * @return
	 */
	const String& getText() const;

};

} /* namespaces */
