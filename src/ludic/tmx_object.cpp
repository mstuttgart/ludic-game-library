#include "tmx_object.hpp"

using namespace Ludic;

//////////////////////////////////////////////////////////////

TMXObject::TMXObject() : gid( 0 ) {}

//////////////////////////////////////////////////////////////

void TMXObject::parse( TiXmlNode* node ) {

	// Transformamos o no em elemento
	TiXmlElement* elem = node->ToElement();

	// Recebemos o atributo nome
	const char* aux = elem->Attribute( "name" );

	// Se existir, setamos name
	if( aux )
		name = aux;

	// Lemos o valor de gid
	aux = elem->Attribute( "gid" );

	// Se existir, setamos gid
	if( aux )
		gid = static_cast<int>( *aux );

	// Lemos as coordenadas
	int x = (int) atoi(elem->Attribute( "x" ));
	int y = (int) atoi(elem->Attribute( "y" ));

	// Setamos as coordenadas
	position.setCoordinates( x, y );

}

//////////////////////////////////////////////////////////////