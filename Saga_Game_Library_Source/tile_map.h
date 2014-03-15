#pragma once

#include "bouding_box.h"
#include "tile_set.h"
#include "tiled_layer.h"
#include "static_sprite.h"

namespace sgl {
namespace image {

/**
 * @file tile_map.h
 * @author Michell Stuttgart
 * @date 02/20/14
 * @class TileMap
 * @brief
 */
class TileMap {

private:

	int rows;
	int colums;
	int width;
	int height;
	int tileWidth;
	int tileHeight;

	std::vector<TiledLayer*> layers;
	std::vector<StaticSprite*> imgObject;
	std::map<std::string, std::string> properties;

	/**
	 * @brief
	 * @param root
	 */
	virtual void parse( TiXmlNode* root, const char* source );

	/**
	 * @brief
	 * @param gid
	 * @param elem
	 */
	void parseImages( int& gid, TiXmlElement* elem, std::vector<TileSet*>& tileset );
	
	/**
	 * @brief 
	 */
	void release();

public:

	/**
	 * @brief
	 */
	TileMap();

	/**
	 * @brief
	 */
	TileMap( const char* tmxFileName );

	/**
	 * @brief
	 * @param tmxFile
	 */
	virtual ~TileMap();

	/**
	 * @brief
	 * @param tmxFile
	 */
	void loadMap( const char* tmxFileName );
	
	/**
	 * @brief 
	 * @param x
	 * @param y
	 * @return 
	 */
	int getTileId( int x, int y );

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
	TiledLayer* getLayer( unsigned int idx );

	/**
	 * @brief
	 * @param idx
	 * @param tileId
	 * @return
	 */
	StaticSprite* getImageObject( unsigned int idx );

	/**
	 * @brief
	 * @param name
	 * @return
	 */
	const char* getProperty( const char* name );

	/**
	 * @brief
	 * @param idx
	 */
	void drawLayer( unsigned int idx );

	/**
	 * @brief
	 * @return
	 */
	inline int sizeLayers();

	/**
	 * @brief
	 * @return
	 */
	inline int sizeImageObjects();
	
	/**
	 * @brief 
	 * @param spr
	 * @param layer
	 * @param tileId
	 * @return 
	 */
	bool checkCollision( Sprite& spr, int movX, int movY, int layer, int tileId );

};

//-------------------------------------------------------------

int TileMap::sizeLayers() {
	return layers.size();
}

//---------------------------------------------

int TileMap::sizeImageObjects() {
	return imgObject.size();
}

//---------------------------------------------

int TileMap::getRows() const {
	return rows;
}

//---------------------------------------------

int TileMap::getColums() const {
	return colums;
}

//---------------------------------------------

int TileMap::getWidth() const {
	return width;
}

//---------------------------------------------

int TileMap::getHeight() const {
	return height;
}

//---------------------------------------------

int TileMap::getTileWidth() const {
	return tileWidth;
}

//---------------------------------------------

int TileMap::getTileHeight() const {
	return tileHeight;
}

//---------------------------------------------

}
} /* namespace */
