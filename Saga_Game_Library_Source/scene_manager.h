#pragma once

#include "key_listener.h"
#include "display_listener.h"
#include "scene.h"
#include "video.h"

#include <vector>

namespace sgl {
namespace input {

/**
* @file scene_manager.h
* @author Michell Stuttgart
* @date 03/23/14
* @class SceneManager
* @brief
*/
class SceneManager {

private:

	// Instancia de video
	Video* video;

	// Declaramos uma fila de eventos
	ALLEGRO_EVENT_QUEUE* eventQueue;

	// Vector que contem as referencia que mplementam cada listener
	std::vector<sgl::event::Listener*> listeners;

	// Objeto scene
	Scene* scene;

	// Recebe os eventos gerados
	ALLEGRO_EVENT al_event;
	ALLEGRO_TIMER* timer;

	bool redraw;
	bool done;

public:

	/**
	* @brief
	* @param _scene
	* @param _video
	* @param FPS
	*/
	SceneManager( Scene* _scene, Video* _video, int FPS );

	/**
	* @brief
	*/
	virtual ~SceneManager();

	/**
	 * @brief
	 * @param dListener
	 */
	void addDisplayListener( sgl::event::DisplayListener* dListener );

	/**
	 * @brief
	 * @param kListener
	 */
	void addKeyListener( sgl::event::KeyListener* kListener );

	/**
	 * @brief
	 */
	void addMouseListener();

	/**
	* @brief
	* @return
	*/
	bool isEmpty();

	/**
	 * @brief
	 */
	void initialize();

	/**
	 * @brief
	 */
	void execute();

	/**
	 * @brief
	 */
	void finalize();

};

}
} /* namespace */
