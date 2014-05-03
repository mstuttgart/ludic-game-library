#pragma once

#include <allegro5/allegro.h>

namespace sgl {
namespace event {

/**
 * @file event.h
 * @author Michell Stuttgart
 * @date 04/25/14
 * @class Event
 * @brief
 */
class Event {

protected:

	ALLEGRO_EVENT al_event;

public:

	/**
	 * @brief
	 * @return
	 */
	Event(){};

	/**
	 * @brief
	 * @param _event
	 */
	Event( ALLEGRO_EVENT* _event );

	/**
	 * @brief
	 */
	~Event();

	/**
	 * @brief
	 * @return
	 */
	unsigned int getType() const;

	/**
	 * @brief
	 * @return
	 */
	operator ALLEGRO_EVENT*();

};

}
}/* namespace */
