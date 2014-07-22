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

#include "collision_box.hpp"
#include "tiled_layer.hpp"
#include "tmx_loader.hpp"
#include "vector2_d.hpp"

namespace Ludic {

/**
 * @file tmx_tile_map.hpp
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
	int getColums() const;

	/**
	 * @brief
	 * @return
	 */
	int getRows() const;

	/**
	 * @brief
	 * @return
	 */
	int getTileWidth() const;

	/**
	 * @brief
	 * @return
	 */
	int getTileHeight() const;

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
	int sizeLayers();

	/**
	 * @brief
	 * @param name
	 * @return
	 */
	bool hasLayer ( const String& name );

};

} /* namespace */
