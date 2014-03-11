#include "resource.h"

using namespace sgl;

//----------------------------------------------------------

Resource::Resource( const char* fileName, void* ptr ) : referenceAmount(0),
	resourcePtr( ptr ), resourceName( fileName ), release(true){}

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

std::string Resource::getResourceName() {
	return resourceName.c_str();
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