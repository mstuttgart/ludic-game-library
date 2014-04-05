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

	void* resourcePtr;
	const String resourceName;
	bool release;

protected:

	/**
	 * @brief
	 * @param fileName
	 * @param ptr
	 */
	Resource( const String& fileName, void* ptr );

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
	const String& getResourceName();

};

} /* namespace */
