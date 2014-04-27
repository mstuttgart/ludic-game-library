#pragma once

#include <allegro5/allegro.h>
#include "event.h"

namespace sgl {
namespace event {

/**
 * @class Listener
 * @author Michell Stuttgart
 * @date 04/23/14
 * @file listener.h
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
