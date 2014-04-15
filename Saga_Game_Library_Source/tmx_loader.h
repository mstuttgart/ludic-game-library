#pragma once

#include "tmx_tile_set.h"
#include "tmx_layer.h"

#include <vector>
#include <map>

namespace sgl {
namespace image {

/**
 * @class TMXLoader
 * @author Michell Stuttgart
 * @date 04/14/14
 * @file tmx_loader.h
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
	inline int getColums() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getHeight() const;

	/**
	 * @brief
	 * @return
	 */
	inline const String& getOrientation() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getRows() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getTileHeight() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getTileWidth() const;

	/**
	 * @brief
	 * @return
	 */
	inline const std::vector<TMXLayer*>& getTmxLayers() const;

	/**
	 * @brief
	 * @return
	 */
	inline const std::vector<TMXTileSet*>& getTmxTilesets() const;

	/**
	 * @brief
	 * @return
	 */
	inline const std::map<String, String>& getProperties() const;

	/**
	 * @brief
	 * @return
	 */
	inline double getVersion() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getWidth() const;

};

//------------------------------------------------------------

int TMXLoader::getColums() const {
	return colums;
}

//------------------------------------------------

int TMXLoader::getHeight() const {
	return height;
}

//------------------------------------------------

const String& TMXLoader::getOrientation() const {
	return orientation;
}

//------------------------------------------------

int TMXLoader::getRows() const {
	return rows;
}

//------------------------------------------------

int TMXLoader::getTileHeight() const {
	return tileHeight;
}

//------------------------------------------------

int TMXLoader::getTileWidth() const {
	return tileWidth;
}

//------------------------------------------------

const std::vector<TMXLayer*>& TMXLoader::getTmxLayers() const {
	return tmx_layers;
}

//------------------------------------------------

const std::vector<TMXTileSet*>& TMXLoader::getTmxTilesets() const {
	return tmx_tilesets;
}

//------------------------------------------------
const std::map<String, String>& TMXLoader::getProperties() const {
	return properties;
}
//------------------------------------------------

double TMXLoader::getVersion() const {
	return version;
}

//------------------------------------------------

int TMXLoader::getWidth() const {
	return width;
}

//------------------------------------------------

}
} /* namespace */
