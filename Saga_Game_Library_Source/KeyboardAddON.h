/**
 * @file KeyboardAddON.h
 * @author Michell Stuttgart
 * @date 12/21/2013
 */

#ifndef KEYBOARDADDON_H_
#define KEYBOARDADDON_H_

#include "AllegroAddON.h"
#include "HardwareException.h"

namespace sgl {
	namespace core {

/**
 * @class KeyboardAddON
 * @brief Class designed to boot from Allegro Keyboard support.
 *
 * Initialization is performed automatically when the constructor of the class 
 * is called by the instance attribute.
 */
class KeyboardAddON : public AllegroAddON{

private:

	static KeyboardAddON instance; /**<   */

protected:

	/**
	 * @brief Standard Constructor.
	 */
	KeyboardAddON();

public:

	/**
	 * @brief Standard Destructor
	 */
	virtual ~KeyboardAddON(){};

};

} /* namespace core */
} /* namespace sgl */

#endif /* KEYBOARDADDON_H_ */
