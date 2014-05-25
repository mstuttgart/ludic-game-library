#include "color.hpp"
#include <math.h>

using namespace sgl;

//---------------------------------------------------------------

Color::Color( float red, float green, float blue ) :
	r( red ), g( green ), b( blue ) {}

//---------------------------------------------------------------

Color::Color( const String& html ) {

	if ( !(al_color_name_to_rgb( html.c_str(), &r, &g, &b) ) ) {
		al_color_html_to_rgb( html.c_str(), &r, &g, &b );
	}

	r *= 255;
	g *= 255;
	b *= 255;

}


//----------------------------------------------------------------

String Color::getName() const {
	return al_color_rgb_to_name( r, g, b );
}

//----------------------------------------------------------------

String Color::toHTML() const {
	char html[8];
	al_color_rgb_to_html( r/255, g/255, b/255, html );
	return html;
}

//----------------------------------------------------------------

void Color::toRGB( int& r, int& g, int& b ) {
	this->r = r;
	this->g = g;
	this->b = b;
}
//----------------------------------------------------------------

Color::operator ALLEGRO_COLOR() const {
	return al_map_rgb( r, g, b );
}

//---------------------------------------------------------------
