#include "Resource.h"
#include "ResourceMap.h"
namespace sgl {

Resource::Resource( const char* fileName, void* ptr ) {

	// Inicializamos os atributos da classe
	referenceAmount = 0;
	resourcePtr     = ptr;
	resourceName    = new std::string( fileName );

}

//-----------------------------------------------------------

Resource::~Resource() {
	if( resourceName ) delete resourceName ;
}

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
	return resourceName->c_str();
}

//-----------------------------------------------------------

Resource* Resource::createResource( const char* fileName, void* ptr ) {

	// Inciamos a string com a msg de carregamento
	std::string str( "File " );
	str += fileName;

	// Pegamos uma instancia do mapa
	ResourceMap* rscMap = ResourceMap::getInstance();

	// Verificamos se o recurso ja foi carregado
	Resource* rsc = rscMap->getResource( fileName );

	if( !rsc ) {

		// Criamos um novo recurso
		rsc = new Resource( fileName, ptr );

		// Adicionamos o resource ao mapa
		rscMap->addResource( fileName, rsc );

		// Montamos a mensagem do log em caso do carregamento ter sucesso.
		str += " loaded successfully!";
	}
	else {
		// Montamos a mensagem do log em caso do carregamento ter sucesso.
		str += " already exists!";
	}

	// Aumentamos o numero de referencias em uma unidade
	rsc->incReferenceAmount();

	std::cout << str << std::endl;
	LogOutput::printInLogout( str.c_str() ); // Saida para log

	return rsc;
}

//-----------------------------------------------------------

void Resource::destroyResource( Resource* rsc ) {

	// Verificamos se resource nao e NULL
	if( !rsc ) return;

	// Decrementamos o número de referências do resource em uma unidade
	rsc->decReferenceAmount();

	//Verificamos se o número de referencias e zero
	if( rsc->getReferenceAmount() == 0 ) {

		// Pegamos uma instancia do ResourceMap
		ResourceMap* map = ResourceMap::getInstance();

		// Removemos o resource do mapa
		map->removeResource( rsc->getResourceName() );

		// Deletamos o resource
		delete rsc;

	}//if

}

//-----------------------------------------------------------

} /* namespace */
