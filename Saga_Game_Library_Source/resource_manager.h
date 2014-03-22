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

	static ResourceManager* ms_instance;
	std::map<String, Resource*> mapResource;

	/**
	 * @brief
	 * @return
	 */
	ResourceManager();

	/**
	 * @brief Default Destructor
	 *
	 */
	virtual ~ResourceManager();

public:

	/**
	 * @brief
	 * @return
	 */
	static ResourceManager* getInstance();

	/**
	 * @brief
	 */
	static void destroy();


	/**
	 * @brief
	 * @param resourceName
	 * @return
	 */
	void addResource( String& fileName, Resource* resource );


	/**
	 * @brief
	 * @param resourceName
	 * @return
	 */
	Resource* getResource( String& resourceName );


	/**
	 * @brief
	 * @param resourceName
	 * @return
	 */
	bool hasResource( String& resourceName );


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
