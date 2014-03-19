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
	std::map<std::string, Resource*> map_rsc;

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
	void addResource( std::string fileName, Resource* resource );


	/**
	 * @brief
	 * @param resourceName
	 * @return
	 */
	Resource* getResource( std::string resourceName );


	/**
	 * @brief
	 * @param resourceName
	 * @return
	 */
	bool hasResource( std::string resourceName );


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
