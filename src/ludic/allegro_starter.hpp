//////////////////////////////////////////////////////////////////////////////
//                                                                         	//
//   Ludic Game Library                                                    	//
//   Copyright (C)2014 - Michell Stuttgart Faria                          	//
//                       Paulo Vicente Gomes dos Santos				        //
//                       Alfredo José de Paula Barbosa                      //
//                                                                         	//
//   Ludic is a FREE SOFTWARE released under the BSD License.              	//
//                                                                         	//
//////////////////////////////////////////////////////////////////////////////


#pragma once

#include "sgl.hpp"

namespace Ludic {

/**
 * @file AllegroStarter.hpp
 * @author Michell Stuttgart
 * @date 01/09/14
 * @class AllegroStarter
 * @brief
 */
class AllegroStarter {

private:

	static AllegroStarter instance;

	/**
	* @brief Default Constructor.
	*/
	AllegroStarter();


public:

	/**
	 * @brief Default Destructor
	 */
	virtual ~AllegroStarter();

};

} /* sgl namespace */
