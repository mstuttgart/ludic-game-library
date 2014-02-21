#pragma once

#include "tinyxml/tinyxml.h"
#include "image_resource.h"

namespace sgl {
namespace image {

/**
 * @file tile_set.h
 * @author Michell Stuttgart
 * @date 02/16/14
 * @class TileSet
 * @brief
 */
class TileSet{

private:

	int firstGid;
	int lastGid;
	std::string source;
	std::string name;
	int tileWidth;
	int tileHeight;
	int width;
	int height;
	int rows;
	int colums;
	ImageResource* image;

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
	
	/**
	 * @brief 
	 * @return 
	 */
	int getRows() const;

	/**
	 * @brief 
	 * @return 
	 */
	int getColums() const;

	/**
	 * @brief
	 * @return
	 */
	const std::string& getName() const;

	/**
	 * @brief
	 * @return
	 */
	const std::string& getSource() const;

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
	int getTileAmount();

};

}
} /* namespace */
