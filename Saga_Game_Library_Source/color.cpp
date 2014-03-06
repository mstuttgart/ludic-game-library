#include "color.h"

using namespace sgl;

//---------------------------------------------------------------

ALLEGRO_COLOR Color::getColorOf_HTML( char const* html ) {
	return al_color_html( html );
}

//---------------------------------------------------------------

ALLEGRO_COLOR Color::getColorOf_RGB(char r, char g, char b) {
	return al_map_rgb( r, g, b );
}

//---------------------------------------------------------------

ALLEGRO_COLOR Color::getColorOf_Name(char const* name) {
	return al_color_name( name );
}

//---------------------------------------------------------------

void Color::convert_HTML_To_RGB(char const* html,
                                float* r, float* g, float* b) {
	return al_color_html_to_rgb( html, r, g, b );
}

//--------------------------------------------------------------

bool Color::convert_Name_To_RGB( char const* name,
                                 float* r, float* g, float* b ) {
	return al_color_name_to_rgb( name, r, g, b );
}

//---------------------------------------------------------------

char const* Color::convert_RGB_To_HTML(float r, float g, float b ) {

	char* html = nullptr;
	al_color_rgb_to_html( r, g, b, html );

	return html;
}

//---------------------------------------------------------------

char const* Color::convert_Name_To_HTML( char const *name ) {
	
	float r, g, b;
	Color::convert_Name_To_RGB( name, &r, &g, &b );

	return Color::convert_RGB_To_HTML( r, g, b );

}

//---------------------------------------------------------------

char const* Color::convert_HTML_To_Name( char const* html ) {
	
	float r, g, b;
	Color::convert_HTML_To_RGB( html, &r, &g, &b );
	
	return Color::convert_RGB_To_Name( r, g, b );
}

//---------------------------------------------------------------

char const* Color::convert_RGB_To_Name(float r, float g, float b) {
	return al_color_rgb_to_name( r, g, b);
}

//---------------------------------------------------------------
