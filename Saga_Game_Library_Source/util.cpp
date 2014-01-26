#include "util.h"
#include <math.h>
using namespace sgl;

//------------------------------------------------------------------------------

int Util::squarePow(int value) {
	
	if(value<0) value=-value; // colocar o value como unsigned int elimina esta linha

	int result=0, delta=1;

	for(int i=0; i<value; i++) {
		result+=delta;
		delta+=2;
	}

	return result;
}

//------------------------------------------

int Util::squareRoot(int value) {
	long square=1, delta=3;

	while(square<=value) {
		square+=delta;
		delta+=2;
	}

	return (delta/2-1);
}
