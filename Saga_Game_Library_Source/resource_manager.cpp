#include "resource_manager.h"

using namespace sgl;
using namespace std;

ResourceManager* ResourceManager::ms_instance = nullptr;

//map<std::string, Resource*>* ResourceManager::map_rsc = nullptr;

//-----------------------------------------------------------

ResourceManager::ResourceManager() {
	//map_rsc = new map<string, Resource*>();
}

//-----------------------------------------------------------

ResourceManager::~ResourceManager() {

	// Variavel auxiliar
	Resource* r = nullptr;

	// Criamos um iterator para o mapa
	map<string, Resource*>::iterator it;

	// Percorremo o mapa deletando os resources deletaveis
	for( it = map_rsc.begin(); it != map_rsc.end(); ++it ) {

		// Pegamos o Resource
		if( it->second )
			r = it->second;

		// Deletamos o Resource
		delete r;

	}//for

	// Limpamos o mapa
	map_rsc.clear();

	// Deletamos o mapa
	//delete map_rsc;

	// Incializamos instance
	ms_instance = nullptr;

	std::cout << std::endl;
	std::cout << "ResourceMap was terminated!" << std::endl;
}

//-----------------------------------------------------------

ResourceManager* ResourceManager::getInstance() {

	// Se instance é null, nos a inicializamos
	if ( !ms_instance ) {
		ms_instance = new ResourceManager();
		//map_rsc     = new map<string, Resource*>();
	}

	return ms_instance;
}

//-----------------------------------------------------------

void ResourceManager::addResource( string fileName, Resource* resource ) {

	// Inserimos o resource no mapa de resource
	map_rsc.insert( pair<string, Resource*>( fileName, resource ) );

}

//-----------------------------------------------------------

Resource* ResourceManager::getResource( string resourceName ) {

	// Verificamos se o resource esta presente no mapa
	return hasResource( resourceName ) ? map_rsc.at( resourceName ) : nullptr;

}

//-----------------------------------------------------------

bool ResourceManager::hasResource( string resourceName ) {

	// Criamos um iterator para o mapa
	map<string, Resource*>::iterator it = map_rsc.find( resourceName );

	// Verificamos se o resource esta presente no mapa
	return it != map_rsc.end() ? true : false;

}

//-----------------------------------------------------------

int ResourceManager::size() const {
	return map_rsc.size();
}

//------------------------------------------------------------

void ResourceManager::release() {

	Resource* r = nullptr;

	// Criamos um iterator para o mapa
	map<string, Resource*>::iterator it;

	// Percorremo o mapa deletando os resources deletaveis
	for( it = map_rsc.begin(); it != map_rsc.end(); ++it ) {

		r = it->second;

		// Verificamos se o Resource e deletavel
		if( r->isRelease() ) {

			// Removemos o resource do map
			map_rsc.erase( it );

			// Deletamos o Resource
			delete r;

		}//if
	}//for

}

//------------------------------------------------------------

void ResourceManager::destroy() {

	// Deletamos instance
	if( ms_instance )
		delete ms_instance;

}
