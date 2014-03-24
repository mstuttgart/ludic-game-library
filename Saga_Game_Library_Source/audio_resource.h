#pragma once

#include "resource.h"

namespace sgl{
namespace audio{

/**
 * @file audio_resource.h
 * @author Paulo Vicente
 * @date 03/22/14
 * @class AudioResource
 * @brief
 */

class AudioResource : public Resource {


    protected:
        AudioResource(String fileName, void* audio);
        virtual ~AudioResource();
    public:
        static AudioResource* createAudioResource(String fileName, bool aux );
        ALLEGRO_SAMPLE* getSamplePtr();
        ALLEGRO_AUDIO_STREAM* getStreamPtr();


};

}}

