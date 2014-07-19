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
 * @file audio_stream_resource.h
 * @author Paulo Vicente e Michell Stuttgart
 * @date 04/17/14
 * @class AudioStreamResource
 * @brief
 */
class AudioStreamResource : public AudioResource {

private:

	unsigned int buff;
	unsigned int samples;

private:

	/**
	 * @brief
	 * @param fileName
	 * @param stream
	 * @param _buff
	 * @param _samples
	 */
	AudioStreamResource( const String& fileName, ALLEGRO_AUDIO_STREAM* stream,
	                     unsigned int& _buff, unsigned int& _samples );

	/**
	 * @brief
	 * @return
	 */
	ALLEGRO_AUDIO_STREAM* getStream();

public:

	/**
	 * @brief
	 */
	virtual ~AudioStreamResource();

	/**
	 * @brief
	 * @param fileName
	 * @param buff
	 * @param samples
	 * @return
	 */
	static AudioStreamResource* createAudioStreamResource(
	    const String& fileName,
		unsigned int buff,
		unsigned int samples );

	/**
	 * @brief
	 * @return
	 */
	unsigned int getBuff() const;

	/**
	 * @brief
	 * @return
	 */
	unsigned int getSamples() const;

	/**
	 * @brief
	 * @return
	 */
	operator ALLEGRO_AUDIO_STREAM*();

};

} /* namespace */
