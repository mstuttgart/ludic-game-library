/**
 * @file ImageAddON.h
 * @author Michell Stuttgart
 * @date 12/21/2013
 * */
#pragma once

#include "AllegroAddON.h"
#include "allegro5/allegro_image.h"

namespace sgl {

/**
 * @class ImageAddON
 * @brief Class designed to boot from Allegro Image Support.
 *
 * Initialization is performed automatically when the constructor of the class
 * is called.
 */
class ImageAddON : public AllegroAddON {


private:

	static bool addOnState; /**< flag that indicates the state of the addon */

protected:

	/**
	* @brief Standard Constructor.
	*/
	ImageAddON();

public:

	/**
	 * @brief Standard Destructor
	 */
	virtual ~ImageAddON() {};

	/**
	 * @brief returns the state of Image AddOn.
	 * @return true if the imageAddOn has already begun, or false otherwise.
	 */
	static bool isInit();

};

} /* namespace sgl */
