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
class TiledLayer : public Layer{

private:

	std::string name;
	int width;
	int height;
	bool visible;
	std::vector<Tile*> tiles;

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
	virtual ~TiledLayer() {};


	/**
	 * @brief
	 * @param node
	 * @param tileset
	 * @param width
	 * @param blockw
	 * @param blockh
	 */
	void parse( TiXmlNode* node, std::vector<TileSet*>& tileset, int width, int blockw, int blockh );

	/**
	 * @brief
	 * @param visible
	 */
	void setVisible(bool visible);

	/**
	 * @brief
	 * @return
	 */
	const char* getName();
	
	virtual int getWidth(){ return width; };
	
	virtual int getHeight(){ return height; };

	/**
	 * @brief
	 * @return
	 */
	bool isVisible() const;

	/**
	 * @brief
	 * @return
	 */
	int size() const;

	/**
	 * @brief 
	 */
	virtual void draw();

};

}
} /* namespace */
