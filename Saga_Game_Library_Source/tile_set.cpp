#include "tile_set.h"
#include <string>

namespace sgl {
namespace image {

//-----------------------------------------------------------

TileSet::TileSet( const char* dir ) {

	source = dir;
	
	firstGid = 0;
	lastGid  = 0;

	rows   = 0;
	colums = 0;

	width  = 0;
	height = 0;

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

	// Destruimos a imagem
	Resource::destroyResource( image );

}

//-----------------------------------------------------------

void TileSet::parse( TiXmlNode* node ) {

	// Convertemos o node para element
	TiXmlElement* elem = node->ToElement();

	// Inciando os atributos do tileset
	elem->Attribute( "firstgid", &firstGid );
	name = elem->Attribute( "name" );

	elem->Attribute( "tilewidth",  &tileWidth  );
	elem->Attribute( "tileheight", &tileHeight );

	elem->Attribute( "spacing", &spacing );
	elem->Attribute( "margin",  &margin  );

	//----------------------------------------

	// Carregamos o offset do mapa
	elem = node->FirstChildElement( "tileoffset" );

	if( elem ) {
		elem->Attribute( "x", &offset.x );
		elem->Attribute( "y", &offset.y );
	}

	//----------------------------------------

	// Carregamos os property do tileset
	properties.parse( node->FirstChild( "properties" ) );

	//----------------------------------------

	// Pegamos os atributos da imagem
	elem = node->FirstChildElement( "image" );

	// Pegamos os atributos da imagem
	elem->Attribute( "width",  &width  );
	elem->Attribute( "height", &height );
	
	// Capturamos o path da imagem
	std::string str = elem->Attribute( "source" );
	
	unsigned found;
	
	//-------------------------------
	// Verificamos se o path da imagem possui ../ no inicio
	found = str.find( "." );
	
	// Se sim, retiramos os ../
	if( found == 0 )
		str = str.substr( found + 3 );
		
	//------------------------------
	
	// Pegamos o path do arquivo .tmx
	found = source.find_last_of( "/" );
	
	// Se sim, criamos uma string apenas com o path, sem o nome do arquivo.
	if( found != 0 )
		source = source.substr( 0, found + 1 );
	else
		source.clear();
	
	// Concatenamos o path do arquivo .tmx com o path da imagem
	source += str;

	// Carregamos a imagem
	image = ImageResource::createImageResource( source.c_str() );

	//---------------------------------------

	// Calculamos o numero de colunas e linhas do tileset
	rows   = height / tileHeight;
	colums = width / tileWidth;

	// Calculamos o lastGid
	lastGid = rows * colums + firstGid - 1;

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

int TileSet::getLastGid() const {
	return lastGid;
}

//-----------------------------------------------------------

ImageResource* TileSet::getImage() {
	return image;
}

//-----------------------------------------------------------

int TileSet::getWidth() const {
	return width;
}

//-----------------------------------------------------------

int TileSet::getHeight() const {
	return height;
}

//-----------------------------------------------------------

int TileSet::getRows() const {
	return rows;
}

//-----------------------------------------------------------

int TileSet::getColums() const {
	return colums;
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

std::string* TileSet::getSource() {
	return &source;
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
