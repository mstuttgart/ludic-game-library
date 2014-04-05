#pragma once

#include "tile.h"
#include "sprite.h"

#include <map>

namespace sgl {
namespace image {


/**
 * @file layer.h
 * @author Michell Stuttgart
 * @date 02/16/14
 * @class Layer
 * @brief
 */
class TiledLayer : public Layer {

private:

	String name;

	Vector2D velocity;

	static int* colums;

	static int* width;
	static int* height;

	static int* tileWidth;
	static int* tileHeight;

	static int* displayW;
	static int* displayH;

	std::map<int, Tile*>* mapTiles;
	std::map<int, Tile*>::iterator it;

public:

	/**
	 * @brief
	 */
	TiledLayer( const String&, int& _colums,
	            int& _width, int& _height,
	            int& _tileWidth, int& _tileHeight,
	            int _displayW, int _displayH,
	            std::map<int, Tile*>* _mapTiles );

	/**
	 * @brief
	 */
	virtual ~TiledLayer();

	/**
	 * @brief
	 * @param x
	 * @param y
	 */
	void setPosition( const Vector2D& vec );

	/**
	* @brief
	* @param vx
	* @param vy
	*/
	void setScroolSpeed( const Vector2D& vec );

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
	inline int sizeLayers() const;

	/**
	 * @brief
	 */
	virtual void draw();

	/**
	 * @brief
	 * @param dx
	 * @param dy
	 */
	void scrool( float desloc );

};

//----------------------------------------------------------

const String& TiledLayer::getName() {
	return name;
}

//-----------------------------------------------------------

int TiledLayer::sizeLayers() const {
	return mapTiles->size();
}

//------------------------------------------------------------
}
} /* namespace */
