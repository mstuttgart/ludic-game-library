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
	bool released;

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
	 * @param released
	 */
	void setReleased(bool released);

	/**
	 * @brief
	 * @return
	 */
	bool isReleased() const;

	/**
	 * @brief
	 * @return
	 */
	const String& getResourceName();

};

} /* namespace */
