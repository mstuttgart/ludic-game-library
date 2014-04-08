#pragma once

#include "sgl.h"
#include "event_source.h"
#include "scene.h"
#include <functional>
#include <map>

namespace sgl {
namespace input {
	
typedef std::function<void ()> Function;

/**
 * @file event_manager.h
 * @author Michell Stuttgart
 * @date 03/23/14
 * @class EventManager
 * @brief
 */
class EventManager {

protected:

	// Declaramos uma fila de eventos 
	ALLEGRO_EVENT_QUEUE* eventQueue;
	
	std::map<ALLEGRO_EVENT_TYPE, Function> mapa;
	
	Scene& scene;
	
	// Recebe os eventos gerados
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMER* timer;
	bool redraw;
	bool done;

public:


	/**
	 * @brief
	 * @param _queue
	 * @param source
	 */
	EventManager( Scene& _scene );

	/**
	 * @brief
	 */
	virtual ~EventManager();
	
	/**
	 * @brief 
	 * @return 
	 */
	bool isEmpty();
	
	
	void execute();
	
	

};

}
} /* namespace */
