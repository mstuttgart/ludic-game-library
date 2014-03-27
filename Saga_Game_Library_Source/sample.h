#pragma once

#include "audio_resource.h"

namespace sgl{

namespace audio{

/**
 * @file sample.h
 * @author Paulo Vicente
 * @date 03/24/14
 * @class Sample
 * @brief
 */

class Sample
{
    private:

        AudioResource* ptr_rsc;
        ALLEGRO_SAMPLE* splAux;
        float gain;
        float  pan;
        float speed;
        ALLEGRO_PLAYMODE loop;

    public:

        enum LOOPING_TYPE{
        Once, Loop, BiDir
        };

        Sample();
        Sample(String fileName);
        Sample(AudioResource* rsc);
        virtual ~Sample();

        bool load(String fileName);
        void play();
        void stopAll();

        void setGain(float g);
        void setPan(float p);
        void setSpeed(float s);
        void setLoopingMode(LOOPING_TYPE l);

        ALLEGRO_SAMPLE* getAllegroSample();


};

}} // end namespaces


