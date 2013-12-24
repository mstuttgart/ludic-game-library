/**
 * @file MouseAddON.h
 * @author Michell Stuttgart
 * @date 12/21/2013
 */

#ifndef MOUSEADDON_H_
#define MOUSEADDON_H_

#include "AllegroAddON.h"
#include "HardwareException.h"

namespace sgl {
	namespace core {

/**
 * @class MouseAddON
 * @brief Class designed to boot from Allegro.
 *
 * Initialization is performed automatically when the constructor of the class 
 * is called by the instance attribute.
 */
class MouseAddON : public AllegroAddON {

private:

	static MouseAddON instance; /**<   */

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

};

} /* namespace core */
} /* namespace sgl */

#endif /* MOUSEADDON_H_ */
