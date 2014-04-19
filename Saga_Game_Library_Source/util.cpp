#include "util.h"
#include "zlib.h"
#include "base64/base64.h"
#include "gzip/gzip.h"

#include <sstream>
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
	
	// z_stream is zlib's control structure
	z_stream zs;
	memset( &zs, 0, sizeof( zs ) );

	if ( inflateInit( &zs ) != Z_OK )
		throw(
		    std::runtime_error( "inflateInit failed while decompressing." ) );

	zs.next_in = ( Bytef* )strIn.data();
	zs.avail_in = strIn.size();

	int ret;
	char outbuffer[32768];

	// get the decompressed bytes blockwise using repeated calls to inflate
	do {
		zs.next_out = reinterpret_cast<Bytef*>( outbuffer );
		zs.avail_out = sizeof( outbuffer );

		ret = inflate( &zs, 0 );

		if ( strOut.size() < zs.total_out ) {
			strOut.append( outbuffer, zs.total_out - strOut.size() );
		}

	}
	while ( ret == Z_OK );

	inflateEnd( &zs );

	if ( ret != Z_STREAM_END ) {        // an error occurred that was not EOF
		std::ostringstream oss;
		oss << "Exception during zlib decompression: (" << ret << ") "
		    << zs.msg;
		throw( std::runtime_error( oss.str() ) );
	}//if

}

//------------------------------------------

void Util::decompressGZIP( const String& strIn, String& strOut ) {
	decompress( strIn, strOut );
}
