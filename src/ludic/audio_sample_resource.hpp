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

#include "audio_resource.hpp" // Base class: sgl::Resource

namespace Ludic {

/**
 * @file audio_sample_resource.h
 * @author Paulo Vicente e Michell Stuttgart
 * @date 04/17/14
 * @class AudioSampleResource
 * @brief
 */
class AudioSampleResource : public AudioResource {

private:

	/**
	 * @brief
	 * @param fileName
	 * @param audio
	 */
	AudioSampleResource( const String& fileName, ALLEGRO_SAMPLE* audio );

	/**
	 * @brief
	 * @return
	 */
	ALLEGRO_SAMPLE* getSample();

public:

	/**
	 * @brief
	 */
	virtual ~AudioSampleResource();

	/**
	 * @brief
	 * @param fileName
	 * @return
	 */
	static AudioSampleResource* createSampleResource( const String& fileName );

	/**
	 * @brief
	 * @return
	 */
	operator ALLEGRO_SAMPLE*();

};

} /* namespace */
