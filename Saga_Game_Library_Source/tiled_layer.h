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
	TiledLayer( int& w, int& h, int& _colums );

	/**
	 * @brief
	 */
	virtual ~TiledLayer();

	/**
	 * @brief
	 * @param x
	 * @param y
	 */
	virtual void setPosition( int x, int y );

	/**
	 * @brief
	 * @param dx
	 * @param dy
	 */
	virtual void move( int dx, int dy );


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
	const char* getName();

	/**
	 * @brief
	 * @return
	 */
	virtual int getWidth();

	/**
	 * @brief
	 * @return
	 */
	virtual int getHeight();

	/**
	 * @brief
	 * @return
	 */
	int size() const;

	/**
	 * @brief
	 */
	virtual void draw();

	/**
	 * @brief
	 */
	virtual void scrool();

};

}
} /* namespace */
