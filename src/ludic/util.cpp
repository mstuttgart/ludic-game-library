#include "util.hpp"
#include "base64/base64.h"
#include "gzip/decompressor.h"

#include <cmath>
#include <vector>
#include <locale>

using namespace sgl;
using namespace std;

//////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////

void Util::decodeBase64( const String& strIn, String& strOut ) {
	strOut = base64_decode( strIn );
}

//////////////////////////////////////////////////////////////

void Util::decompressZLIB( const String& strIn, String& strOut ) {
	ZLIB_Decompressor( strIn, strOut );
}

//////////////////////////////////////////////////////////////

void Util::decompressGZIP( const String& strIn, String& strOut ) {
	GZIP_Decompressor( strIn, strOut );
}

//////////////////////////////////////////////////////////////

float Util::ceilFloat(float value) {
	return ceilf( value );
}

//////////////////////////////////////////////////////////////

float Util::floorFloat(float value) {
	return floorf( value );
}

//////////////////////////////////////////////////////////////
