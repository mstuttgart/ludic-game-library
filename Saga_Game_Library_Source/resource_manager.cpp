#include "resource_manager.h"

using namespace sgl;
using namespace std;

ResourceManager* ResourceManager::ms_instance = nullptr;

//-----------------------------------------------------------

ResourceManager::ResourceManager() {}

//-----------------------------------------------------------

ResourceManager::~ResourceManager() {

	// Variavel auxiliar
	Resource* r = nullptr;

	// Criamos um iterator para o mapa
	map<string, Resource*>::iterator it;

	// Percorremo o mapa deletando os resources deletaveis
	for( it = mapResource.begin(); it != mapResource.end(); ++it ) {

		// Pegamos o Resource
		if( it->second )
			r = it->second;

		// Deletamos o Resource
		delete r;

	}//for

	// Limpamos o mapa
	mapResource.clear();

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
	if ( !ms_instance )
		ms_instance = new ResourceManager();

	return ms_instance;
}

//-----------------------------------------------------------

void ResourceManager::addResource( String fileName, Resource* resource ) {

	// Inserimos o resource no mapa de resource
	mapResource.insert( pair<string, Resource*>( fileName, resource ) );

}

//-----------------------------------------------------------

Resource* ResourceManager::getResource( String resourceName ) {

	// Verificamos se o resource esta presente no mapa
	return hasResource( resourceName ) ? mapResource.at( resourceName ) : nullptr;

}

//-----------------------------------------------------------

bool ResourceManager::hasResource( String resourceName ) {

	// Criamos um iterator para o mapa
	map<string, Resource*>::iterator it = mapResource.find( resourceName );

	// Verificamos se o resource esta presente no mapa
	return it != mapResource.end() ? true : false;

}

//-----------------------------------------------------------

int ResourceManager::size() const {
	return mapResource.size();
}

//------------------------------------------------------------

void ResourceManager::release() {

	Resource* r = nullptr;

	// Criamos um iterator para o mapa
	map<string, Resource*>::iterator it;
	std::map<std::string, Resource*> mapResourceAux;

	// Percorremo o mapa deletando os resources deletaveis
	for( it = mapResource.begin(); it != mapResource.end(); ++it ) {

		// Pegamos o resource apontado pelo iterator
		r = it->second;

		// Verificamos se o Resource e deletavel
		if( r && !r->isRelease() ) {

			//Passamos os Resources que nao podem
			// ser apagados para o outro mapa
			mapResourceAux[ it->first ] = it->second;

		}//if
		else if( r ) {
			// Deletamos o Resource
			delete mapResource[ it->first ];
		}
		
		// Definimos a posicao que perdeu o resource como null
		mapResource[ it->first ] = nullptr;

	}//for
	
	// Limpamos o mapa
	mapResource.clear();
	
	// Percorremo o mapa auxiliar copiando os resources nao deletaveis
	// para o mapa principal
	for( it = mapResourceAux.begin(); it != mapResourceAux.end(); ++it ) {
		
		//Passamos os Resources que nao podem
		// ser apagados para o outro mapa
		mapResource[ it->first ] = it->second;

	}//for
	
}

//------------------------------------------------------------

void ResourceManager::destroy() {

	// Deletamos instance
	if( ms_instance )
		delete ms_instance;

}
