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

void ResourceMap::addResource( const char* fileName, Resource* resource ) {

	// Inserimos o resource no mapa de resource
	insert( ResourceMap::value_type( fileName, resource ) );

}

//-----------------------------------------------------------

Resource* ResourceMap::getResource( const char* resourceName ) {
	
	// Criamos um iterator para o mapa
	ResourceMap::iterator it = find( resourceName );
	
	// Verificamos se o resource esta presente no mapa
	return it != end() ? it->second : NULL;

}

//-----------------------------------------------------------

bool ResourceMap::removeResource( const char* resourceName ) {

	// Criamos um iterator para o mapa
	ResourceMap::iterator it = find( resourceName );
	
	if( it != end() ) {
		erase( it );
		return true;		
	}//if

	return false;
}

//-----------------------------------------------------------

bool ResourceMap::isResourcePresent( const char* resourceName ) {
	
	// Criamos um iterator para o mapa
	ResourceMap::iterator it = find( resourceName );
	
	// Verificamos se o resource esta presente no mapa
	return it != end() ? true : false;
	
}

//-----------------------------------------------------------
int ResourceMap::resourcesAmount() const {
	return size();
}

//-----------------------------------------------------------
void ResourceMap::release() {
	
}

//---------------------------------------------------------

} /* namespace */
