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
	std::string resourceName;
	bool release;

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
	void* getResorcePtr() const;


public:

	/**
	 * @brief
	 */
	virtual ~Resource();

	/**
	 * @brief
	 * @param release
	 */
	void setRelease(bool release);

	/**
	 * @brief
	 * @return
	 */
	bool isRelease() const;

	/**
	 * @brief
	 * @return
	 */
	std::string getResourceName();

};

} /* namespace */
