#pragma once

#include "audio_resource.h"
#include "audio.h"

namespace sgl{

namespace audio{

/**
 * @file sample.h
 * @author Paulo Vicente
 * @date 03/24/14
 * @class Sample
 * @brief
 */

class Sample : public Audio
{
    private:

        ALLEGRO_SAMPLE* splAux;
        float gain;
        float  pan;
        float speed;
        static unsigned int num_samples;


    public:

        Sample();
        Sample(String fileName);
        Sample(AudioResource* rsc);
        virtual ~Sample();

        bool load(String fileName);

        virtual void play() const;
        void stopAll();

        void setGain(float g);
        void setPan(float p);
        void setSpeed(float s);

        static unsigned int getNumSamples();

        ALLEGRO_SAMPLE* getAllegroSample();


};

}} // end namespaces


