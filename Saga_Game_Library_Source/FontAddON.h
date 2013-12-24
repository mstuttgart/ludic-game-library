/**
 * @file FontAddON.h
 * @author Michell Stuttgart
 * @date 12/21/2013
 */

#ifndef FONTADDON_H_
#define FONTADDON_H_

#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "AllegroAddON.h"

namespace sgl {
	namespace core {

/**
 * @class FontAddON
 * @brief Class designed to boot from Allegro Font support.
 *
 * Initialization is performed automatically when the constructor of the class 
 * is called by the instance attribute.
 */
class FontAddON : public AllegroAddON {

private:

	static FontAddON instance; /**<   */

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

};

} /* namespace core */
} /* namespace sgl */

#endif /* FONTADDON_H_ */
