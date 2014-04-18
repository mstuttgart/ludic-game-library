#pragma once

#include "bouding_box.h"
#include "tiled_layer.h"
#include "tmx_loader.h"
#include "vector2_d.h"

namespace sgl {
namespace image {

/**
 * @class TMXTileMap
 * @author Michell Stuttgart
 * @date 04/14/14
 * @file tmx_tile_map.h
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
	 * @param display
	 * @return 
	 */
	bool load( TMXLoader* loader );


	/**
	 * @brief
	 * @param spr
	 * @param layer
	 * @param tileId
	 * @return
	 */
	bool checkCollision ( const Sprite& spr, int movX, int movY,
	                      const String& layerName, int tileId );

	/**
	 * @brief
	 */
	void scroll ( float desloc );

	/**
	 * @brief
	 * @param layerIdx
	 * @param velx
	 * @param vely
	 */
	void setScrollVelocity ( const String& layerName, const Vector2D& vel );

	/**
	 * @brief
	 * @param layerIdx
	 * @param x
	 * @param y
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
	 * @param layerName
	 */
	void setVisible ( bool visible );

	/**
	 * @brief
	 * @param x
	 * @param y
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
	 * @param idx
	 * @return
	 */
	TiledLayer* getLayer ( const String& layerName );

	/**
	 * @brief
	 * @param idx
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
