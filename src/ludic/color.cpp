#include "color.hpp"
#include <math.h>

using namespace Ludic;

//////////////////////////////////////////////////////////////////

Color::Color() : red( 0 ), green( 0 ), blue( 0 ) {}

//////////////////////////////////////////////////////////////////

Color::Color( unsigned char _red, unsigned char _green, unsigned char _blue ) :
	red( _red ), green( _green ), blue( _blue ) {}

//////////////////////////////////////////////////////////////////

Color::Color( const String& html )
{
	// Variaveis auxiliares
	float r, g, b;
	
	if ( !(al_color_name_to_rgb( html.c_str(), &r, &g, &b) ) ) {
		al_color_html_to_rgb( html.c_str(), &r, &g, &b );
	}

	red   = r * 255;
	green = g * 255;
	blue  = b * 255;

}


//////////////////////////////////////////////////////////////////

String Color::getName() const
{
	return al_color_rgb_to_name( red/255.0, green/255.0, blue/255.0 );
}

//////////////////////////////////////////////////////////////////

String Color::toHTML() const
{
	char html[8];
	al_color_rgb_to_html( red/255.0, green/255.0, blue/255.0, html );
	return html;
}

//////////////////////////////////////////////////////////////////

void Color::toRGB( unsigned char& r, unsigned char& g, unsigned char& b )
{
	r = this->red;
	g = this->green;
	b = this->blue;
}
//////////////////////////////////////////////////////////////////

Color::operator ALLEGRO_COLOR() const
{
	return al_map_rgb( red, green, blue );
}

//////////////////////////////////////////////////////////////////

void Color::setRGB(unsigned char red, unsigned char green, unsigned char blue)
{
	this->red   = red;
	this->green = green;
	this->blue  = blue;
}

///////////////////////////////////////////////////////////////////
