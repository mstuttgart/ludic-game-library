#include "stream.h"
#include <iostream>


using namespace sgl::audio;

Stream::Stream() : ptr_rsc(nullptr), strAux(nullptr) {}

//-----------------------------------------------------

Stream::Stream(String fileName, size_t buff, unsigned int samples){

   load(fileName, buff, samples);
   strAux = ptr_rsc->getStreamPtr();

}

//-----------------------------------------------------

Stream::~Stream()
{
    //dtor
}

//-----------------------------------------------------

bool Stream::load(String fileName, size_t buff, unsigned int samples){

if ( fileName.empty() ) {

    return false;

    }else{
    if (!al_reserve_samples(2)) return false;
    ptr_rsc = AudioResource::createAudioResource( fileName, true, buff, samples );

    return true;

    }


}

//-----------------------------------------------------

void Stream::play(){


   al_attach_audio_stream_to_mixer(strAux, al_get_default_mixer());
   al_set_audio_stream_playing(strAux, true);

}

//-----------------------------------------------------

void Stream::stop(){

    al_drain_audio_stream(strAux);
    al_rewind_audio_stream(strAux);


}

//-----------------------------------------------------

void Stream::pause(){

al_set_audio_stream_playing(strAux, false);


}

//-----------------------------------------------------

void Stream::proceed(){

al_set_audio_stream_playing(strAux, true);

}

//-----------------------------------------------------

void Stream::rewind(){

al_rewind_audio_stream(strAux);

}

//-----------------------------------------------------

bool Stream::setSpeed(float speed){

return al_set_audio_stream_speed(strAux, speed);

}

//-----------------------------------------------------

bool Stream::setGain(float gain){

return al_set_audio_stream_gain(strAux, gain);

}

//-----------------------------------------------------

bool Stream::setPan(float pan){

return al_set_audio_stream_pan(strAux, pan);

}

//-----------------------------------------------------

bool Stream::setPlaymode(LOOPING_TYPE l){

ALLEGRO_PLAYMODE loop;

switch (l){
case Once:
    loop = ALLEGRO_PLAYMODE_ONCE;
    break;
case Loop:
    loop = ALLEGRO_PLAYMODE_LOOP;
    break;
case BiDir:
    loop = ALLEGRO_PLAYMODE_BIDIR;
    break;

  }

return al_set_audio_stream_playmode(strAux, loop);

}

//-----------------------------------------------------

bool Stream::setLooping(double ini, double fin){

return al_set_audio_stream_loop_secs(strAux, ini, fin);


}

//-----------------------------------------------------

bool Stream::setBegin(double pos){

return al_seek_audio_stream_secs(strAux, pos);

}
