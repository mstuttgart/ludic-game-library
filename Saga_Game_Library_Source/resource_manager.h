#pragma once

#include "resource.h"
#include <map>
#include <memory>

namespace sgl {

/**
 * @file ResourceMap.h
 * @author Michell Stuttgart
 * @date 01/16/14
 * @class ResourceMap
 * @brief
 */
class ResourceManager {

private:

	static std::unique_ptr<ResourceManager> ms_instance;
	std::map<String, Resource*> mapResource;

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
	static ResourceManager* getResourceManager();

	/**
	 * @brief
	 */
	static void destroy();


	/**
	 * @brief
	 * @param resourceName
	 * @return
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
