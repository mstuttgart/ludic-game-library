#pragma once

#include "property_set.h"

namespace sgl {
namespace image {

class TmxBase {

protected:

	PropertySet properties;

public:

	/**
	 * @brief
	 * @return
	 */
	virtual ~TmxBase() {};

	/**
	 * @brief
	 * @param node
	 */
	virtual void parse( TiXmlNode* node ) = 0;

	/**
	 * @brief 
	 * @param properties
	 */
	inline void setProperties(const PropertySet& properties) {
		this->properties = properties;
	}
	
	/**
	 * @brief 
	 * @return 
	 */
	inline const PropertySet& getProperties() const {
		return properties;
	}

};

}
} /* namespace */
