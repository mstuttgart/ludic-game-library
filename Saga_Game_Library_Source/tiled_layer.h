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
	int vel_x;
	int vel_y;
	
	static int* colums;

	static short int* tileWidth;
	static short int* tileHeight;
	
	static int* displayW;
	static int* displayH;

	std::map<int, Tile*>* mapTiles;
	std::map<int, Tile*>::iterator it;

public:

	/**
	 * @brief
	 */
	TiledLayer( const char* _name, int& _colums,
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
	void setPosition( int x, int y );

	/**
	* @brief
	* @param vx
	* @param vy
	*/
	void setScroolSpeed( int vx, int vy );
	
	/**
	 * @brief 
	 * @param spr
	 * @param movX
	 * @param movY
	 * @param colums
	 * @param tileId
	 * @return 
	 */
	bool checkCollision( Sprite& spr, int movX, int movY, int tileId );

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
	void scrool( unsigned int dx, unsigned int dy );

};

//-----------------------------------------------------------

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
