#include "tile_set.h"

namespace sgl {
namespace image {

//-----------------------------------------------------------

TileSet::TileSet() {

	firstGid = -1;

	tileWidth  = 0;
	tileHeight = 0;

	spacing = 0;
	margin  = 0;
	
	offset.x = 0;
	offset.y = 0;
	
	image = nullptr;

}

//-----------------------------------------------------------

TileSet::~TileSet() {

	// Criamos um iterator para o mapa
	std::map<int, Tile*>::iterator it;

	// Percorremos o mapa desalocando os tiles*
	for( it = tiles.begin(); it != tiles.end(); ++it ) {
		delete it->second;
	}

	// Limpamos o mapa
	tiles.clear();

}

//-----------------------------------------------------------

void TileSet::parse( TiXmlNode* node ) {
	
	// Convertemos o node para element
	TiXmlElement* elem = node->ToElement();

	// Inciando os atributos do tileset
	elem->Attribute( "firstgid",   &firstGid );
	name = elem->Attribute( "name" );
	
	elem->Attribute( "tilewidth",  &tileWidth  );
	elem->Attribute( "tileheight", &tileHeight );
	
	elem->Attribute( "spacing", &spacing );
	elem->Attribute( "margin",  &margin  );
	
	//----------------------------------------
	
	// Carregamos o offset do mapa
	elem = node->FirstChildElement( "tileoffset" );
	
	elem->Attribute( "x", &offset.x );
	elem->Attribute( "y", &offset.y );
	
	//----------------------------------------
	
	// Carregamos os property do tileset
	properties.parse( node->FirstChild( "properties" ) );
	
	//----------------------------------------

	// Pegamos os atributos da imagem
	elem = node->FirstChildElement( "image" );

	// Carregamos a imagem
	image = ImageResource::createImageResource( elem->Attribute( "source" ) );
	
	//----------------------------------------

	// elem agora ira iterarar atraves dos tiles
	node = node->FirstChild( "tile" );

	// Percorremos a tag tileset salvando cada um das propriedades
	while( node ) {

		// Criamos o tile
		Tile* t = new Tile();
		
		// Fazemos o parser
		t->parse( node );

		// Adicionamos o tile na lista de tiles
		tiles[ t->getId() ] = t;

		// Passamos para a proxima property
		node = node->NextSibling( "tile" );

	}//while
	
	//---------------------------------------

}

//-----------------------------------------------------------

Tile* TileSet::getTile( int id ) {

	// Criamos um iterator para o mapa
	std::map<int, Tile*>::iterator it;

	// Inicializamos o iterator
	it = tiles.find( id );

	// Verificamos se o resource esta presente no mapa
	return it != tiles.end() ? it->second : NULL;

}

//-----------------------------------------------------------

int TileSet::getTileAmount() {
	return tiles.size();
}

//-----------------------------------------------------------

bool TileSet::hasTile(int id) {

	// Criamos um iterator para o mapa
	std::map<int, Tile*>::iterator it;

	// Inicializamos o iterator
	it = tiles.find( id );

	// Verificamos se o tile esta presente no mapa
	return it != tiles.end() ? true : false;
}

//-----------------------------------------------------------

int TileSet::getFirstGid() const {
	return firstGid;
}

//-----------------------------------------------------------

ImageResource* TileSet::getImage() {
	return image;
}

//-----------------------------------------------------------

int TileSet::getMargin() const {
	return margin;
}

//-----------------------------------------------------------

const char* TileSet::getName() {
	return name;
}

//-----------------------------------------------------------

const char* TileSet::getSource() {
	return source;
}

//-----------------------------------------------------------

int TileSet::getSpacing() const {
	return spacing;
}

//-----------------------------------------------------------

int TileSet::getTileHeight() const {
	return tileHeight;
}

//-----------------------------------------------------------

int TileSet::getTileWidth() const {
	return tileWidth;
}

//-----------------------------------------------------------

const std::map<int, Tile*>& TileSet::getTiles() const {
	return tiles;
}

//-----------------------------------------------------------

}
} /* namespace */
