#include <allegro5/allegro_primitives.h>

#include "geometrics.h"
#include "color.h"

using namespace sgl;

//--------------------------------------------------------

Geometrics::Geometrics() :
	thickness( 1 ), lineColor( Color( 0, 0, 0 ) ), fillColor( Color( 255, 255, 255 ) ) {}

//--------------------------------------------------------

Geometrics::Geometrics(
    int _thickness, const Color& _lineColor, const Color& _fillColor ):
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

//------------------------------------------------------------------------------

void Geometrics::refreshScreen() const {
	al_flip_display();
}

//--------------------------------------------------------

void Geometrics::fillBackground() const {
	al_clear_to_color( fillColor );
}

//--------------------------------------------------------

void Geometrics::drawLine( float x1, float y1, float x2, float y2 ) const {
	al_draw_line( x1, y1, x2, y2, lineColor, thickness );
}

//--------------------------------------------------------

void Geometrics::drawTriangle(
    float x1, float y1, float x2, float y2, float x3, float y3, bool fill ) const {
		
	al_draw_triangle( x1, y1, x2, y2, x3, y3, lineColor, thickness );
	
	if( fill ) 
		al_draw_filled_triangle( x1, y1, x2, y2, x3, y3, fillColor );
}

//--------------------------------------------------------

void Geometrics::drawRectangle( float x, float y, float w, float h, bool fill ) const {
  
	al_draw_rectangle( x, y, x + w, y + h, lineColor, thickness );
	
	if( fill ) {
		const int& aux = thickness / 2;
		al_draw_filled_rectangle( x + aux, y + aux,
		                          x + w - aux, y + h - aux, fillColor );
	}
}

//--------------------------------------------------------

void Geometrics::drawRoundedRectangle(
    float x, float y, float w, float h, float rx, float ry, bool fill ) const {

	al_draw_rounded_rectangle( x, y, x + w, y + h, rx, ry, lineColor, thickness );

	if( fill ) {
		const int& aux = thickness / 4;
		al_draw_filled_rounded_rectangle( x + aux, y + aux,
		                                  x + w - aux, y + h - aux, rx, ry, fillColor );
	}
}

//--------------------------------------------------------

void Geometrics::drawEllipse(
    float cx, float cy, float rx, float ry, bool fill ) const {

	al_draw_ellipse( cx, cy, rx, ry, lineColor, thickness );

	if( fill ) {
		const int& aux = thickness / 2;
		al_draw_filled_ellipse( cx, cy, rx - aux, ry - aux, fillColor );
	}
}

//------------------------------------------	--------------

void Geometrics::drawCircle( float x, float y, float r, bool fill ) const {
  
	al_draw_circle( x, y, r, lineColor, thickness );

	if( fill )
		al_draw_filled_circle( x, y, r - thickness / 2, fillColor );
}

//--------------------------------------------------------

void Geometrics::drawArc( float x, float y, float r, float ia, float da ) const {
	al_draw_arc( x, y, r, ia, da, lineColor, thickness );
}

//--------------------------------------------------------

void Geometrics::drawSpline(
    float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4 ) {
	const float aux[] = {x1, y1, x2, y2, x3, y3, x4, y4};
	al_draw_spline( ( float* )&aux, lineColor, thickness );
}

//--------------------------------------------------------
