#include "decompressor.h"

using namespace std;

//------------------------------------------------------------------

bool GZIP_Decompressor( const String& compressedBytes, String& uncompressedBytes ) {

	if ( compressedBytes.size() == 0 ) {
		uncompressedBytes = compressedBytes ;
		return true ;
	}

	uncompressedBytes.clear() ;

	unsigned full_length = compressedBytes.size() ;
	unsigned half_length = compressedBytes.size() / 2;

	unsigned uncompLength = full_length;

	char* uncomp = new char[uncompLength];

	z_stream strm;
	strm.next_in   = ( Bytef * ) compressedBytes.c_str();
	strm.avail_in  = compressedBytes.size() ;
	strm.total_out = 0;
	strm.zalloc    = Z_NULL;
	strm.zfree     = Z_NULL;

	bool done = false ;

	if ( inflateInit2( &strm, ( 16 + MAX_WBITS ) ) != Z_OK ) {
		delete uncomp;
		return false;
	}

	while ( !done ) {

		// If our output buffer is too small
		if ( strm.total_out >= uncompLength ) {

			// Increase size of output buffer
			char* uncomp2 = new char[ uncompLength + half_length ];
			memcpy( uncomp2, uncomp, uncompLength );
			
			uncompLength += half_length ;
			
			delete uncomp;
			
			uncomp = uncomp2 ;
		}

		strm.next_out  = ( Bytef * ) ( uncomp + strm.total_out );
		strm.avail_out = uncompLength - strm.total_out;

		// Inflate another chunk.
		int err = inflate ( &strm, Z_SYNC_FLUSH );
		
		if ( err == Z_STREAM_END ) {
			done = true;
		}
		else if ( err != Z_OK )  {
			break;
		}
		
	}

	if ( inflateEnd ( &strm ) != Z_OK ) {
		delete uncomp;
		return false;
	}

	for ( size_t i = 0; i < strm.total_out; ++i ) {
		uncompressedBytes += uncomp[ i ];
	}

	delete uncomp;

	return true ;
}

//------------------------------------------------------------------

bool ZLIB_Decompressor( const String& strIn, String& strOut )
{
	strOut.clear();
	
	// z_stream is zlib's control structure
	z_stream zs;
	memset( &zs, 0, sizeof( zs ) );

	if ( inflateInit( &zs ) != Z_OK )
	{
		throw( runtime_error( "inflateInit failed while decompressing." ) );
		return false;
	}
		
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
		ostringstream oss;
		oss << "Exception during zlib decompression: (" << ret << ") "
		    << zs.msg;
		throw( runtime_error( oss.str() ) );
		return false;
	}//if
	
	return true;
}