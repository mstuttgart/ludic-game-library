#include "resource.h"

using namespace sgl;

//----------------------------------------------------------

Resource::Resource( const String& fileName, void* ptr ) : resourcePtr( ptr ),
resourceName( fileName ), released(true){}

//---------------------------------------------------------

Resource::~Resource() {
	resourcePtr = nullptr;
}

//-----------------------------------------------------------

void* Resource::getResourcePtr() const {
	return resourcePtr;
}

//-----------------------------------------------------------

const String& Resource::getResourceName() {
	return resourceName;
}

//-----------------------------------------------------------

void Resource::setReleased(bool released) {
	this->released = released;
}

//-----------------------------------------------------------

bool Resource::isReleased() const {
	return released;
}

//----------------------------------------------------------
