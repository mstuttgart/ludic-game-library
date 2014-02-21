#pragma once

#include "sgl.h"

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
	void* getResorcePtr() const;

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

};

} /* namespace */
