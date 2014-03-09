#pragma once

#include "tile_set.h"
#include "tile.h"
#include "layer.h"
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
	int vel_x, vel_y;
	int width, height;
	std::vector<Tile*> tiles;
	ALLEGRO_BITMAP* background;

	/**
	* @brief
	* @return
	*/
	virtual void parse( TiXmlNode* node );

public:

	/**
	 * @brief
	 */
	TiledLayer( int& w, int& h );

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
	            int& width, int& blockw, int& blockh );

	/**
	 * @brief
	 * @param vx
	 * @param vy
	 */
	void setScroolVelocity( int vx, int vy );

	/**
	 * @brief
	 * @return
	 */
	const char* getName();

	/**
	 * @brief
	 * @return
	 */
	virtual int getWidth() {
		return width;
	};

	/**
	 * @brief
	 * @return
	 */
	virtual int getHeight() {
		return height;
	};

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
