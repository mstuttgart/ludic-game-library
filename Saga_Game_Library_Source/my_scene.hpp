#pragma once

#include "scene.hpp"

#include "key_listener.hpp"
#include "video.hpp"
#include "animated_sprite.hpp"
#include "font.hpp"
#include "tmx_tile_map.hpp"
#include "audio_sample.hpp"
#include "audio_stream.hpp"

typedef sgl::event::KeyListener KeyListener;
typedef sgl::event::KeyEvent KeyEvent;

namespace sgl {

/**
 * @class MyScene
 * @author Michell Stuttgart
 * @date 04/28/14
 * @file my_scene.h
 * @brief
 */
class MyScene : public Scene, public KeyListener {

private:

	int movex, movey;
	bool keys[ALLEGRO_KEY_MAX];
	Vector2D desloc;
	Video* video;
	sgl::image::AnimatedSprite spr;
	sgl::image::TMXTileMap mapa;
	std::vector<sgl::image::Layer*> layerManager;
	sgl::image::TiledLayer* l;
	sgl::audio::AudioStream musica;

public:

	MyScene( Video* _video );
	~MyScene();

public:

	void finalize();
	void initialize();
	void logic();
	void render();

	/**
	* @brief
	* @param ev
	*/
	virtual void displayClose();

	/**
	 * @brief
	 * @param keyCode
	 */
	virtual void keyDown( const KeyEvent& keyEvent );

	/**
	 * @brief
	 * @param keyCode
	 */
	virtual void keyRelease( const KeyEvent& keyEvent );

};

} /* namespace */
