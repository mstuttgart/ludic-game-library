#include "resource_manager.hpp"

using namespace Ludic;
using namespace std;

ResourceManager* ResourceManager::ms_instance = nullptr;

//////////////////////////////////////////////////////////////

ResourceManager::ResourceManager() {}

//////////////////////////////////////////////////////////////

ResourceManager::~ResourceManager() {

	// Variavel auxiliar
	//Resource* r = nullptr;

	// Percorremo o mapa deletando os resources deletaveis
	for( auto& it : resourceMap ) {

		// Verificamos se o Resource e deletavel
		if( it.second ) {
			cout << "File " << it.first << " deleted!" << endl;
			delete it.second;
		}

	}//for

	// Limpamos o mapa
	resourceMap.clear();
	
	cout << endl;
	cout << "* ResourceMap was terminated!" << endl;
}

//////////////////////////////////////////////////////////////

ResourceManager* ResourceManager::Instance() {

	// Se instance é null, nos a inicializamos
	if( !ms_instance )
		ms_instance = new ResourceManager();

	return ms_instance;

}

//////////////////////////////////////////////////////////////

void ResourceManager::addResource( const String& fileName, Resource* resource ) {

	// Inserimos o resource no mapa de resource
	resourceMap.insert( pair<string, Resource*>( fileName, resource ) );

}

//////////////////////////////////////////////////////////////

Resource* ResourceManager::getResource( const String& resourceName ) {

	// Verificamos se o resource esta presente no mapa
	return hasResource( resourceName ) ? resourceMap.at( resourceName ) : nullptr;

}

//////////////////////////////////////////////////////////////

bool ResourceManager::hasResource( const String& resourceName ) {

	// Criamos um iterator para o mapa
	map<string, Resource*>::iterator it = resourceMap.find( resourceName );

	// Verificamos se o resource esta presente no mapa
	return it != resourceMap.end() ? true : false;

}

//////////////////////////////////////////////////////////////

int ResourceManager::size() const {
	return resourceMap.size();
}

//////////////////////////////////////////////////////////////

void ResourceManager::release() {

	// Criamos mapa auxiliar que recebe recursos nao deletaveis
	map<String, Resource*> resourceMapAux;

	// Percorremo o mapa deletando os resources deletaveis
	for( auto& it : resourceMap ) {

		// Pegamos o resource apontado pelo iterator
		Resource* r = it.second;

		// Verificamos se o Resource e deletavel
		if( r && !r->isReleased() ) {

			//Passamos os Resources que nao podem
			// ser apagados para o outro mapa
			resourceMapAux[ it.first ] = it.second;

		}//if
		else if( r ) {
			// Deletamos o Resource
			delete resourceMap[ it.first ];
		}

		// Definimos a posicao que perdeu o resource como null
		resourceMap[ it.first ] = nullptr;

	}//for

	// Limpamos o mapa
	resourceMap.clear();

	// Percorremo o mapa auxiliar copiando os resources nao deletaveis
	// para o mapa principal
	for( auto& it : resourceMapAux ) {

		//Passamos os Resources que nao podem
		// ser apagados para o outro mapa
		resourceMap[ it.first ] = it.second;

	}//for

}

//////////////////////////////////////////////////////////////

void ResourceManager::destroy() {

	// Deletamos instance
	if( ms_instance )
		delete ms_instance;
}

//////////////////////////////////////////////////////////////
