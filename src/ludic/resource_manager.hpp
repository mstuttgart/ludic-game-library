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

#include "resource.hpp"
#include <map>
#include <memory>

namespace Ludic {

/**
 * @file resource_manager.h
 * @author Michell Stuttgart
 * @date 01/16/14
 * @class ResourceManager
 * @brief
 */
class ResourceManager {

private:

	static ResourceManager* ms_instance;
	std::map<String, Resource*> resourceMap;

	/**
	 * @brief
	 * @return
	 */
	ResourceManager();

public:


	/**
	 * @brief
	 */
	virtual ~ResourceManager();

	/**
	 * @brief
	 * @return
	 */
	static ResourceManager* Instance();

	/**
	 * @brief
	 */
	static void destroy();


	/**
	 * @brief
	 * @param fileName
	 * @param resource
	 */
	void addResource( const String& fileName, Resource* resource );


	/**
	 * @brief
	 * @param resourceName
	 * @return
	 */
	Resource* getResource( const String& resourceName );


	/**
	 * @brief
	 * @param resourceName
	 * @return
	 */
	bool hasResource( const String& resourceName );


	/**
	 * @brief
	 */
	void release();


	/**
	 * @brief
	 * @return
	 */
	int size() const;

};

}/* namespace */
