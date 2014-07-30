//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   Ludic Game Library                                                     //
//   Copyright (C)2014 - Michell Stuttgart Faria                            //
//                       Paulo Vicente Gomes dos Santos                     //
//                       Alfredo José de Paula Barbosa                      //
//                                                                          //
//   Ludic is a FREE SOFTWARE released under the BSD License.               //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////


#pragma once

#include "ludic.hpp"

namespace Ludic
{

/**
 * @file AllegroStarter.hpp
 * @author Michell Stuttgart
 * @date 01/09/14
 * @class AllegroStarter
 * @brief Class responsible for initializing the basic modules of the Allegro.
 *
 * The basic modules are: Allegro_Image, Allegro_Font, Allegro_Audio
 * and Allegro_Primitives.
 * It is called automatically by Ludic Library
 * in early in the program. This is a class for the exclusive
 * use of the library.
 */
class AllegroStarter
{

private:

    static AllegroStarter instance;

    /**
    * @brief Default Constructor.
    */
    AllegroStarter();


public:

    /**
     * @brief Default Destructor
     */
    virtual ~AllegroStarter();

};

} /* sgl namespace */
