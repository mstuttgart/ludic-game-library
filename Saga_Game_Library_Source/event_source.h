#pragma once

#include "sgl.h"

namespace sgl {

/**
 * @file event_source.h
 * @author Michell Stuttgart
 * @date 03/28/14 
 * @class EventSource
 * @brief 
 */
class EventSource {

private:

	ALLEGRO_EVENT_SOURCE* source;

public:

	virtual ~EventSource() {};

	/**
	 * @brief 
	 * @param src
	 */
	void operator = ( ALLEGRO_EVENT_SOURCE* src ) {
		this->source = src;
	}

	/**
	 * @brief 
	 */
	operator ALLEGRO_EVENT_SOURCE*() const {
		return source;
	}

};

}/* namespace */
