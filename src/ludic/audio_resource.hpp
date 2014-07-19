/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is FREE SOFTWARE released under the BSD License.                //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "resource.hpp"

namespace Ludic {

/**
 * @file audio_resource.h
 * @author Paulo Vicente
 * @date 03/22/14
 * @class AudioResource
 * @brief
 */
class AudioResource : public Resource {

private:

	static int samplesSize;

protected:

	/**
	 * @brief
	 * @param fileName
	 * @param audio
	 */
	AudioResource( const String& fileName, void* audio );

public:

	/**
	 * @brief
	 */
	virtual ~AudioResource(){};

	/**
	 * @brief
	 */
	static void incSamplesSize();

	/**
	 * @brief
	 */
	static void decSamplesSize();

	/**
	 * @brief
	 * @return
	 */
	static int getSamplesSize();

};

}