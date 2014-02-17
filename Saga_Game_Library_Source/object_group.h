#pragma once

#include "object.h"
#include <vector>

namespace sgl {
namespace image {

class ObjectGroup : public TmxBase {

private:

	const char* name;
	double opacity;
	bool visible;

	std::vector<Object*> vObjects;

public:

	/**
	 * @brief 
	 */
	ObjectGroup();
	
	/**
	 * @brief 
	 */
	virtual ~ObjectGroup();

	/**
	 * @brief 
	 * @param node
	 */
	virtual void parse( TiXmlNode* node );

	/**
	 * @brief 
	 * @param index
	 * @return 
	 */
	Object* getObject( unsigned int index );
	
	/**
	 * @brief 
	 * @return 
	 */
	const char* getName();
	
	/**
	 * @brief 
	 * @return 
	 */
	double getOpacity() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	const std::vector<Object*>& getObjects() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	bool isVisible() const;

	/**
	 * @brief 
	 * @return 
	 */
	int size();

	/**
	 * @brief 
	 * @return 
	 */
	int isEmpty();

};

}
} /* namespace */
