/**
 * @file ImageAddON.h
 * @author Michell Stuttgart
 * @date 12/21/2013
 */

#ifndef IMAGEADDON_H_
#define IMAGEADDON_H_

#include "AllegroAddON.h"
#include "allegro5/allegro_image.h"

namespace sgl {
	namespace core {

/**
 * @class ImageAddON
 * @brief Class designed to boot from Allegro Image Support.
 *
 * Initialization is performed automatically when the constructor of the class 
 * is called by the instance attribute.
 */
class ImageAddON : public AllegroAddON{

private:

	static ImageAddON instance; /**<   */

protected:

	/**
	 * @brief Standard Constructor.
	 */
	ImageAddON();

public:

	/**
	 * @brief Standard Destructor
	 */
	virtual ~ImageAddON(){};

};

} /* namespace core */
} /* namespace sgl */

#endif /* IMAGEADDON_H_ */
