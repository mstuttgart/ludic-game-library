#pragma once

#include "tile.h"
#include "image_resource.h"

namespace sgl {
namespace image {
	
struct TileOffset{
	int x;
	int y;
};

/**
 * @file tile_set.h
 * @author Michell Stuttgart
 * @date 02/16/14
 * @class TileSet
 * @brief
 */
class TileSet : public TmxBase {

private:

	int firstGid;
	int lastGid;
	std::string source;
	const char* name;
	int tileWidth;
	int tileHeight;
	int width;
	int height;
	int rows;
	int colums;
	int spacing;
	int margin;
	TileOffset offset;
	ImageResource* image;
	std::map<int, Tile*> tiles;

public:

	/**
	 * @brief
	 */
	TileSet( const char* tileSetsDir );


	/**
	 * @brief
	 * @param node
	 */
	virtual ~TileSet();

	/**
	 * @brief
	 * @param node
	 */
	virtual void parse( TiXmlNode* node );

	/**
	 * @brief
	 * @return
	 */
	int getFirstGid() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	int getLastGid() const;

	/**
	 * @brief
	 * @return
	 */
	ImageResource* getImage();
	
	/**
	 * @brief 
	 * @return 
	 */
	int getWidth() const ;
	
	/**
	 * @brief 
	 * @return 
	 */
	int getHeight() const;
	
	int getRows() const;
	
	int getColums() const;

	/**
	 * @brief
	 * @return
	 */
	int getMargin() const;

	/**
	 * @brief
	 * @return
	 */
	const char* getName() ;

	/**
	 * @brief
	 * @return
	 */
	std::string* getSource();

	/**
	 * @brief
	 * @return
	 */
	int getSpacing() const;

	/**
	 * @brief
	 * @return
	 */
	int getTileHeight() const;

	/**
	 * @brief
	 * @return
	 */
	int getTileWidth() const;

	/**
	 * @brief
	 * @return
	 */
	const std::map<int, Tile*>& getTiles() const;

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
	int getTileAmount();

	/**
	 * @brief
	 * @param id
	 * @return
	 */
	bool hasTile( int id );


};

}
} /* namespace */
