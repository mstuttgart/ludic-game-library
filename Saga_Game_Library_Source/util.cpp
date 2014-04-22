#include "util.h"
#include "base64/base64.h"
#include "gzip/decompressor.h"

#include <math.h>
#include <vector>
#include <locale>

using namespace sgl;
using namespace std;

//----------------------------------------------------------------

int Util::squarePow( unsigned value ) {

	int result = 0;
	int delta  = 1;

	for( unsigned int i = 0; i < value; i++ ) {
		result += delta;
		delta  += 2;
	}

	return result;
}

//----------------------------------------------------------------

int Util::squareRoot( int value ) {

	long square = 1;
	long delta  = 3;

	while( square <= value ) {
		square += delta;
		delta  += 2;
	}

	return ( delta * 0.5 - 1 );
}

//----------------------------------------------------------------

String Util::toLower( const String& str ) {

	// String que recebe a string em lowcase
	String result;
	locale loc;

	// Realizamos a conversao
	for ( unsigned int i = 0; i < str.length(); ++i ) {
		result += std::tolower( str.at( i ), loc );
	}

	return result;
}

//----------------------------------------------------------------

String Util::toUpper( const String& str ) {

	// String que recebe a string em lowcase
	String result;
	locale loc;

	// Realizamos a conversao
	for ( unsigned int i = 0; i < str.length(); ++i ) {
		result += std::toupper( str.at( i ), loc );
	}

	return result;
}

//----------------------------------------------------------------

void Util::decodeBase64( const String& strIn, String& strOut ) {
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
