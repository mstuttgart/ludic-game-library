#pragma once

#include "audio_resource.h"
#include "audio.h"

namespace sgl{

namespace audio{

/**
 * @file stream.h
 * @author Paulo Vicente
 * @date 03/28/14
 * @class Stream
 * @brief
 */

class Stream : public Audio
{
    private:

        ALLEGRO_AUDIO_STREAM* strAux;


    public:

        Stream();
        Stream(String fileName, size_t buff, unsigned int samples);
        Stream(AudioResource* rsc);
        virtual ~Stream();

        bool load(String fileName, size_t buff, unsigned int samples);
        virtual void play() const;
        void stop();
        void pause();
        void proceed();
        void rewind();


        void setGain(float gain);
        void setPan(float pan);
        void setSpeed(float speed);
        void setLoopingMode(LOOPING_TYPE l);

        void setLooping(double ini, double fin);
        void setBegin(double pos);

};

}} // end namespaces
