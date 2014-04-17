#pragma once

#include "font_resource.h"
#include "vector2_d.h"
#include "color.h"
#include "bouding_box.h"

namespace sgl {
namespace font {

enum class FontAlignament : std::uint8_t {
    LEFT    = ALLEGRO_ALIGN_LEFT,
    CENTRE  = ALLEGRO_ALIGN_CENTRE,
    RIGHT   = ALLEGRO_ALIGN_RIGHT,
    INTEGER = ALLEGRO_ALIGN_INTEGER
};

/**
 * @file Font.h
 * @author Paulo Vicente
 * @date 02/22/14
 * @class Font
 * @brief
 */
class Font {

private:

	FontResource* fontResource;
	FontAlignament alignment;
	Vector2D position;
	String file;
	String text;
	Color color;

public:

	/**
	 * @brief
	 * @param fileName
	 * @param fontSize
	 */
	Font( const String& fileName, unsigned int fontSize );

	/**
	 * @brief
	 * @param rsc
	 */
	Font( FontResource* rsc );

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
	void setAlignment( FontAlignament align );

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
	BoundingBox getTextDimension();

	/**
	 * @brief
	 * @param str
	 * @return
	 */
	BoundingBox getTextDimension( const String& str );

	/**
	 * @brief 
	 * @return 
	 */
	const FontAlignament& getAlignment() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	const Color& getColor() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	const String& getFile() const;
	
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


}
} /* namespaces */
