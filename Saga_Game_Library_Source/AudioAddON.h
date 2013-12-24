/**
 * @file AudioAddON.h
 * @author Michell Stuttgart
 * @date 12/21/2013
 */

#ifndef AUDIOADDON_H_
#define AUDIOADDON_H_

#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "AllegroAddON.h"

namespace sgl {
	namespace core {

/**
 * @class AudioAddON
 * @brief Class designed to boot from Allegro Audio support and Codec Audios.
 *
 * Initialization is performed automatically when the constructor of the class 
 * is called by the instance attribute.
 */
class AudioAddON : public AllegroAddON {

private:

	static AudioAddON instance; /**<   */

protected:

	/**
	 * @brief Standard Constructor.
	 */
	AudioAddON();

public:

	/**
	 * @brief Standard Destructor
	 */
	virtual ~AudioAddON(){};

};

} /* namespace core */
} /* namespace sgl */

#endif /* AUDIOADDON_H_ */
