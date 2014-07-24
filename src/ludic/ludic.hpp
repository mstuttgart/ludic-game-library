/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is a FREE SOFTWARE released under the BSD License.              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>

#include <iostream>

#include "ludic_exception.hpp"
#include <stdexcept>      // std::out_of_range

typedef std::string String;

//////////////////////////////////////////////////////////////

/**
 * @namespace Ludic
 * @brief base of the namespace all Ludic library' namespaces.
 */
namespace Ludic
{}

//////////////////////////////////////////////////////////////

/**
 * \mainpage LUDIC Game Library
 *
 * \section intro_sec Introduction
 *
 * The Ludic Game Library, or Ludic library is a multiplatform library, developed on Allegro5 API
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

