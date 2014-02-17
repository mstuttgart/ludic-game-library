#include "layer.h"

namespace sgl {

namespace image {

//-----------------------------------------------------------

Layer::Layer() : opacity(1.0), visible( true ) {}

//-----------------------------------------------------------

void Layer::parse( TiXmlNode* node ) {

	// Convertemos o node para element
	TiXmlElement* elem = node->ToElement();

	// Pegamos o nome do layer
	name = elem->Attribute( "name" );

	// Pegamos a opacidade
	elem->Attribute( "opacity", &opacity );

	// Verificamos se o layer e visivel
	if( !elem->Attribute( "visible" ) ) visible = false;

	// Inicializamos o propertySet
	properties.parse( node->FirstChild( "properties" ) );

	// Pegamos o primeiro indice para preenchermos o vetor
	elem = node->FirstChild( "data" )->FirstChildElement( "tile" );

	int aux;

	while( elem ) {

		// Pegamos o numero do tile
		elem->Attribute( "gid", &aux );

		// Inserimos no vetor
		data.push_back( aux );

		// Passamos para o proximo indice
		elem = elem->NextSiblingElement( "tile" );

	}//while

}

//-----------------------------------------------------------

void Layer::setOpacity(double opacity) {
	this->opacity = opacity;
}

//-----------------------------------------------------------

void Layer::setVisible(bool visible) {
	this->visible = visible;
}

//-----------------------------------------------------------

const char* Layer::getName() {
	return name;
}

//-----------------------------------------------------------

double Layer::getOpacity() const {
	return opacity;
}

//-----------------------------------------------------------

bool Layer::isVisible() const {
	return visible;
}

//-----------------------------------------------------------

int Layer::size() const {
	return data.size();
}

//-----------------------------------------------------------

}
} /* namespace */
