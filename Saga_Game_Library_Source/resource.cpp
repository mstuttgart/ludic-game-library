#include "resource.h"

using namespace sgl;

//----------------------------------------------------------

Resource::Resource( const String& fileName, void* ptr ) : resourcePtr( ptr ), 
resourceName( fileName ), release(true){}

//---------------------------------------------------------

Resource::~Resource() {
	std::cout << "File " << resourceName << " deleted!" << std::endl;
	resourcePtr = nullptr;
}

//-----------------------------------------------------------

void* Resource::getResorcePtr() const {
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