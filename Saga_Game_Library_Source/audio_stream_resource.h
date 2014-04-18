#pragma once

#include "audio_resource.h" // Base class: sgl::Resource

namespace sgl {
namespace audio {

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

}
} /* namespace */
