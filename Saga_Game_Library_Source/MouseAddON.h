/**
 * @file MouseAddON.h
 * @author Michell Stuttgart
 * @date 12/21/2013
 */

#pragma once

#include "AllegroAddON.h"
#include "HardwareException.h"

namespace sgl {

/**
 * @class MouseAddON
 * @brief Class designed to boot from Allegro.
 *
 * Initialization is performed automatically when the constructor of the class 
 * is called by the instance attribute.
 */
class MouseAddON : public AllegroAddON {

protected:

	/**
	 * @brief Standard Constructor.
	 */
	MouseAddON();

public:

	/**
	 * @brief Standard Destructor
	 */
	virtual ~MouseAddON(){};
	
	/**
	 * @brief returns the state of Mouse AddOn.
	 * @return true if the Mouse has already begun, or false otherwise.
	 */
	static bool isInit();

};

} /* namespace sgl */
