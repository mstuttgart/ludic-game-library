#pragma once

#include "tile.hpp"
#include "sprite.hpp"
#include "tmx_tile_set.hpp"
#include "tmx_layer.hpp"

#include <map>
#include <vector>

namespace Ludic {

/**
 * @file tiled_layer.h
 * @author Michell Stuttgart
 * @date 02/16/14
 * @class TiledLayer
 * @brief
 */
class TiledLayer : public Layer {

private:

	String name;

	Vector2D velocity;

	int* colums;

	int* width;
	int* height;

	int* tileWidth;
	int* tileHeight;

	int displayW;
	int displayH;

	std::map<int, Tile*> mapTiles;
	std::map<int, Tile*>::iterator it;

		private:

void initTiledLayer();

public:

	/**
	 * @brief
	 * @param _name
	 * @param _colums
	 * @param _width
	 * @param _height
	 * @param _tileWidth
	 * @param _tileHeight
	 * @param data
	 * @param tmxTileset
	 * @param baseImages[]
	 */
	TiledLayer( const String& _name, int& _colums,
	            int& _width, int& _height,
	            int& _tileWidth, int& _tileHeight,
				const std::vector< TMXLayer::DataInfo >& data, const std::vector< TMXTileSet* >& tmxTileset,
				ImageResource* baseImages[]
	            );

	/**
	 * @brief
	 */
	virtual ~TiledLayer();

	/**
	 * @brief
	 * @param vec
	 */
	void setPosition( const Vector2D& vec );

	/**
	* @brief
	* @param vec
	*/
	void setScroolSpeed( const Vector2D& vec );

	/**
	 * @brief
	 * @param width
	 * @param height
	 */
	void setScreenDimension( int width, int height );

	/**
	 * @brief
	 * @param spr
	 * @param movX
	 * @param movY
	 * @param colums
	 * @param tileId
	 * @return
	 */
	bool checkCollision( const Sprite& spr, int movX, int movY, int tileId );

	/**
	 * @brief
	 * @return
	 */
	virtual float getWidth() const;

	/**
	 * @brief
	 * @return
	 */
	virtual float getHeight() const;

	/**
	 * @brief
	 * @param id
	 * @return
	 */
	const Tile* getTile( int id );

	/**
	 * @brief
	 * @return
	 */
	inline const String& getName();

	/**
	 * @brief
	 * @return
	 */
	inline int size() const;

	/**
	 * @brief
	 */
	virtual void draw();

	/**
	 * @brief
	 * @param desloc
	 */
	void scrool( float desloc );

};

//----------------------------------------------------------

const String& TiledLayer::getName() {
	return name;
}

//-----------------------------------------------------------

int TiledLayer::size() const {
	return mapTiles.size();
}

//------------------------------------------------------------

} /* namespace */
