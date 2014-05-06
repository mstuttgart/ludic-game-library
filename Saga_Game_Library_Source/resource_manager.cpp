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

	// Percorremo o mapa deletando os resources deletaveis
	for( auto& it : mapResource ) {

		// Pegamos o resource apontado pelo iterator
		r = it.second;

		// Verificamos se o Resource e deletavel
		if( r ) {
			cout << "File " << it.first << " deleted!" << endl;
			delete r;
		}

	}//for

	// Limpamos o mapa
	mapResource.clear();
	
	cout << endl;
	cout << "* ResourceMap was terminated!" << endl;
}

//-----------------------------------------------------------

ResourceManager* ResourceManager::Instance() {

	// Se instance é null, nos a inicializamos
	if( !ms_instance )
		ms_instance = new ResourceManager();

	return ms_instance;

}

//-----------------------------------------------------------

void ResourceManager::addResource( const String& fileName, Resource* resource ) {

	// Inserimos o resource no mapa de resource
	mapResource.insert( pair<string, Resource*>( fileName, resource ) );

}

//-----------------------------------------------------------

Resource* ResourceManager::getResource( const String& resourceName ) {

	// Verificamos se o resource esta presente no mapa
	return hasResource( resourceName ) ? mapResource.at( resourceName ) : nullptr;

}

//-----------------------------------------------------------

bool ResourceManager::hasResource( const String& resourceName ) {

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

	// Criamos mapa auxiliar que recebe recursos nao deletaveis
	map<String, Resource*> mapResourceAux;

	// Percorremo o mapa deletando os resources deletaveis
	for( auto& it : mapResource ) {

		// Pegamos o resource apontado pelo iterator
		r = it.second;

		// Verificamos se o Resource e deletavel
		if( r && !r->isRelease() ) {

			//Passamos os Resources que nao podem
			// ser apagados para o outro mapa
			mapResourceAux[ it.first ] = it.second;

		}//if
		else if( r ) {
			// Deletamos o Resource
			delete mapResource[ it.first ];
		}

		// Definimos a posicao que perdeu o resource como null
		mapResource[ it.first ] = nullptr;

	}//for

	// Limpamos o mapa
	mapResource.clear();

	// Percorremo o mapa auxiliar copiando os resources nao deletaveis
	// para o mapa principal
	for( auto& it : mapResourceAux ) {

		//Passamos os Resources que nao podem
		// ser apagados para o outro mapa
		mapResource[ it.first ] = it.second;

	}//for

}

//------------------------------------------------------------

void ResourceManager::destroy() {

	// Deletamos instance
	if( ms_instance )
		delete ms_instance;
}

//------------------------------------------------------------
