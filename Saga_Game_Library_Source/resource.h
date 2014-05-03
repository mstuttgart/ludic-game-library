#pragma once

#include "sgl.h"

namespace sgl {

/**
 * @file resource.h
 * @author Michell Stuttgart
 * @date 01/16/14
 * @class Resource
 * @brief
 */
class Resource {

private:

	void* resourcePtr;
	String resourceName;
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
	void* getResourcePtr() const;

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
