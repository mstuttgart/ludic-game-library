/**
 * @file AllegroAddON.h
 * @author Michell Stuttgart
 * @date 12/21/2013
 */

#ifndef ALLEGROADDON_H_
#define ALLEGROADDON_H_

#include "allegro5/allegro.h"
#include "AddOnException.h"
#include <iostream>

namespace sgl {
	namespace core {

/**
 * @class AllegroAddON
 * @brief Class designed to boot from Allegro.
 *
 * Initialization is performed automatically when the constructor of the class 
 * is called by the instance attribute.
 */
class AllegroAddON {

private:

	static AllegroAddON instance; /**<   */

protected:

	/**
	 * @brief Standard Constructor.
	 */
	AllegroAddON();

public:

	/**
	 * @brief Standard Destructor
	 */
	virtual ~AllegroAddON(){};

};

} /* namespace core */
} /* namespace sgl */

#endif /* ALLEGROADDON_H_ */
