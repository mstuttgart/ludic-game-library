#pragma once

#include "audio_resource.h" // Base class: sgl::Resource

namespace sgl {
namespace audio {

/**
 * @class AudioSampleResource
 * @author Paulo Vicente e Michell Stuttgart
 * @date 04/17/14
 * @file audio_sample_resource.h
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
	 */
	operator ALLEGRO_SAMPLE*();

};

}
} /* namespace */
