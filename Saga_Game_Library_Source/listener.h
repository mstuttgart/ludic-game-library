#pragma once

#include <allegro5/allegro.h>
#include "event.h"

namespace sgl {
namespace event {

/**
 * @file listener.h
 * @author Michell Stuttgart
 * @date 04/23/14
 * @class Listener
 * @brief
 */
class Listener {

public:

	/**
	 * @brief
	 */
	Listener();

	/**
	 * @brief
	 */
	virtual ~Listener();

	/**
	 * @brief
	 */
	virtual void callMethods( Event& ev ) = 0;

};

}
} /* namespace */
