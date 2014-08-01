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
 * \mainpage LUDIC GAME LIBRARY
 *
 * \section intro_sec Introduction
 * 
 * The Ludic Game Library, or Ludic library is a oriented object multi-platform game library, 
 * developed on Allegro5 API and the C++ language, focused on the development of 2D games. 
 * Its main focus is academia, providing students tools that will facilitate learning the 
 * techniques used in creating electronic games.
 * 
 * \section Features
 * 
 * The current version is usable. However, we intend to improve it even more, 
 * so it is defined as an alpha version 1.0.0.
 * 
 * * Support the animated sprites;
 * * Support the Tiled level editor to create Levels for you 
 * games and animations for you Animated Sprites;
 * * Support the several image formates provide by Allegro 5 API: BMP, PCX, TGA. 
 * Every platform also supports JPEG and PNG via external dependencies;
 * * Rendering using 3D hardware acceleration;
 * * Support of True Type fonts (.ttf);
 * * Support of several audio formates: .wav, .flac, .ogg, .it, .mod, .s3m, .xm. 
 * Include support to play BGM and SFX sounds;
 * * Support of mouse and keyboard inputs. Support for joystick soon;
 * * Resource Manager proven methods to manage and control memory while allocating 
 * image resources, audio and ttf fonts resources;
 * * Support of collision checking by rectangles and pixel-perfect methods.
 * * Simple and easy to use :)
 * 
 * \section Dependences
 * 
 * Ludic Game Library makes use of other libraries to perform some of their routines:
 * 
 * * Allegro 5.0.10 - http://liballeg.org/
 * * TinyXML - http://www.grinninglizard.com/tinyxml/ - under ZLIB License
 * * zlib 1.2.3 - http://www.zlib.net - under zlib License
 * * Support for tile maps and animations made with Tiled. - http://www.mapeditor.org/
 * 
 * \section License
 * 
 * Ludic Game Library is released under the BSD License. 
 * This license is very simple and very permissive, go to the LICENSE file on 
 * the root of the distribution for its complete text. Just remember that 
 * Ludic Game Library uses other external libraries, and they have their own 
 * licenses that must be respected.
 * 
 * \section Credits
 * 
 * Copyright (C)2013-2014 by Michell Stuttgart Faria, Paulo Vicente Gomes dos Santos 
 * and Alfredo José de Paula Barbosa.
 *
 */

