#include "resource_map.h"

using namespace sgl;
using namespace std;

ResourceMap* ResourceMap::ms_instance = nullptr;

map<std::string, Resource*>* ResourceMap::map_rsc = nullptr;
map<std::string, Resource*>::iterator ResourceMap::it;

//-----------------------------------------------------------

ResourceMap::~ResourceMap() {

	// Variavel auxiliar
	Resource* r = nullptr;

	// Percorremo o mapa deletando os resources deletaveis
	for( it = map_rsc->begin(); it != map_rsc->end(); ++it ) {

		// Pegamos o Resource
		r = it->second;

		// Removemos o resource do map
		//map_rsc->erase( it );

		// Deletamos o Resource
		delete r;

	}//for

	// Limpamos o mapa
	map_rsc->clear();

	// Deletamos o mapa
	delete map_rsc;

	// Incializamos instance
	ms_instance = nullptr;
}

//-----------------------------------------------------------

ResourceMap* ResourceMap::getInstance() {

	// Se instance é null, nos a inicializamos
	if ( !ms_instance ) {
		ms_instance = new ResourceMap();
		map_rsc     = new map<string, Resource*>();
	}

	return ms_instance;
}

//-----------------------------------------------------------

void ResourceMap::addResource( string fileName, Resource* resource) {

	// Inserimos o resource no mapa de resource
	map_rsc->insert( pair<string, Resource*>( fileName, resource ));

}

//-----------------------------------------------------------

Resource* ResourceMap::getResource( string resourceName ) {
	
	// Criamos um iterator para o mapa
	it = map_rsc->find( resourceName );

	// Verificamos se o resource esta presente no mapa
	return it != map_rsc->end() ? it->second : NULL;

}

//-----------------------------------------------------------

bool ResourceMap::hasResource( string resourceName ) {

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

void ResourceMap::release() {

	Resource* r = nullptr;

	// Percorremo o mapa deletando os resources deletaveis
	for( it = map_rsc->begin(); it != map_rsc->end(); ++it ) {

		r = it->second;

		// Verificamos se o Resource e deletavel
		if( r->isRelease() ) {

			// Removemos o resource do map
			map_rsc->erase( it );

			// Deletamos o Resource
			delete r;

		}//if
	}//for

}

//------------------------------------------------------------

void ResourceMap::destroy() {

	// Deletamos instance
	if( ms_instance )
		delete ms_instance;

}
