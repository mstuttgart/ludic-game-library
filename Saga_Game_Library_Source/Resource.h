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
	virtual ~Resource();
	
public:


	/**
	 * @brief
	 * @param rsc
	 */
	static void destroyResource( Resource* rsc );

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
	void* getResorcePtr() const;

};

} /* namespace */

#endif
