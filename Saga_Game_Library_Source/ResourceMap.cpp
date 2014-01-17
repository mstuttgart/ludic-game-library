#include "ResourceMap.h"

namespace sgl {

ResourceMap* ResourceMap::ms_instance = nullptr;

//-----------------------------------------------------------

ResourceMap::~ResourceMap() {

	if ( ms_instance != nullptr ) {
		delete ms_instance;
	}

	ms_instance = nullptr;

}

//-----------------------------------------------------------

ResourceMap* ResourceMap::getInstance() {

	if ( ms_instance == nullptr ) {
		ms_instance = new ResourceMap();
	}

	return ms_instance;
}

//-----------------------------------------------------------

void ResourceMap::addResource( Resource* resource ) {

	// Verificamos se o resource ja nao esta presente no mapa
	if( find( resource->getResourceName() ) != end() ) {

		std::cout << "Resource " << resource->getResourceName()
		          << " already exists." << std::endl;
		return;
	}

	// Inserimos o resource no mapa de resources
	insert( std::pair<const char*, Resource*>( resource->getResourceName(), resource ) );

}

//-----------------------------------------------------------

bool ResourceMap::getResource( const char* resourceName, Resource* resource ) {

	// Verificamos se o resource esta presente no mapa
	if( find( resourceName ) != end() ) {
		resource = at( resourceName );
		return true;
	}

	return false;
}

//-----------------------------------------------------------

bool ResourceMap::removeResource( const char* resourceName ) {

	if( find( resourceName ) != end() ) {

		erase( resourceName );
		return true;
	}//if

	return false;
}

//-----------------------------------------------------------

bool ResourceMap::isResourcePresent( const char* resourceName ) {

	if( find( resourceName ) != end() ) {
		return true;
	}

	return false;

}

//-----------------------------------------------------------
int ResourceMap::resourcesAmount() const {
	return size();
}

//-----------------------------------------------------------

} /* namespace */
