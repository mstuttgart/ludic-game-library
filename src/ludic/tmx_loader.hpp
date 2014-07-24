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

#include "tmx_tile_set.hpp"
#include "tmx_layer.hpp"

#include <vector>
#include <map>

namespace Ludic {

/**
 * @file tmx_loader.hpp
 * @author Michell Stuttgart
 * @date 04/14/14
 * @class TMXLoader
 * @brief
 */
class TMXLoader {

private:

	double version;
	String orientation;
	int rows;
	int colums;
	int width;
	int height;
	int tileWidth;
	int tileHeight;

	String file;

	TiXmlDocument doc;
	TiXmlNode* root;

	std::vector< TMXTileSet* > tmx_tilesets;
	std::vector< TMXLayer* >   tmx_layers;

	std::map< String, String > properties;

private:

	/**
	 * @brief
	 */
	void parseProperty();

	/**
	 * @brief
	 */
	void release();

public:

	/**
	 * @brief
	 */
	TMXLoader();

	/**
	 * @brief
	 * @param file
	 */
	TMXLoader( const String& file );

	/**
	 * @brief
	 */
	virtual ~TMXLoader();

	/**
	 * @brief
	 * @param file
	 * @return
	 */
	bool load( const String& file );

	/**
	 * @brief
	 */
	void parseTileset();

	/**
	 * @brief
	 */
	void parseLayers();

	/**
	 * @brief
	 * @return
	 */
	int getColums() const;

	/**
	 * @brief
	 * @return
	 */
	int getWidth() const;

	/**
	 * @brief
	 * @return
	 */
	int getHeight() const;

	/**
	 * @brief
	 * @return
	 */
	inline const String& getOrientation() const;

	/**
	 * @brief
	 * @return
	 */
	int getRows() const;

	/**
	 * @brief
	 * @return
	 */
	int getTileHeight() const;

	/**
	 * @brief
	 * @return
	 */
	int getTileWidth() const;

	/**
	 * @brief
	 * @return
	 */
	const std::vector<TMXLayer*>& getTmxLayers() const;

	/**
	 * @brief
	 * @return
	 */
	const std::vector<TMXTileSet*>& getTmxTilesets() const;

	/**
	 * @brief
	 * @return
	 */
	const std::map<String, String>& getProperties() const;


	/**
	 * @brief
	 * @return
	 */
	double getVersion() const;

};

} /* namespace */
