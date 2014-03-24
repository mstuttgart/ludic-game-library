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

        Sample();
        Sample(String fileName);
        virtual ~Sample();
        bool load(String fileName);
        void play();
        void stopAll();
        ALLEGRO_SAMPLE* getAllegroSample();
        void getSampleInformation();
};

}} // end namespaces


