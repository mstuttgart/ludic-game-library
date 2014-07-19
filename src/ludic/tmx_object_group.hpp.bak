#pragma once

#include "tmx_object.hpp"
#include <vector>

namespace Ludic {

/**
 * @file tmx_object_group.h
 * @author Michell Stuttgart
 * @date 04/14/14
 * @class TMXObjectGroup
 * @brief
 */
class TMXObjectGroup {

private:

	String name;
	int width;
	int height;

	std::vector<TMXObject*> objects;

public:

	/**
	 * @brief
	 */
	TMXObjectGroup();

	/**
	 * @brief
	 */
	virtual ~TMXObjectGroup();

	/**
	 * @brief
	 * @param node
	 */
	void parse( TiXmlNode* node );

	/**
	 * @brief
	 * @return
	 */
	inline int getHeight() const;

	/**
	 * @brief
	 * @return
	 */
	inline const String& getName() const;

	/**
	 * @brief
	 * @return
	 */
	inline const std::vector<TMXObject*>& getObjects() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getWidth() const;

};

//--------------------------------------------------------

int TMXObjectGroup::getHeight() const {
	return height;
}

//--------------------------------------------------------

const String& TMXObjectGroup::getName() const {
	return name;
}

//--------------------------------------------------------

const std::vector<TMXObject*>& TMXObjectGroup::getObjects() const {
	return objects;
}

//--------------------------------------------------------

int TMXObjectGroup::getWidth() const {
	return width;
}

//--------------------------------------------------------

} /* namespace */
