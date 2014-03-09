#include "resource.h"
#include "resource_map.h"

using namespace sgl;

Resource::Resource( const char* fileName, void* ptr ) : referenceAmount(0),
	resourcePtr( ptr ), resourceName( fileName ) {

	// Inicializamos os atributos da classe
	/*referenceAmount = 0;
	resourcePtr     = ptr;
	resourceName    = new std::string( fileName );*/

}

//-----------------------------------------------------------

/*Resource::~Resource() {

	//delete resourceName ;
			


}*/

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

const char* Resource::getResourceName() {
	return resourceName.c_str();
}

//-----------------------------------------------------------

void Resource::destroyResource( Resource* rsc ) {

	// Verificamos se resource nao e NULL
	if( !rsc ) return;

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

	}//if

}//destroyResource

//-----------------------------------------------------------
