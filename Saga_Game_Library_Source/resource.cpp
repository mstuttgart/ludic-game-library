#include "resource.h"

using namespace sgl;

//----------------------------------------------------------

Resource::Resource( const String& fileName, void* ptr ) : resourcePtr( ptr ),
resourceName( fileName ), release(true){}

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

void Resource::setRelease(bool release) {
	this->release = release;
}

//-----------------------------------------------------------

bool Resource::isRelease() const {
	return release;
}

//----------------------------------------------------------
