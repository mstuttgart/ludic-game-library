#include "color.h"

using namespace sgl;

//---------------------------------------------------------------

Color::Color( float red, float green, float blue ) :
	r( red ), g( green ), b( blue ) {}

//---------------------------------------------------------------

Color::Color( const String& html )
{
	al_color_html_to_rgb( html.c_str(), &r, &g, &b );
}

//----------------------------------------------------------------

String Color::getName() const
{
	return al_color_rgb_to_name( r, g, b );
}

//----------------------------------------------------------------

String Color::toHTML() const
{
	char html[8];
	al_color_rgb_to_html( r, g, b, html );
	return html;
}

//----------------------------------------------------------------

void Color::toRGB( int& r, int& g, int& b )
{
	r = this->r;
	g = this->g;
	b = this->b;
}

//----------------------------------------------------------------

Color::operator ALLEGRO_COLOR()
{
	return al_map_rgb( r, g, b );
}

//---------------------------------------------------------------
