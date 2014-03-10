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
class ResourceMap {

private:

	static ResourceMap* ms_instance;
	static std::map<std::string, Resource*> *map_rsc;
	static std::map<std::string, Resource*>::iterator it;

	/**
	 * @brief
	 * @return
	 */
	ResourceMap() {};

public:

	/**
	 * @brief Default Destructor
	 *
	 */
	virtual ~ResourceMap();

	/**
	 * @brief
	 * @return
	 */
	static ResourceMap* getInstance();


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
	bool removeResource( std::string resourceName );


	/**
	 * @brief
	 * @param resourceName
	 * @return
	 */
	bool hasResource( std::string resourceName );
	

	/**
	 * @brief
	 * @return
	 */
	int size() const;

};

}/* namespace */
