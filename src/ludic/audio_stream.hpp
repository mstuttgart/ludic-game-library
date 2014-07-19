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

#include "audio_stream_resource.hpp"
#include "audio.hpp"

namespace Ludic {

/**
 * @file audio_stream.h
 * @author Paulo Vicente
 * @date 03/28/14
 * @class AudioStream
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
	 * @param fileName
	 * @param buff
	 * @param samples
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
	 */
	void stop();

	/**
	 * @brief
	 * @param gain
	 */
	void setGain( float gain );

	/**
	 * @brief
	 * @param pan
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

} // end namespaces
