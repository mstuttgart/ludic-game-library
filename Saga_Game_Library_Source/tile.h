#pragma once

#include "property_set.h"

namespace sgl {
namespace image {

/**
 * @file tile.h
 * @author Michell Stuttgart
 * @date 02/16/14 
 * @class Tile
 * @brief 
 */
class Tile {

private:

	int id;
	PropertySet propertySet;

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
	 * @param node
	 */
	void parse( TiXmlNode* node );

	/**
	 * @brief
	 * @return
	 */
	inline int getId() { return id;	}

	/**
	 * @brief
	 * @return
	 */
	inline PropertySet& getPropertySet() {
		return propertySet;
	}

};

}
} /* namespace */
