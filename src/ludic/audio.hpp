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

#include "audio_resource.hpp"

namespace Ludic
{

enum class AudioPlayMode
{
    PLAY_ONCE  = ALLEGRO_PLAYMODE_ONCE,
    PLAY_LOOP  = ALLEGRO_PLAYMODE_LOOP,
    PLAY_BIDIR = ALLEGRO_PLAYMODE_BIDIR
};

/**
 * @file audio.hpp
 * @author Paulo Vicente
 * @date 04/17/14
 * @class Audio
 * @brief This class represent a interface to manipulate audio files.
 */
class Audio
{

protected:

	float gain;
	float pan;
	float speed;

	ALLEGRO_MIXER* mixer;
	static bool active;

public:

	/**
	 * @brief Default Constructor
	 */
	Audio();

	/**
	 * @brief Default Destructor
	 */
	virtual ~Audio();

	/**
	 * @brief Abstract Method. Used to play audio file.
	 */
	virtual void play() = 0;

	/**
	 * @brief Set the gain of audio.
	 * @param g the gain value.
	 */
	virtual void setGain( float g ) = 0;

	/**
	 * @brief Set the pan of audio.
	 * @param s the pan value.
	 */
	virtual void setPan( float p ) = 0;

	/**
	 * @brief Set the speed of audio reprodution.
	 * @param s the speed value.
	 */
	virtual void setSpeed( float s ) = 0;

	/**
	 * @brief Set the looping mode of audio.
	 * @param l the loop type.
	 * @see AudioPlayMode
	 */
	virtual void setLoopingMode( AudioPlayMode l ) = 0;

	/**
	 * @brief Get the gain of audio.
	 * @return value of gain.
	 */
	float getGain() const;

	/**
	 * @brief Get the pan value of audio.
	 * @return the pan value.
	 */
	float getPan() const;

	/**
	 * @brief Get the speed reprodution of audio.
	 * @return the value of speed reprodution.
	 */
	float getSpeed() const;

};

} /* namespace */
