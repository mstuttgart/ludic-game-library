/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is a FREE SOFTWARE released under the BSD License.              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "audio_sample_resource.hpp"
#include "audio.hpp"

namespace Ludic {

/**
 * @file audio_sample.hpp
 * @author Paulo Vicente
 * @date 03/24/14
 * @class AudioSample
 * @brief This class represents a interface to manipulate
 * AudioResources, using it like audioSamples.
 */
class AudioSample : public Audio {

private:

	AudioSampleResource* sampleRsc;
	AudioPlayMode loop;

public:

	/**
	 * @brief Default Constructor
	 */
	AudioSample();

	/**
	 * @brief Parameter constructor. Load
	 * a AudioSample file from audio file. Support 
	 * of several audio formates: .wav, .flac, .ogg, .it, .mod, .s3m, .xm. 
	 * @param fileName the name of audio file. 
	 */
	AudioSample( const String& fileName);

	/**
	 * @brief Default Destructor.
	 */
	virtual ~AudioSample();

	/**
	 * @brief Load a AudioSample file from audio file. Support 
	 * of several audio formates: .wav, .flac, .ogg, .it, .mod, .s3m, .xm. 
	 * @param fileName name of audio file.
	 * @return True if load sucessfull, otherwise False.
	 */
	bool load(const String& fileName);

	/**
	 * @brief Play AudioSample audio.
	 */
	void play();

	/**
	 * @brief Stop All AudioSamples that is playing.
	 */
	void stopAll();

	/**
	 * @brief Set the gain of AudioSample
	 * @param g gain value
	 */
	void setGain(float g);

	/**
	 * @brief Set the value of AudioSample.
	 * @param p pan value.
	 */
	void setPan(float p);

	/**
	 * @brief Set the speed of AudioSample reprodution.
	 * @param s speed value.
	 */
	void setSpeed( float s);

	/**
	 * @brief Set the loop mode. 
	 * @param l loop mode type.
	 * @see AudioPlayMode
	 */
	void setLoopingMode( AudioPlayMode l );

	/**
	 * @brief Return a pointer to SampleResource instance of
	 * this AudioSample.
	 * @return a pointer to SampleResource object.
	 */
	const AudioSampleResource* getSampleResource() const;

};

} // end namespaces
