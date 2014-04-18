#pragma once

#include "audio_stream_resource.h"
#include "audio.h"

namespace sgl {

namespace audio {

/**
 * @file stream.h
 * @author Paulo Vicente
 * @date 03/28/14
 * @class Stream
 * @brief
 */
class AudioStream : public Audio {
	
private:

	AudioStreamResource* streamRsc;
	bool stopped;
	bool paused;

public:

	/**
	 * @brief 
	 */
	AudioStream();
	
	/**
	 * @brief 
	 */
	AudioStream( const String& fileName, unsigned int buff, unsigned int samples );
	
	/**
	 * @brief 
	 */
	virtual ~AudioStream();

	/**
	 * @brief 
	 * @param fileName
	 * @param buff
	 * @param samples
	 * @return 
	 */
	bool load( const String& fileName, unsigned int buff, unsigned int samples );
	
	/**
	 * @brief 
	 */
	void play();
	
	/**
	 * @brief 
	 */
	void pause();
	
	/**
	 * @brief 
	 * @param gain
	 */
	void stop();
	
	/**
	 * @brief 
	 * @param gain
	 */
	void setGain( float gain );
	
	/**
	 * @brief 
	 * @param speed
	 */
	void setPan( float pan );
	
	/**
	 * @brief 
	 * @param speed
	 */
	void setSpeed( float speed );

	/**
	 * @brief 
	 * @param l
	 */
	void setLoopingMode( AudioPlayMode l );

	/**
	 * @brief 
	 * @param ini
	 * @param fin
	 */
	void setLooping( double ini, double fin );
	
	/**
	 * @brief 
	 * @param pos
	 */
	void setBegin( double pos );
	
	/**
	 * @brief 
	 * @return 
	 */
	bool isPlaying() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	bool isPaused() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	bool isStopped() const;

};

}
} // end namespaces
