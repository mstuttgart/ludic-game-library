/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is a FREE SOFTWARE released under the BSD License.              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "ludic.hpp"

namespace Ludic {

/**
 * @file resource.hpp
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
