#pragma once

#include "bouding_box.h"
#include "tiled_layer.h"
#include "tmx_loader.h"

#include <memory>

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

	static std::unique_ptr<TileMap> ms_instance;

	int rows;
	int colums;
	int width;
	int height;
	int tileWidth;
	int tileHeight;
	String file;

	std::map<String, TiledLayer*> layers;
	std::map<String, TiledLayer*>::iterator itrL;

	std::map<String, TMXTileSet*> tilesets;
	std::map<String, TMXTileSet*>::iterator itrT;

	/**
	* @brief
	*/
	TileMap();


	/**
	 * @brief
	 * @param tmxFile
	 */
	bool load ( TMXLoader loader );


	/**
	 * @brief
	 * @param root
	 */
	void parse ( TiXmlNode* root, const String& source );

	/**
	 * @brief
	 * @param node
	 * @param tileset
	 * @return
	 */
	std::map<int, Tile*>* parseLayers( TiXmlNode* node );

public:

	/**
	 * @brief
	 * @param tmxFile
	 */
	virtual ~TileMap();

	/**
	 * @brief
	 * @param tmxFileName
	 * @return
	 */
	static TileMap* createTileMap ( const String& tmxFileName );

	/**
	 * @brief
	 */
	void scroll ( float desloc );

	/**
	 * @brief
	 * @param layerIdx
	 * @param x
	 * @param y
	 */
	void setPosition ( const Vector2D& vec );

	/**
	 * @brief
	 * @param velx
	 * @param vely
	 */
	void setLayerSpeed( const Vector2D& vec );

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
	int getTileId ( const Vector2D& vec );

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
	TiledLayer* getLayer ( const String& layerName );

	/**
	 * @brief
	 * @param tilesetName
	 * @return
	 */
	const TMXTileSet* getTileSet( const String& tilesetName );

	/**
	 * @brief
	 * @param layerName
	 * @return
	 */
	TiledLayer* removeLayer( const String& layerName );

	/**
	 * @brief
	 * @return
	 */
	inline int sizeLayers() const;

	/**
	 * @brief
	 * @return
	 */
	inline int sizeTilesets() const;

	/**
	 * @brief
	 * @param name
	 * @return
	 */
	bool hasLayer ( const String& name );

	/**
	 * @brief
	 * @param tilesetName
	 * @return
	 */
	bool hasTileSet( const String& tilesetName );

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

int TileMap::sizeLayers() const {
	return layers.size();
}

//---------------------------------------------
int TileMap::sizeTilesets() const {
	return tilesets.size();
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
