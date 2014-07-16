#pragma once

#include "sgl.hpp"

namespace Ludic {

/**
 * @file AllegroStarter.h
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
