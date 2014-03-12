#pragma once

#include "collision_rect.h"
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
	int sizeLayers();

	/**
	 * @brief
	 * @return
	 */
	int sizeImageObjects();

};

}
} /* namespace */
