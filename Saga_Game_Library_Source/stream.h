#pragma once

#include "audio_resource.h"

namespace sgl{

namespace audio{

/**
 * @file stream.h
 * @author Paulo Vicente
 * @date 03/28/14
 * @class Stream
 * @brief
 */

class Stream
{
    private:

        AudioResource* ptr_rsc;
        ALLEGRO_AUDIO_STREAM* strAux;


    public:

        enum LOOPING_TYPE{
        Once, Loop, BiDir
        };

        Stream();
        Stream(String fileName);
        Stream(AudioResource* rsc);
        virtual ~Stream();

        bool load(String fileName);
        void play();
        void stop();
        void pause();
        void proceed();
        void rewind();
        bool setSpeed(float speed);
        bool setGain(float gain);
        bool setPan(float pan);
        bool setPlaymode(LOOPING_TYPE l);
        bool setLooping(double ini, double fin);
        bool setBegin(double pos);

        void getStreamInformations();
};

}} // end namespaces
