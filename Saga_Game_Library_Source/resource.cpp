#include "resource.h"
#include "resource_map.h"

using namespace sgl;

Resource::Resource( const char* fileName, void* ptr ) : referenceAmount(0),
	resourcePtr( ptr ), resourceName( fileName ) {}

Resource::~Resource() {
	resourcePtr = nullptr;
	std::cout << "Destrutor Resource" << std::endl;
}

//-----------------------------------------------------------

bool Resource::destroyResource( Resource* rsc ) {

	// Verificamos se resource nao e NULL
	if( !rsc ) return false;

	// Decrementamos o número de referências do resource em uma unidade
	rsc->decReferenceAmount();

	//Verificamos se o número de referencias e zero
	if( rsc->getReferenceAmount() <= 0 ) {

		// Pegamos uma instancia do ResourceMap
		ResourceMap* map = ResourceMap::getInstance();

		// Removemos o resource do mapa
		// Se for um subImageResource, o
		// pai nao sera removido do ResourceMap
		map->removeResource( rsc->getResourceName() );

		// Deletamos o resource
		delete rsc;
		
		// Retornamos true indicando que desalocamos o Resource
		return true;

	}//if

	return false;

}//destroyResource

//-----------------------------------------------------------

int Resource::getReferenceAmount() const {
	return referenceAmount;
}

//-----------------------------------------------------------

void Resource::incReferenceAmount() {
	referenceAmount++;
}

//-----------------------------------------------------------

void Resource::decReferenceAmount() {
	referenceAmount--;
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
