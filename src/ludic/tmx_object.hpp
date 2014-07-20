/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is FREE SOFTWARE released under the BSD License.                //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "sgl.hpp"
#include "vector2_d.hpp"
#include "../tinyxml/tinyxml.h"

namespace Ludic {

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
	const String& getName() const;

	/**
	 * @brief
	 * @return
	 */
	int getGid() const;

	/**
	 * @brief
	 * @return
	 */
	const Vector2D& getPosition() const;

};

}/* namespace */