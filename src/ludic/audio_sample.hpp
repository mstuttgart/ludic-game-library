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
 * @brief
 */
class AudioSample : public Audio {

private:

	AudioSampleResource* sampleRsc;
	AudioPlayMode loop;

public:

	/**
	 * @brief
	 */
	AudioSample();

	/**
	 * @brief
	 * @param fileName
	 */
	AudioSample( const String& fileName);

	/**
	 * @brief
	 */
	virtual ~AudioSample();

	/**
	 * @brief
	 * @param fileName
	 * @return
	 */
	bool load(const String& fileName);

	/**
	 * @brief
	 */
	void play();

	/**
	 * @brief
	 */
	void stopAll();

	/**
	 * @brief
	 * @param g
	 */
	void setGain(float g);

	/**
	 * @brief
	 * @param s
	 */
	void setPan(float p);

	/**
	 * @brief
	 * @param s
	 */
	void setSpeed( float s);

	/**
	 * @brief
	 * @param l
	 */
	void setLoopingMode( AudioPlayMode l );

	/**
	 * @brief
	 * @return
	 */
	const AudioSampleResource* getSampleResource() const;

};

} // end namespaces
