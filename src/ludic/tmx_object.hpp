#pragma once

#include "sgl.hpp"
#include "vector2_d.hpp"
#include "tinyxml/tinyxml.h"

namespace sgl {
namespace image {

/**
 * @file tmx_object.h
 * @author Michell Stuttgart
 * @date 04/14/14
 * @class TMXObject
 * @brief
 */
class TMXObject {

private:

	String name;
	int gid;
	Vector2D position;

public:

	/**
	 * @brief
	 */
	TMXObject();

	/**
	 * @brief
	 */
	virtual ~TMXObject() {};

	/**
	 * @brief
	 * @param node
	 */
	void parse( TiXmlNode* node );

	/**
	 * @brief
	 * @return
	 */
	inline const String& getName() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getGid() const;

	/**
	 * @brief
	 * @return
	 */
	inline const Vector2D& getPosition() const;

};

//------------------------------------------------

const String& TMXObject::getName() const {
	return name;
}

//------------------------------------------------

int TMXObject::getGid() const {
	return gid;
}

//------------------------------------------------

const Vector2D& TMXObject::getPosition() const {
	return position;
}

//------------------------------------------------

}
} /* namespace */
