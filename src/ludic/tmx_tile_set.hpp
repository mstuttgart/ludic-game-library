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
#include "vector2_d.hpp"

#include "../tinyxml/tinyxml.h"

namespace Ludic {

/**
 * @file tmx_tile_set.hpp
 * @author Michell Stuttgart
 * @date 02/16/14
 * @class TMXTileSet
 * @brief
 */
class TMXTileSet {

private:

	String name;
	String source;
	String colorkey;
	unsigned firstGid;
	unsigned lastGid;
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
	 */
	virtual ~TMXTileSet() {};

	/**
	 * @brief
	 * @param node
	 * @param tmxFile
	 */
	void parse( TiXmlNode* node, const String& tmxFile );

	/**
	 * @brief
	 * @return
	 */
	const unsigned int& getFirstGid() const;

	/**
	 * @brief
	 * @return
	 */
	const unsigned int& getLastGid() const;

	/**
	 * @brief
	 * @return
	 */
	const int& getWidth() const ;

	/**
	 * @brief
	 * @return
	 */
	const int& getHeight() const;

	/**
	 * @brief
	 * @return
	 */
	const int& getRows() const;

	/**
	 * @brief
	 * @return
	 */
	const int& getColums() const;

	/**
	 * @brief
	 * @return
	 */
	const String& getName() const;

	/**
	 * @brief
	 * @return
	 */
	const String& getSource() const;

	/**
	 * @brief
	 * @return
	 */
	const int& getTileHeight() const;

	/**
	 * @brief
	 * @return
	 */
	const int& getTileWidth() const;

	/**
	 * @brief
	 * @return
	 */
	const String& getColorkey() const;

	/**
	 * @brief
	 * @return
	 */
	int getMargin() const;

	/**
	 * @brief
	 * @return
	 */
	const Vector2D& getOffset() const;

	/**
	 * @brief
	 * @return
	 */
	int getSpacing() const;

};

} /* namespace */
