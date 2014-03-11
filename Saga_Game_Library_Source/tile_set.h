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
	virtual ~TileSet(){};

	/**
	 * @brief
	 * @param node
	 */
	virtual void parse( TiXmlNode* node );

	/**
	 * @brief
	 * @return
	 */
	const inline int& getFirstGid() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	const inline int& getLastGid() const;

	/**
	 * @brief
	 * @return
	 */
	inline ImageResource* getImage() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	const inline int& getWidth() const ;
	
	/**
	 * @brief 
	 * @return 
	 */
	const inline int& getHeight() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	const inline int& getRows() const;

	/**
	 * @brief 
	 * @return 
	 */
	const inline int& getColums() const;

	/**
	 * @brief
	 * @return
	 */
	inline const std::string& getName() const;

	/**
	 * @brief
	 * @return
	 */
	inline const std::string& getSource() const;

	/**
	 * @brief
	 * @return
	 */
	const inline int& getTileHeight() const;

	/**
	 * @brief
	 * @return
	 */
	const inline int& getTileWidth() const;

	/**
	 * @brief
	 * @return
	 */
	const inline int& getTileAmount();

};

//==========================================================
// Implementacao inline dos metodos get

const int& TileSet::getFirstGid() const {
	return firstGid;
}

//-----------------------------------------------------------

const int& TileSet::getLastGid() const {
	return lastGid;
}

//-----------------------------------------------------------

ImageResource* TileSet::getImage() const{
	return image;
}

//-----------------------------------------------------------

const int& TileSet::getWidth() const {
	return width;
}

//-----------------------------------------------------------

const int& TileSet::getHeight() const {
	return height;
}

//-----------------------------------------------------------

const int& TileSet::getRows() const {
	return rows;
}

//-----------------------------------------------------------

const int& TileSet::getColums() const {
	return colums;
}

//-----------------------------------------------------------

const std::string& TileSet::getName() const{
	return name;
}

//-----------------------------------------------------------

const std::string& TileSet::getSource() const{
	return source;
}

//-----------------------------------------------------------

const int& TileSet::getTileHeight() const {
	return tileHeight;
}

//-----------------------------------------------------------

const int& TileSet::getTileWidth() const {
	return tileWidth;
}

//-----------------------------------------------------------

}
} /* namespace */
