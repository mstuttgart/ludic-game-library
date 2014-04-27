#pragma once

#include <allegro5/allegro.h>

namespace sgl {
namespace event {

/**
 * @class Event
 * @author Michell Stuttgart
 * @date 04/25/14
 * @file event.h
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
	 */
	operator ALLEGRO_EVENT*();

};

}
}/* namespace */
