#ifndef _SGL_RESOURCE_MAP_
#define _SGL_RESOURCE_MAP_

#include "resource.h"
#include <map>

namespace sgl {

/**
 * @file ResourceMap.h
 * @author Michell Stuttgart
 * @date 01/16/14
 * @class ResourceMap
 * @brief
 */
class ResourceMap : private std::map<const char*, Resource*> {

private:

	static ResourceMap* ms_instance;

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
	void addResource( const char* fileName, Resource* resource );


	/**
	 * @brief
	 * @param resourceName
	 * @return
	 */
	Resource* getResource( const char* resourceName );


	/**
	 * @brief
	 * @param resourceName
	 * @return
	 */
	bool removeResource( const char* resourceName );


	/**
	 * @brief
	 * @param resourceName
	 * @return
	 */
	bool isResourcePresent( const char* resourceName );
	
	/**
	 * @brief 
	 * @return 
	 */
	int resourcesAmount() const;
	
	/**
	 * @brief 
	 */
	void release();

};

}/* namespace */

#endif
