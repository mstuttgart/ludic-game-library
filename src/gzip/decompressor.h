/*
This C++ program uses zlib to read then decompress a gzipped file in memory.
Author: Andrew Lim Chong Liang
http://windrealm.org
*/
#pragma once

#include "zlib.h"
#include "zconf.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <cstdlib>

typedef std::string String;

/**
 * @brief This C++ program uses zlib to read then decompress a gzipped file in memory.
 * Author: Andrew Lim Chong Liang
 * http://windrealm.org
 * 
 * @param compressedBytes
 * @param uncompressedBytes
 * @return 
 */
bool GZIP_Decompressor( const String& compressedBytes, String& uncompressedBytes );

/**
 * @brief Copyright 2007 Timo Bingmann <tb@panthema.net>
 * Distributed under the Boost Software License, Version 1.0.
 * (See http://www.boost.org/LICENSE_1_0.txt)
 * 
 * @param strIn
 * @param strOut
 */
bool ZLIB_Decompressor( const String& strIn, String& strOut );