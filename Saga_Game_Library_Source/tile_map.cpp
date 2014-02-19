#include "tile_map.h"

namespace sgl {
namespace image {

//---------------------------------------------

TileMap::TileMap() : width(0), height(0), tileWidth(0), tileHeight(0) {
}

//---------------------------------------------

TileMap::~TileMap() {

	for( unsigned int i=0; i<tilesets.size(); i++ ) {
		delete tilesets[i];
	}

	for( unsigned int i=0; i<layers.size(); i++ ) {
		delete layers[i];
	}

	tilesets.clear();
	layers.clear();

}

//---------------------------------------------

void TileMap::loadMap( const char* tmxFileName ) {

	//Carregamos o mapa
	TiXmlDocument doc;

	//-----------------------------------------

	// Carregamos o documento
	if( !doc.LoadFile( tmxFileName ) ) {
		std::cout << doc.ErrorDesc() << std::endl;
		return;
	}//if

	//-----------------------------------------

	// Carregamos o elemento root
	TiXmlNode* root = doc.FirstChild( "map" );

	if( !root ) {
		std::cout << "Failed to load file: No root element." << std::endl;
		doc.Clear();
		return;
	}//if

	//tileSetsDir = tilesetsPath;
	tileSetsDir = tmxFileName;

	// Realizamos o parse do mapa
	parse( root );
	
	// Fechamos o doc
	doc.Clear();

}

//---------------------------------------------

void TileMap::parse( TiXmlNode* root ) {

	//-----------------------------------------

	// Pegamos os atributos do mapa
	root->ToElement()->Attribute( "width", &width   );
	root->ToElement()->Attribute( "height", &height );
	root->ToElement()->Attribute( "tilewidth", &tileWidth   );
	root->ToElement()->Attribute( "tileheight", &tileHeight );

	//------------------------------------------

	// Comecamos a ler o mapa pela suas properties
	properties.parse( root->FirstChild( "properties" ) );

	//-----------------------------------------

	// Primeiro no com tileset
	TiXmlNode* nodeAux = root->FirstChild( "tileset" );

	while( nodeAux ) {

		// Criamos o tileset
		TileSet* t = new TileSet( tileSetsDir );

		// Realizamos o parser
		t->parse( nodeAux );

		// Armazenamos o tileset
		tilesets.push_back( t );

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
		l->parse( nodeAux, tilesets, width, tileWidth, tileHeight );

		// Armazenamos o tileset
		layers.push_back( l );

		// Proximo no com tileset
		nodeAux = nodeAux->NextSibling( "layer" );

	}//while*/
	
	//-------------------------------------------
	
	// Carregamos os objects
	/*nodeAux = root->FirstChild( "objectgroup" );

	while( nodeAux ) {

		// Criamos o layer
		ObjectGroup* obj = new ObjectGroup();

		// Realizamos o parser
		obj->parse( nodeAux, &tilesets, width, tileWidth, tileHeight );

		// Armazenamos o tileset
		layers.push_back( l );

		// Proximo no com tileset
		nodeAux = nodeAux->NextSibling( "layer" );

	}//while*/
	

}

//---------------------------------------------

Layer* TileMap::getLayer( int idx ) {
	return layers.at(idx);
}

//---------------------------------------------

}
} /* namespace */
