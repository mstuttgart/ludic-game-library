#include "stream.h"
#include <iostream>


using namespace sgl::audio;

Stream::Stream() : Audio(), strAux(nullptr) {}

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
    if (!al_reserve_samples(1)) return false;
    ptr_rsc = AudioResource::createAudioResource( fileName, true, buff, samples );

    return true;

    }


}

//-----------------------------------------------------

void Stream::play() const{


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

void Stream::setSpeed(float speed){

al_set_audio_stream_speed(strAux, speed);

}

//-----------------------------------------------------

void Stream::setGain(float gain){

al_set_audio_stream_gain(strAux, gain);

}

//-----------------------------------------------------

void Stream::setPan(float pan){

al_set_audio_stream_pan(strAux, pan);

}

//-----------------------------------------------------

void Stream::setLoopingMode(LOOPING_TYPE l){

Audio::setLoopingMode(l);
al_set_audio_stream_playmode(strAux, loop);

}

//-----------------------------------------------------

void Stream::setLooping(double ini, double fin){

al_set_audio_stream_loop_secs(strAux, ini, fin);


}

//-----------------------------------------------------

void Stream::setBegin(double pos){

al_seek_audio_stream_secs(strAux, pos);

}
