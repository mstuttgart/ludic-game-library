#include "audio.h"

using namespace sgl::audio;

Audio::Audio(): ptr_rsc(nullptr){}

//------------------------------------------

Audio::~Audio(){} //dtor

//------------------------------------------

void Audio::setLoopingMode(LOOPING_TYPE l) {

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



}
