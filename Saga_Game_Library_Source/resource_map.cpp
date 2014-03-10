#include "resource_map.h"

using namespace sgl;
using namespace std;

ResourceMap* ResourceMap::ms_instance = nullptr;

map<std::string, Resource*>* ResourceMap::map_rsc = nullptr;
map<std::string, Resource*>::iterator ResourceMap::it;

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
		map_rsc = new map<std::string, Resource*>();
	}

	return ms_instance;
}

//-----------------------------------------------------------

void ResourceMap::addResource( std::string fileName, Resource* resource) {

	// Inserimos o resource no mapa de resource
	map_rsc->insert( pair<std::string, Resource*>( fileName, resource ));

}

//-----------------------------------------------------------

Resource* ResourceMap::getResource( std::string resourceName ) {

	// Verificamos se o resource esta presente no mapa
	return hasResource( resourceName ) ? it->second : NULL;

}

//-----------------------------------------------------------

bool ResourceMap::removeResource( std::string resourceName ) {

	if( hasResource( resourceName ) ) {
		map_rsc->erase( it );
		return true;
	}//if

	return false;
}

//-----------------------------------------------------------

bool ResourceMap::hasResource( std::string resourceName ) {

	// Criamos um iterator para o mapa
	it = map_rsc->find( resourceName );

	// Verificamos se o resource esta presente no mapa
	return it != map_rsc->end() ? true : false;

}

//-----------------------------------------------------------

int ResourceMap::size() const {
	return map_rsc->size();
}

//------------------------------------------------------------

