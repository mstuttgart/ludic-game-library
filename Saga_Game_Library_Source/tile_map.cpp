#include "tile_map.h"

namespace sgl {
namespace image {

//---------------------------------------------

TileMap::TileMap() {
}

//---------------------------------------------

TileMap::~TileMap() {

}

//---------------------------------------------

void TileMap::loadMap( const char* tmxFile ) {

	//Carregamos o mapa
	TiXmlDocument doc;

	//-----------------------------------------

	// Carregamos o documento
	if( !doc.LoadFile( tmxFile ) ) {
		std::cerr << doc.ErrorDesc() << std::endl;
		return;
	}//if

	//-----------------------------------------

	// Carregamos o elemento root
	TiXmlNode* root = doc.FirstChild( "map" );

	if( !root ) {
		std::cerr << "Failed to load file: No root element." << std::endl;
		doc.Clear();
		return;
	}//if
	
	// Realizamos o parse do mapa
	parse( root );
	
}

//---------------------------------------------

void TileMap::parse( TiXmlNode* root ) {

	//-----------------------------------------

	// Pegamos os atributos do mapa
	root->ToElement()->Attribute( "width", &width   );
	root->ToElement()->Attribute( "height", &height );
	root->ToElement()->Attribute( "tilewidth", &tileWidth   );
	root->ToElement()->Attribute( "tileheight", &tileheight );

	//------------------------------------------

	// Comecamos a ler o mapa pela suas properties
	properties.parse( root->FirstChild( "properties" ) );

	//-----------------------------------------

	// Primeiro no com tileset
	TiXmlNode* nodeAux = root->FirstChild( "tileset" );

	while( nodeAux ) {
		
		// Criamos o tileset
		TileSet* t = new TileSet();

		// Realizamos o parser
		t->parse( nodeAux );

		// Armazenamos o tileset
		tilesetMap[ t->getFirstGid() ] = t;

		// Proximo no com tileset
		nodeAux = nodeAux->NextSibling( "tileset" );
		
	}//while
	
	//-------------------------------------------
	
	// Carregamos os layers
	nodeAux = root->FirstChild( "layer" );

	while( nodeAux ) {
		
		// Criamos o layer
		Layer* l = new Layer();

		// Realizamos o parser
		l->parse( nodeAux );

		// Armazenamos o tileset
		layerMap[ l->getName() ] = l;

		// Proximo no com tileset
		nodeAux = nodeAux->NextSibling( "layer" );
		
	}//while

}

//---------------------------------------------

}
} /* namespace */
