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
 * @file audio.h
 * @author Paulo Vicente
 * @date 04/17/14
 * @class Audio
 * @brief
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
	 * @brief
	 */
	Audio();

	/**
	 * @brief
	 */
	virtual ~Audio();

	/**
	 * @brief
	 */
	virtual void play() = 0;

	/**
	 * @brief
	 * @param g
	 */
	virtual void setGain( float g ) = 0;

	/**
	 * @brief
	 * @param s
	 */
	virtual void setPan( float p ) = 0;

	/**
	 * @brief
	 * @param s
	 */
	virtual void setSpeed( float s ) = 0;

	/**
	 * @brief
	 * @param l
	 */
	virtual void setLoopingMode( AudioPlayMode l ) = 0;

	/**
	 * @brief
	 * @return
	 */
	float getGain() const;

	/**
	 * @brief
	 * @return
	 */
	float getPan() const;

	/**
	 * @brief
	 * @return
	 */
	float getSpeed() const;

};

} /* namespace */
