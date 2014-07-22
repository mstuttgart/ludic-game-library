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

#include "sgl.hpp"

namespace Ludic
{

/**
 * @file color.hpp
 * @author Michell Stuttgart
 * @date 03/06/14
 * @class Color
 * @brief
 */
class Color
{

private:

	float r, g, b;

public:

	Color();

	/**
	 * @brief Cria uma cor no campo RGB.
	 * @param red
	 * @param green
	 * @param blue
	 */
	Color( float red, float green, float blue );

	/**
	 * @brief Cria uma cor usando a notação clássica da web.
	 * @param html
	 */
	Color( const String& html );


	/**
	 * @brief
	 * @param red
	 * @param green
	 * @param blue
	 */
	void setRGB( int red, int green, int blue );

	/**
	 * @brief
	 * @return Nome da cor, caso ela tenha um nome.
	 */
	String getName() const;

	/**
	 * @brief
	 * @return Código RGB em HTML da cor.
	 */
	String toHTML() const;

	/**
	 * @brief Muda a cor de um objeto.
	 * @param r
	 * @param g
	 * @param b
	 */
	void toRGB( int& r, int& g, int& b );

	/**
	 * @brief Uso interno: Faz a conversão automática de um objeto do tipo color
		para um objeto do tipo ALLEGRO_COLOR. Essa conversão é automática quando
		se espera um objeto ALLEGRO_COLOR e não deve ser forçada de qualquer
		outra forma.
	 * @return
	 */
	operator ALLEGRO_COLOR() const;

};

} /* namespace */
