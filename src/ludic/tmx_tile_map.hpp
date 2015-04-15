#pragma once

#include "bouding_box.hpp"
#include "tiled_layer.hpp"
#include "tmx_loader.hpp"
#include "vector2_d.hpp"

namespace sgl {
namespace image {

/**
 * @file tmx_tile_map.h
 * @author Michell Stuttgart
 * @date 04/14/14
 * @class TMXTileMap
 * @brief
 */
class TMXTileMap {

private:

	int rows;
	int colums;
	int width;
	int height;
	int tileWidth;
	int tileHeight;

	std::map<String, TiledLayer*> tiledLayers;
	std::map<String, TiledLayer*>::iterator itrL;

private:

	/**
	 * @brief
	 * @param loader
	 */
	void initTilesLayers( const TMXLoader& loader );

public:

	/**
	 * @brief
	 */
	TMXTileMap();

	/**
	 * @brief
	 */
	virtual ~TMXTileMap();

	/**
	 * @brief
	 * @param file
	 * @return
	 */
	bool load( const String& file );

	/**
	 * @brief
	 * @param loader
	 * @return
	 */
	bool load( TMXLoader* loader );


	/**
	 * @brief
	 * @param spr
	 * @param movX
	 * @param movY
	 * @param layerName
	 * @param tileId
	 * @return
	 */
	bool checkCollision ( const Sprite& spr, int movX, int movY,
	                      const String& layerName, int tileId );

	/**
	 * @brief
	 * @param desloc
	 */
	void scroll ( float desloc );

	/**
	 * @brief
	 * @param layerName
	 * @param vec
	 */
	void setScrollVelocity ( const String& layerName, const Vector2D& vel );

	/**
	 * @brief
	 * @param pos
	 */
	void setPosition ( const Vector2D& pos );

	/**
	 * @brief
	 * @param displayW
	 * @param displayH
	 */
	void setScreenDimension( int displayW, int displayH );

	/**
	 * @brief
	 * @param visible
	 */
	void setVisible ( bool visible );

	/**
	 * @brief
	 * @param position
	 * @return
	 */
	int getTileId ( const Vector2D& position );

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
	 * @param layerName
	 * @return
	 */
	TiledLayer* getLayer ( const String& layerName );

	/**
	 * @brief
	 * @param layerName
	 */
	void drawLayer ( const String& layerName );

	/**
	 * @brief
	 * @return
	 */
	inline int sizeLayers();

	/**
	 * @brief
	 * @param name
	 * @return
	 */
	bool hasLayer ( const String& name );

};

//---------------------------------------------

int TMXTileMap::sizeLayers() {
	return tiledLayers.size();
}

//---------------------------------------------

int TMXTileMap::getRows() const {
	return rows;
}

//---------------------------------------------

int TMXTileMap::getColums() const {
	return colums;
}

//---------------------------------------------

int TMXTileMap::getWidth() const {
	return width;
}

//---------------------------------------------

int TMXTileMap::getHeight() const {
	return height;
}

//---------------------------------------------

int TMXTileMap::getTileWidth() const {
	return tileWidth;
}

//---------------------------------------------

int TMXTileMap::getTileHeight() const {
	return tileHeight;
}

//---------------------------------------------

}
} /* namespace */
