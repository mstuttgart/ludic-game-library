#pragma once

#include "audio_resource.h"

namespace sgl{

namespace audio{

/**
 * @file audio.h
 * @author Paulo Vicente
 * @date 04/10/14
 * @class Audio
 * @brief
 */

class Audio
{
    private:


    public:

        Audio();
        virtual ~Audio();

        enum LOOPING_TYPE{
        Once, Loop, BiDir
        };


        AudioResource* ptr_rsc;
        ALLEGRO_PLAYMODE loop;

        virtual void play() const = 0;

        void setGain(float g);
        void setPan(float p);
        void setSpeed(float s);
        void setLoopingMode(LOOPING_TYPE l);

};

}} // end namespaces
