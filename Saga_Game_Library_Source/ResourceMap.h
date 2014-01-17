#ifndef _SGL_RESOURCE_MAP_
#define _SGL_RESOURCE_MAP_

#include "Resource.h"
#include <map>

namespace sgl {

/**
 * @file ResourceMap.h
 * @author Michell Stuttgart
 * @date 01/16/14
 * @class ResourceMap
 * @brief
 */
class ResourceMap : protected std::map<const char*, Resource*> {

private:

	static ResourceMap* ms_instance;

	/**
	 * @brief
	 * @return
	 */
	ResourceMap() {};
	
	/**
	 * @brief Default Destructor
	 *
	 */
	virtual ~ResourceMap();

public:

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
	void addResource( Resource* resource );


	/**
	 * @brief
	 * @param resourceName
	 * @return
	 */
	bool getResource( const char* resourceName, Resource* resource );


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
	static void destroyResourceMap();

};

}/* namespace */

#endif
