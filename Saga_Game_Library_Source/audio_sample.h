#pragma once

#include "audio_sample_resource.h"
#include "audio.h"

namespace sgl {
namespace audio {

/**
 * @file sample.h
 * @author Paulo Vicente
 * @date 03/24/14
 * @class Sample
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

}
} // end namespaces
