#ifndef _SGL_RESOURCE_
#define _SGL_RESOURCE_

#include "SGL.h"

namespace sgl {

/**
 * @file Resource.h
 * @author Michell Stuttgart
 * @date 01/16/14 
 * @class Resource
 * @brief 
 */
class Resource {

private:

	int referenceAmount;
	void* resourcePtr;
	std::string* resourceName;

protected:

	/**
	 * @brief 
	 * @param fileName
	 * @param ptr
	 */
	Resource( const char* fileName, void* ptr );
	
	/**
	 * @brief 
	 */
	void incReferenceAmount();
	
	/**
	 * @brief 
	 */
	void decReferenceAmount();
	

	/**
	 * @brief 
	 */
	const void* getResorcePtr() const;

public:

	/**
	 * @brief 
	 */
	virtual ~Resource();

	/**
	 * @brief 
	 * @return 
	 */
	const char* getResourceName();

	/**
	 * @brief 
	 * @return 
	 */
	int getReferenceAmount() const;
	
	/**
	 * @brief 
	 */
	virtual void draw( int& x, int& y, int& mirror ) = 0;

};

} /* namespace */

#endif
