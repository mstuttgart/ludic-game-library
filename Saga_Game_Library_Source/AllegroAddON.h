/**
 * @file AllegroAddON.h
 * @author Michell Stuttgart
 * @date 12/21/2013
 */

#pragma once

#include "allegro5/allegro.h"
#include "AddOnException.h"
#include "LogOutput.h"

#include <iostream>

namespace sgl {

/**
 * @class AllegroAddON
 * @brief Class designed to boot from Allegro.
 *
 * Initialization is performed automatically when the constructor of the class
 * is called by the instance attribute.
 */
class AllegroAddON {

protected:

	/**
	 * @brief Standard Constructor. 
	 */
	AllegroAddON();

public:

	/**
	 * @brief Standard Destructor
	 */
	virtual ~AllegroAddON() {};

	/**
	 * @brief returns the state of Allegro Lib.
	 * @return true if the allegro has already begun, or false otherwise.
	 */
	static bool isInit();

};

} /* namespace sgl */
