#pragma once
#include "color.h"
/**
 * @file geometrics.h
 * @author Alfredo Barbosa
 * @date 03/20/14
 * @class Geometrics
 * @brief Usada para desenhar elementos geométricos básicos como linhas e formas.
 */
namespace sgl { 
	class Geometrics {
	private:
		int thickness;
		Color lineColor, fillColor;
	public:
		/** @return thickness, a grossura da linha do objeto. */
		int getThickness() const;
		/** @return lineColor, a cor usada nas linhas geradas pelo objeto. */
		const Color& getLineColor() const;
		/** @return fillColor, a cor usada no preenchimento das formas geradas pelo objeto. */
		const Color& getFillColor() const;
	public:
		/** @brief construtor padrão, cria um objeto de lineColor back e fillColor white. */
		Geometrics();
		/** @brief cria um objeto de thickness, lineColor e fillColor definidas
		* @param thickness
		* @param lineColor
		* @param fillColor
		*/
		Geometrics(int thickness, const Color& lineColor, const Color& fillColor);
		/** @param thickness */
		void setThickness(int value);
		/** @param lineColor */
		void setLineColor(const Color& value);
		/** @param fillColor */
		void setFillColor(const Color& value);
	public:
		/** @brief Provoca a atualização da tela. */
		void refreshScreen() const;
		/** @brief Preenche toda a tela com a fillColor. */
		void fillBackground() const;
		/** @brief Desenha uma linha de (x1, y1) até (x2, y2).
		* @param x1
		* @param y1
		* @param x2
		* @param y2
		*/
		void drawLine(float x1, float y1, float x2, float y2) const;
		/** @brief Desenha um triângulo de vértices (x1, y1), (x2, y2) e (x3, y3),
		Se fill=true, preenche o triângulo com fillColor.
		* @param x1
		* @param y1
		* @param x2
		* @param y2
		* @param x3
		* @param y3
		* @param fill (bool=false)
		*/
		void drawTriangle(float x1, float y1, float x2, float y2, 
			float x3, float y3, bool fill=false) const;
		/** @brief Desenha um retângulo com um vértice em (x, y), largura w 
		(da esquerda pra direita) e altura h (de cima pra baixo).
		Se fill=true, o retângulo é preenchido com fillColor.
		* @param x
		* @param y
		* @param w
		* @param h
		* @param fill (bool=false)
		*/
		void drawRectangle(float x, float y, float w, float h, bool fill=false) const;
		/** @brief Desenha um retângulo arredondado com um vértice em (x, y), 
		largura w (da esquerda pra direita) e altura h (de cima pra baixo).
		Os parâmetros rx e ry definem a largura e a altura das curvas respectivamente. 
		Se fill=true, o retângulo é preenchido com fillColor.
		* @param x
		* @param y
		* @param w
		* @param h
		* @param rx
		* @param ry
		* @param fill (bool=false)
		*/
		void drawRoundedRectangle(
			float x, float y, float w, float h, float rx, float ry, bool fill=false) const;
		/** @brief Desenha uma elipse no ponto (cx, cy) com raios rx e ry
		respectivamente. Se fill=true, a elipse é preenchida com fillColor.
		* @param cx
		* @param cy
		* @param rx
		* @param ry
		* @param fill (bool=false)
		*/
		void drawEllipse(float cx, float cy, float rx, float ry, bool fill=false) const;
		/** @brief Desenha uma circunferência (ou um círculo) na origem (x, y)
		com raio r. Se fill=false, só uma circunferência é desenhada. Se fill=true,
		ela é preenchida com fillColor.
		* @param x
		* @param y
		* @param r
		* @param fill (bool=false)
		*/
		void drawCircle(float x, float y, float r, bool fill=false) const;
		void drawArc(float x, float y, float r, float ia, float da) const;
		void drawSpline(float x1, float y1, 
			float x2, float y2, float x3, float y3, float x4, float y4);
	};
}