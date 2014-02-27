#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <iostream>

#include "sgl_exception.h" 


/**
 * @namespace sgl
 * @brief base of the namespace all SGL' namespaces.
 */
namespace sgl
{

    /**
     * @namespace graphics
     * @brief Holds all classes responsible for the graphics routines of SGL.
     */
    namespace graphics {}

    /**
     * @namespace audio
     * @brief Holds all classes responsible for routines audio of SGL.
     */
    namespace audio {}

    /**
     * @namespace font
     * @brief Holds all classes responsible for routines text of SGL.
     */
    namespace font {}

}

/**
 * \mainpage Saga Game Library
 *
 * \section intro_sec Introduction
 *
 * The Saga Game Library, or SGL library is a multiplatform library, developed on Allegro5 API
 * and the C + + language, focused on the development of 2D games. Its main focus is academia,
 * providing students tools that will facilitate learning the techniques used in creating
 * electronic games.
 *
 * \section hist_sec About
 *
 * Originally developed in 2013 and 2014, to design for:
 * Michell Stuttgart, Alfredo Barbosa and Paulo V. Gomes
 *
 */
