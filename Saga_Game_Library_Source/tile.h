#pragma once

#include "tmx_base.h"

namespace sgl {
namespace image {


/**
 * @file tile.h
 * @author Michell Stuttgart
 * @date 02/16/14 
 * @class Tile
 * @brief 
 */
class Tile : public TmxBase{

private:

	int id;

public:

	/**
	 * @brief
	 * @param node
	 */
	Tile();

	/**
	 * @brief
	 * @return
	 */
	virtual ~Tile() {};
	

	/**
	 * @brief 
	 * @param elem
	 */
	virtual void parse( TiXmlNode* node );

	/**
	 * @brief
	 * @return
	 */
	inline int getId() { return id;	}

};

}
} /* namespace */
