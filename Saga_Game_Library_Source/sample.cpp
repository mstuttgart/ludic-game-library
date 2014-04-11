#include "sample.h"
#include <iostream>

using namespace sgl::audio;

unsigned int Sample::num_samples = 0;

Sample::Sample() : Audio(), splAux(nullptr) {}

//------------------------------------------

Sample::Sample(String fileName){

    num_samples++;
    load(fileName);
    splAux = ptr_rsc->getSamplePtr();
    gain = 1;
    pan = ALLEGRO_AUDIO_PAN_NONE;
    speed = 1;
    loop = ALLEGRO_PLAYMODE_ONCE;

}

unsigned int Sample::getNumSamples(){ return num_samples; };

//------------------------------------------

Sample::Sample(AudioResource* rsc){
   if(rsc){

     num_samples++;
     al_reserve_samples(num_samples);
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
    num_samples--;
    al_reserve_samples(num_samples);

}

//------------------------------------------

bool Sample::load( String fileName ){

    if ( fileName.empty() ) {

    return false;

    }else{
    if (!al_reserve_samples(num_samples)) return false;
    ptr_rsc = AudioResource::createAudioResource( fileName, false, 0, 0 );

    return true;

    }


}

//------------------------------------------

void Sample::play() const{

al_play_sample(splAux, gain, pan, speed, loop, NULL);


}

//------------------------------------------

void Sample::stopAll(){

al_stop_samples();

}

//------------------------------------------

void Sample::setGain(float g) {
 gain = g;

}

//------------------------------------------
void Sample::setPan(float p) {
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

void Sample::setSpeed(float s) {
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

ALLEGRO_SAMPLE* Sample::getAllegroSample(){

return splAux;

}


//------------------------------------------
