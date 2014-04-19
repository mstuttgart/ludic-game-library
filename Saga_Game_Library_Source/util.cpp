#include "util.h"
#include "base64/base64.h"
#include "gzip/decompressor.h"

#include <math.h>
#include <vector>

using namespace sgl;
using namespace std;
//------------------------------------------------------------------------------

int Util::squarePow( int value ) {

	if( value < 0 ) value = -value; // colocar o value como unsigned int elimina esta linha

	int result = 0, delta = 1;

	for( int i = 0; i < value; i++ ) {
		result += delta;
		delta += 2;
	}

	return result;
}

//------------------------------------------

int Util::squareRoot( int value ) {
	long square = 1, delta = 3;

	while( square <= value ) {
		square += delta;
		delta += 2;
	}

	return ( delta / 2 - 1 );
}

//----------------------------------------------------------------

void Util::decodeBase64( const String& strIn, String& strOut ) {
	
	// Limpamos a string que recebera a entrada decodificada
	strOut.clear();

	// Recebemos a strIn decodificada
	strOut = base64_decode( strIn );
}

//-----------------------------------------------------------------

void Util::decompressZLIB( const String& strIn, String& strOut ) {
	ZLIB_Decompressor( strIn, strOut );
}

//------------------------------------------

void Util::decompressGZIP( const String& strIn, String& strOut ) {
	GZIP_Decompressor( strIn, strOut );
}

//------------------------------------------
