#include "Resource.h"

namespace sgl {

Resource::Resource( const char* fileName, void* ptr ) {

	// Inicializamos os atributos da classe
	referenceAmount = 0;
	resourcePtr     = ptr;
	resourceName    = new std::string( fileName );

}

//-----------------------------------------------------------

Resource::~Resource() {
	if( resourceName ) delete resourceName ;
}

//-----------------------------------------------------------

int Resource::getReferenceAmount() const {
	return referenceAmount;
}

//-----------------------------------------------------------

void Resource::incReferenceAmount() {
	referenceAmount++;
}

//-----------------------------------------------------------

void Resource::decReferenceAmount() {
	referenceAmount--;
}

//-----------------------------------------------------------
const void* Resource::getResorcePtr() const
{
	return resourcePtr;
}
//-----------------------------------------------------------

const char* Resource::getResourceName() {
	return resourceName->c_str();
}
//-----------------------------------------------------------

} /* namespace */
