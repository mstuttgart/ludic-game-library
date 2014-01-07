/**
 * @file FontAddON.h
 * @author Michell Stuttgart
 * @date 12/21/2013
 */

#pragma once

#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "AllegroAddON.h"

namespace sgl {

/**
 * @class FontAddON
 * @brief Class designed to boot from Allegro Font support.
 *
 * Initialization is performed automatically when the constructor of the class 
 * is called.
 */
class FontAddON : public AllegroAddON {

private:

	static bool addOnState; /**< flag that indicates the state of the addon */

protected:

	/**
	 * @brief Standard Constructor.
	 */
	FontAddON();

public:

	/**
	 * @brief Standard Destructor
	 */
	virtual ~FontAddON(){};
	
	/**
	 * @brief returns the state of Font AddOn.
	 * @return true if the fontAddOn has already begun, or false otherwise.
	 */
	static bool isInit();

};

} /* namespace sgl */
