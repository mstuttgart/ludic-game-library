/**
 * @file AudioAddON.h
 * @author Michell Stuttgart
 * @date 12/21/2013
 */

#pragma once

#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "AllegroAddON.h"

namespace sgl {

/**
 * @class AudioAddON
 * @brief Class designed to boot from Allegro Audio support and Codec Audios.
 *
 * Initialization is performed automatically when the constructor of the class
 * is called.
 */
class AudioAddON : public AllegroAddON {

private:

	static bool addOnState; /**< flag that indicates the state of the addon */

protected:

	/**
	 * @brief Standard Constructor.
	 */
	AudioAddON();

public:

	/**
	 * @brief Standard Destructor
	 */
	virtual ~AudioAddON() {};

	/**
	* @brief returns the state of Font AddOn.
	* @return true if the fontAddOn has already begun, or false otherwise.
	*/
	static bool isInit();

};

} /* namespace sgl */
