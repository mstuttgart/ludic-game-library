#include "exception.h"

//-----------------------------------------

namespace sgl {
	
const char* Exception::getError( EXCEPTION& exIndex ) {

	const char* error[] = {
		"Failed to initialize ALLEGRO.",
		"Failed to initialize ALLEGRO_IMAGE.",
		"Failed to initialize ALLEGRO_TTF.",
		"Failed to initialize ALLEGRO_AUDIO.",
		"Failed to initialize ALLEGRO_PRIMITIVES.",
		"Failed to initialize ALLEGRO_KEYBOARD.",
		"Failed to initialize ALLEGRO_MOUSE.",
		"Failed to create ALLEGRO_DISPLAY.",
		"Failed to create ALLEGRO_BITMAP.",
		"Invalid path specified."
		"An unknown error occurred."
	};

	return ( exIndex < EXCEPTION::count ) ? error[ exIndex ] : error[ EXCEPTION::count - 1 ];

}

} /*namespace */
