#pragma once

#include "collision_rect.h"
#include "tile_set.h"
#include "tiled_layer.h"
#include "image.h"

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

	std::vector<TileSet*> tilesets;
	std::vector<TiledLayer*> layers;
	std::vector<Image*> images;
	std::vector<CollisionRect*> cRects;

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
	void parseImages( int gid, TiXmlElement* elem );

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
	Image* getImageObject( unsigned int idx );


	/**
	 * @brief
	 * @param name
	 * @return
	 */
	const char* getProperty( const char* name );

	/**
	 * @brief
	 * @param layerIndex
	 */
	void drawLayer( unsigned int layerIndex );
	
	/**
	 * @brief 
	 * @param rect
	 * @return 
	 */
	bool collisionVerify( CollisionRect& rect );
	
	/**
	 * @brief 
	 * @param rect
	 * @param idx
	 * @return 
	 */
	bool collisionVerify( CollisionRect& rect, unsigned int idx );

	/**
	 * @brief
	 * @return
	 */
	int sizeLayers();

	/**
	 * @brief
	 * @return
	 */
	int sizeImgObjects();
	
	/**
	 * @brief 
	 * @return 
	 */
	int sizeRects();

};

}
} /* namespace */
