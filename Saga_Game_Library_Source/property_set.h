#pragma once

#include <map>
#include "tinyxml/tinyxml.h"

namespace sgl {
namespace image {

/**
 * @file property_set.h
 * @author Michell Stuttgart
 * @date 02/16/14 
 * @class PropertySet
 * @brief 
 */
class PropertySet {

private:

	std::map<const char*, const char*> property;

public:

	/**
	 * @brief 
	 * @return 
	 */
	PropertySet() {};
	
	/**
	 * @brief 
	 * @return 
	 */
	virtual ~PropertySet() {};
	
	/**
	 * @brief 
	 * @param node
	 */
	void parse( TiXmlNode* node );
	
	/**
	 * @brief 
	 * @param name
	 * @return 
	 */
	bool hasProperty( const char* name );
	
	/**
	 * @brief 
	 * @param name
	 * @return 
	 */
	const char* getPropertyValue( const char* name );
	
	/**
	 * @brief 
	 * @return 
	 */
	inline const int getSize(){ return property.size(); }
	
	/**
	 * @brief 
	 */
	inline void clear(){ property.clear(); }
	
	/**
	 * @brief 
	 * @return 
	 */
	inline bool isEmpty(){ return property.empty(); }

};

}
} /* namespace */
