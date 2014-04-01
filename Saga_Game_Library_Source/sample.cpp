#include "sample.h"
#include <iostream>

using namespace sgl::audio;

Sample::Sample() : ptr_rsc(nullptr), splAux(nullptr) {}

//------------------------------------------

Sample::Sample(String fileName){

    load(fileName);
    splAux = ptr_rsc->getSamplePtr();
    gain = 1;
    pan = ALLEGRO_AUDIO_PAN_NONE;
    speed = 1;
    loop = ALLEGRO_PLAYMODE_ONCE;

}

//------------------------------------------

Sample::Sample(AudioResource* rsc){
   if(rsc){
     ptr_rsc = rsc;
     splAux = ptr_rsc->getSamplePtr();
     gain = 1;
     pan = ALLEGRO_AUDIO_PAN_NONE;
     speed = 1;
     loop = ALLEGRO_PLAYMODE_ONCE;
}

  }

//------------------------------------------

Sample::~Sample()
{
    //dtor
}

//------------------------------------------

bool Sample::load( String fileName ){

    if ( fileName.empty() ) {

    return false;

    }else{
    if (!al_reserve_samples(2)) return false;
    ptr_rsc = AudioResource::createAudioResource( fileName, false, 0, 0 );

    return true;

    }


}

//------------------------------------------

void Sample::play(){

al_play_sample(splAux, gain, pan, speed, loop, NULL);


}

//------------------------------------------

void Sample::stopAll(){

al_stop_samples();

}

//------------------------------------------

void Sample::setGain(float g){
gain = g;

}

//------------------------------------------
void Sample::setPan(float p){
    try{
        if((p<-1) || (p>1)){
            sgl::Exception ex( "Error: pan must be in a range of -1.0 and 1.0");
            throw ex;
         }

            }
              catch( sgl::Exception ex ) {
			    std::cout << ex.what() << std::endl;
		        }

    pan = p;

}

//------------------------------------------

void Sample::setSpeed(float s){
     try{
        if( s<0 ){
            sgl::Exception ex( "Error: speed must be a positive value.");
            throw ex;
         }

            }
              catch( sgl::Exception ex ) {
			    std::cout << ex.what() << std::endl;
		        }



speed = s;

}

//------------------------------------------

void Sample::setLoopingMode(LOOPING_TYPE l){

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

//------------------------------------------

ALLEGRO_SAMPLE* Sample::getAllegroSample(){

return splAux;

}

//------------------------------------------
