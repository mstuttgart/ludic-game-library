#pragma once

#include "color.h"
#include "vector2_d.h"

namespace sgl {

/**
 * @file geometrics.h
 * @author Alfredo Barbosa
 * @date 03/20/14
 * @class Geometrics
 * @brief Usada para desenhar elementos geométricos básicos como linhas e formas.
 */
class Geometrics {

private:

	int thickness;
	Color lineColor, fillColor;

public:

	/**
	 * @brief
	 * @return thickness, a espessura da linha do objeto.
	 */
	int getThickness() const;

	/**
	 * @brief
	 * @return lineColor, a cor usada nas linhas geradas pelo objeto.
	 */
	const Color& getLineColor() const;

	/**
	 * @brief
	 * @return fillColor, a cor usada no preenchimento das formas
	 * geradas pelo objeto.
	 */
	const Color& getFillColor() const;

public:

	/**
	 * @brief Construtor padrão, cria um objeto de
	 * lineColor back e fillColor white.
	 */
	Geometrics();

	/**
	* @brief cria um objeto de thickness, lineColor e fillColor definidas.
	*
	* @param thickness
	* @param lineColor
	* @param fillColor
	*/
	Geometrics( int _thickness, const Color& _lineColor, const Color& _fillColor );

	/**
	 * @brief thickness
	 * @param value
	 */
	void setThickness( int value );

	/**
	 * @brief lineColor
	 * @param value
	 */
	void setLineColor( const Color& value );

	/**
	 * @brief fillColor
	 * @param value
	 */
	void setFillColor( const Color& value );

public:

	/** @brief Preenche toda a tela com a fillColor.*/
	void fillBackground() const;

	/**
	* @brief Desenha uma linha de (x1, y1) até (x2, y2).
	*
	* @param pos1
	* @param pos2
	**/
	void drawLine( const Vector2D& pos1, const Vector2D& pos2 ) const;

	/**
	* @brief Desenha um triângulo de vértices (x1, y1), (x2, y2) e (x3, y3),
	* Se fill=true, preenche o triângulo com fillColor.
	*
	* @param v1
	* @param v2
	* @param v3
	* @param fill (bool=false)
	*/
	void drawTriangle( const Vector2D& v1, const Vector2D& v2,
	                   const Vector2D& v3, bool fill = false ) const;

	/**
	* @brief Desenha um retângulo com um vértice em (x, y), largura w
	* (da esquerda pra direita) e altura h (de cima pra baixo).
	* Se fill=true, o retângulo é preenchido com fillColor.
	*
	* @param pos
	* @param w
	* @param h
	* @param fill (bool=false)
	*/
	void drawRectangle( const Vector2D& pos, float w, float h, bool fill = false ) const;

	/**
	 * @brief Desenha um retângulo arredondado com um vértice em (x, y),
	 * largura w (da esquerda pra direita) e altura h (de cima pra baixo).
	 * Os parâmetros rx e ry definem a largura e a altura das curvas
	 * respectivamente.
	 * Se fill=true, o retângulo é preenchido com fillColor.
	 *
	 * @param pos
	 * @param w
	 * @param h
	 * @param rw
	 * @param rh
	 * @param fill (bool=false)
	 */
	void drawRoundedRectangle(
	    const Vector2D& pos, float w, float h, float rw, float rh, bool fill = false ) const;


	/**
	 * @brief Desenha uma elipse no ponto (cx, cy) com raios rx e ry
	 * respectivamente. Se fill=true, a elipse é preenchida com fillColor.
	 *
	 * @param center
	 * @param rx
	 * @param ry
	 * @param fill (bool=false)
	 */
	void drawEllipse( const Vector2D& center, float rx, float ry, bool fill = false ) const;

	/**
	 * @brief Desenha uma circunferência (ou um círculo) na origem (x, y)
	 * com raio r. Se fill=false, só uma circunferência é desenhada.
	 * Se fill=true, ela é preenchida com fillColor.
	 *
	 * @param pos
	 * @param r
	 * @param fill (bool=false)
	 */
	void drawCircle( const Vector2D& pos, float r, bool fill = false ) const;

	/**
	 * @brief
	 * @param pos
	 * @param r
	 * @param ia
	 * @param da
	 */
	void drawArc( const Vector2D& pos, float r, float ia, float da ) const;

	/**
	 * @brief
	 * @param pos1
	 * @param pos2
	 * @param pos3
	 * @param pos4
	 */
	void drawSpline(
	    const Vector2D& pos1, const Vector2D& pos2, const Vector2D& pos3, const Vector2D& pos4 );

};

} /* namespace */
