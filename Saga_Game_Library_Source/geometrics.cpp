#include <allegro5/allegro_primitives.h>

#include "geometrics.hpp"
#include "color.hpp"

using namespace sgl;

//--------------------------------------------------------

Geometrics::Geometrics() : thickness( 1 ),
	lineColor( Color( 0, 0, 0 ) ), fillColor( Color( 255, 255, 255 ) ) {}

//--------------------------------------------------------

Geometrics::Geometrics( int _thickness,
                        const Color& _lineColor, const Color& _fillColor ):
	thickness( _thickness ),
	lineColor( _lineColor ),
	fillColor( _fillColor ) {}

//--------------------------------------------------------

int Geometrics::getThickness() const {
	return thickness;
}

//--------------------------------------------------------

const Color& Geometrics::getLineColor() const {
	return lineColor;
}

//--------------------------------------------------------

const Color& Geometrics::getFillColor() const {
	return fillColor;
}

//--------------------------------------------------------

void Geometrics::setThickness( int value ) {
	thickness = value;
}

//--------------------------------------------------------

void Geometrics::setLineColor( const Color& value ) {
	lineColor = value;
}

//--------------------------------------------------------

void Geometrics::setFillColor( const Color& value ) {
	fillColor = value;
}

//--------------------------------------------------------

void Geometrics::fillBackground() const {
	al_clear_to_color( fillColor );
}

//--------------------------------------------------------

void Geometrics::drawLine( const Vector2D& pos1, const Vector2D& pos2 ) const {

	// Desenhamos uma linha
	al_draw_line( pos1.getX(), pos1.getY(),
	              pos2.getX(), pos2.getY(), lineColor, thickness );

}

//--------------------------------------------------------

void Geometrics::drawTriangle( const Vector2D& v1, const Vector2D& v2,
                               const Vector2D& v3, bool fill ) const {

	float x1 = v1.getX();
	float y1 = v1.getY();
	float x2 = v2.getX();
	float y2 = v2.getY();
	float x3 = v3.getX();
	float y3 = v3.getY();

	// Desenhamos a borda
	al_draw_triangle( x1, y1, x2, y2, x3, y3, lineColor, thickness );

	// Verificamos se o triangulo deve ser preenchido
	if( fill )
		al_draw_filled_triangle( x1, y1, x2, y2, x3, y3, fillColor );

}

//--------------------------------------------------------

void Geometrics::drawRectangle( const Vector2D& pos,
                                float w, float h, bool fill ) const {

	float x = pos.getX();
	float y = pos.getY();

	// Desenhamos a borda
	al_draw_rectangle( x, y, x + w, y + h, lineColor, thickness );

	if( fill ) {
		const int& aux = thickness / 2;
		al_draw_filled_rectangle( x + aux, y + aux,
		                          x + w - aux, y + h - aux, fillColor );
	}//if
}

//--------------------------------------------------------

void Geometrics::drawRoundedRectangle( const Vector2D& pos, float w, float h,
                                       float rw, float rh, bool fill ) const {

	float x = pos.getX();
	float y = pos.getY();

	// Desenhamos a borda
	al_draw_rounded_rectangle( x, y, x + w, y + h, rw, rh, lineColor, thickness );

	if( fill ) {

		const int& aux = thickness / 4;

		// Preenchemos o retangulo
		al_draw_filled_rounded_rectangle(
		    x + aux, y + aux, x + w - aux, y + h - aux, rw, rh, fillColor );
	}
}

//--------------------------------------------------------

void Geometrics::drawEllipse(
    const Vector2D& center, float rx, float ry, bool fill ) const {

	float cx = center.getX();
	float cy = center.getY();

	// Desenhamos a borda da ellipse
	al_draw_ellipse( cx, cy, rx, ry, lineColor, thickness );

	// Se true, preenchemos com a cor fillcolor
	if( fill ) {

		const int& aux = thickness / 2;
		al_draw_filled_ellipse( cx, cy, rx - aux, ry - aux, fillColor );
	}
}

//------------------------------------------	--------------

void Geometrics::drawCircle( const Vector2D& pos, float r, bool fill ) const {

	float x = pos.getX();
	float y = pos.getY();

	// Desenhamos a borda do circulo
	al_draw_circle( x, y, r, lineColor, thickness );

	if( fill )
		al_draw_filled_circle( x, y, r - thickness / 2, fillColor );
}

//--------------------------------------------------------

void Geometrics::drawArc( const Vector2D& pos,
                          float r, float ia, float da ) const {
	al_draw_arc( pos.getX(), pos.getY(), r, ia, da, lineColor, thickness );
}

//--------------------------------------------------------

void Geometrics::drawSpline( const Vector2D& pos1, const Vector2D& pos2,
                             const Vector2D& pos3, const Vector2D& pos4 ) {

	const float aux[] = {
		pos1.getX(), pos1.getY(),
		pos2.getX(), pos2.getY(),
		pos3.getX(), pos3.getY(),
		pos4.getX(), pos4.getY()
	};

	// desenhamos a spline
	al_draw_spline( ( float* ) &aux, lineColor, thickness );
}

//--------------------------------------------------------
