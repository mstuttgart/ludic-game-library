#pragma once

#include "bouding_box.h"
#include "tile_set.h"
#include "tiled_layer.h"

namespace sgl {
namespace image {

/**
 * @file tile_map.h
 * @author Michell Stuttgart
 * @date 02/20/14
 * @class TileMap
 * @brief
 */
class TileMap {

private:

	static TileMap* instance;

	int rows;
	int colums;
	int width;
	int height;
	int tileWidth;
	int tileHeight;
	String file;

	std::map<std::string, TiledLayer*> layers;
	std::map<std::string, TiledLayer*>::iterator it;

	/**
	* @brief
	*/
	TileMap();

	/**
	 * @brief
	 * @param tmxFile
	 */
	virtual ~TileMap();


	/**
	 * @brief
	 * @param tmxFile
	 */
	bool load ( String& tmxFileName );


	/**
	 * @brief
	 * @param root
	 */
	void parse ( TiXmlNode* root, String& source );

	/**
	 * @brief
	 * @param node
	 * @param tileset
	 * @return
	 */
	std::map<int, Tile*>* parseLayers( TiXmlNode* node,
	                                   std::vector<TileSet*>& tileset );

public:

	/**
	 * @brief
	 * @param tmxFileName
	 * @return
	 */
	static TileMap* createTileMap ( String tmxFileName );

	/**
	 * @brief
	 */
	void scroll ( unsigned int dx, unsigned int dy );

	/**
	 * @brief
	 * @param layerIdx
	 * @param x
	 * @param y
	 */
	void setPosition ( int x, int y );

	/**
	 * @brief
	 * @param velx
	 * @param vely
	 */
	void setLayerSpeed( int velx, int vely );

	/**
	 * @brief
	 * @param layerName
	 */
	void setVisible ( bool visible );

	/**
	 * @brief
	 * @param x
	 * @param y
	 * @return
	 */
	int getTileId ( int x, int y );

	/**
	 * @brief
	 * @return
	 */
	inline const String& getMapName() const;

	/**
	* @brief
	* @return
	*/
	inline int getWidth() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getHeight() const;

	/**
	* @brief
	* @return
	*/
	inline int getColums() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getRows() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getTileWidth() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getTileHeight() const;

	/**
	 * @brief
	 * @param idx
	 * @return
	 */
	TiledLayer* getLayer ( String layerName );

	/**
	 * @brief
	 * @param layerName
	 * @return
	 */
	TiledLayer* removeLayer( String layerName );

	/**
	 * @brief
	 * @return
	 */
	inline int size();

	/**
	 * @brief
	 * @param name
	 * @return
	 */
	bool hasLayer ( String name );

	/**
	 * @brief
	 */
	static void destroyTileMap();

};

//---------------------------------------------

const String& TileMap::getMapName() const {
	return file;
}

//---------------------------------------------

int TileMap::size() {
	return layers.size();
}

//---------------------------------------------

int TileMap::getRows() const {
	return rows;
}

//---------------------------------------------

int TileMap::getColums() const {
	return colums;
}

//---------------------------------------------

int TileMap::getWidth() const {
	return width;
}

//---------------------------------------------

int TileMap::getHeight() const {
	return height;
}

//---------------------------------------------

int TileMap::getTileWidth() const {
	return tileWidth;
}

//---------------------------------------------

int TileMap::getTileHeight() const {
	return tileHeight;
}

//---------------------------------------------

}
} /* namespace */
