#pragma once

#include "tile_set.h"
#include "tile.h"
#include "layer.h"
#include <map>
#include <vector>

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

	std::string name;
	int colums;
	int vel_x, vel_y;
	int width, height;

	static int displayW;
	static int displayH;

	std::map<int, Tile*> mapTiles;
	std::map<int, Tile*>::iterator it;

	/**
	* @brief
	* @return
	*/
	virtual void parse( TiXmlNode* node );

public:

	/**
	 * @brief
	 */
	TiledLayer( int& w, int& h, int& _colums,
	            unsigned int& _displayW, unsigned int& _displayH );

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
	 * @param dx
	 * @param dy
	 */
	void scrool();


	/**
	 * @brief
	 * @param node
	 * @param tileset
	 * @param width
	 * @param blockw
	 * @param blockh
	 */
	void parse( TiXmlNode* node, std::vector<TileSet*>& tileset,
	            int& blockw, int& blockh );

	/**
	 * @brief
	 * @param vx
	 * @param vy
	 */
	void setScroolVelocity( int vx, int vy );

	/**
	 * @brief
	 * @param tileId
	 * @return
	 */
	int getTileId( int x, int y );

	/**
	 * @brief
	 * @param id
	 * @return
	 */
	Tile* getTile( int id );

	/**
	 * @brief
	 * @return
	 */
	inline const char* getName();

	/**
	 * @brief
	 * @return
	 */
	inline int getWidth();

	/**
	 * @brief
	 * @return
	 */
	inline virtual int getHeight();

	/**
	 * @brief
	 * @return
	 */
	inline int size() const;

	/**
	 * @brief
	 */
	virtual void draw();

};

//--------------------------------------------


int TiledLayer::getHeight() {
	return height;
}

//------------------------------------------------------------

int TiledLayer::getWidth() {
	return width;
}

//-----------------------------------------------------------

const char* TiledLayer::getName() {
	return name.c_str();
}

//-----------------------------------------------------------

int TiledLayer::size() const {
	return mapTiles.size();
}

//------------------------------------------------------------
}
} /* namespace */
