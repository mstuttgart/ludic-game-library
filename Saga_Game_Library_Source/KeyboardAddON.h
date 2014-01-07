/**
 * @file KeyboardAddON.h
 * @author Michell Stuttgart
 * @date 12/21/2013
 */

#pragma once

#include "AllegroAddON.h"
#include "HardwareException.h"

namespace sgl {

/**
 * @class KeyboardAddON
 * @brief Class designed to boot from Allegro Keyboard support.
 *
 * Initialization is performed automatically when the constructor of the class
 * is called.
 */
class KeyboardAddON : public AllegroAddON {

protected:

	/**
	 * @brief Standard Constructor.
	 */
	KeyboardAddON();

public:

	/**
	 * @brief Standard Destructor
	 */
	virtual ~KeyboardAddON() {};

	/**
	 * @brief returns the state of KeyBoard AddOn.
	 * @return true if the KeyBoard has already begun, or false otherwise.
	 */
	static bool isInit();

};

} /* namespace sgl */
