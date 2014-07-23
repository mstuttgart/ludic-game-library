/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is a FREE SOFTWARE released under the BSD License.              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "tmx_object.hpp"
#include <vector>

namespace Ludic {

/**
 * @file tmx_object_group.hpp
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
	const String& getName() const;

	/**
	 * @brief
	 * @return
	 */
	const std::vector<TMXObject*>& getObjects() const;

};

} /* namespace */
