#pragma once

#include "sgl.h"
#include "vector2_d.h"

#include "tinyxml/tinyxml.h"

namespace sgl {
namespace image {

/**
 * @file tile_set.h
 * @author Michell Stuttgart
 * @date 02/16/14
 * @class TileSet
 * @brief
 */
class TMXTileSet {

private:

	String name;
	String source;
	String colorkey;
	int firstGid;
	int lastGid;
	int rows;
	int colums;
	int width;
	int height;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	Vector2D offset;

public:

	/**
	 * @brief
	 */
	TMXTileSet();


	/**
	 * @brief
	 * @param node
	 */
	virtual ~TMXTileSet() {};

	/**
	 * @brief
	 * @param node
	 */
	void parse( TiXmlNode* node, const String& tmxFile );

	/**
	 * @brief
	 * @return
	 */
	inline const int& getFirstGid() const;

	/**
	 * @brief
	 * @return
	 */
	inline const int& getLastGid() const;

	/**
	 * @brief
	 * @return
	 */
	inline const int& getWidth() const ;

	/**
	 * @brief
	 * @return
	 */
	inline const int& getHeight() const;

	/**
	 * @brief
	 * @return
	 */
	inline const int& getRows() const;

	/**
	 * @brief
	 * @return
	 */
	inline const int& getColums() const;

	/**
	 * @brief
	 * @return
	 */
	inline const String& getName() const;

	/**
	 * @brief
	 * @return
	 */
	inline const String& getSource() const;

	/**
	 * @brief
	 * @return
	 */
	inline const int& getTileHeight() const;

	/**
	 * @brief
	 * @return
	 */
	inline const int& getTileWidth() const;

	/**
	 * @brief 
	 * @return 
	 */
	inline const String& getColorkey() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	inline int getMargin() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	inline const Vector2D& getOffset() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	inline int getSpacing() const;

};

//==========================================================
// Implementacao inline dos metodos get

const int& TMXTileSet::getFirstGid() const {
	return firstGid;
}

//-----------------------------------------------------------

const int& TMXTileSet::getLastGid() const {
	return lastGid;
}

//-----------------------------------------------------------

const int& TMXTileSet::getWidth() const {
	return width;
}

//-----------------------------------------------------------

const int& TMXTileSet::getHeight() const {
	return height;
}

//-----------------------------------------------------------

const int& TMXTileSet::getRows() const {
	return rows;
}

//-----------------------------------------------------------

const int& TMXTileSet::getColums() const {
	return colums;
}

//-----------------------------------------------------------

const String& TMXTileSet::getName() const {
	return name;
}

//-----------------------------------------------------------

const String& TMXTileSet::getSource() const {
	return source;
}

//-----------------------------------------------------------

const int& TMXTileSet::getTileHeight() const {
	return tileHeight;
}

//-----------------------------------------------------------

const int& TMXTileSet::getTileWidth() const {
	return tileWidth;
}

//-----------------------------------------------------------
const String& TMXTileSet::getColorkey() const {
	return colorkey;
}

//-----------------------------------------------------------

int TMXTileSet::getMargin() const {
	return margin;
}

//-----------------------------------------------------------

const Vector2D& TMXTileSet::getOffset() const {
	return offset;
}

//-----------------------------------------------------------

int TMXTileSet::getSpacing() const {
	return spacing;
}

//-----------------------------------------------------------

}
} /* namespace */
