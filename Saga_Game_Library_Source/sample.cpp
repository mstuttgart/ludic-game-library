#include "sample.h"

using namespace sgl::audio;

Sample::Sample() : ptr_rsc(nullptr), splAux(nullptr) {}

//------------------------------------------

Sample::Sample(String fileName){

    load(fileName);
    splAux = ptr_rsc->getSamplePtr();
    gain = 0;
    pan = 0;
    speed = 1;
 //   loop = NULL;

}

Sample::~Sample()
{
    //dtor
}

//------------------------------------------

bool Sample::load( String fileName ){

    if ( fileName.empty() ) {

    return false;

    }else{

    ptr_rsc = AudioResource::createAudioResource( fileName, false );

    return true;

    }


}

//------------------------------------------



