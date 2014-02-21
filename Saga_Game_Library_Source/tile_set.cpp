#include "tile_set.h"
#include <string>

using namespace sgl::image;

//-----------------------------------------------------------

TileSet::TileSet( const char* dir ) {

	firstGid = 0;
	lastGid  = 0;

	rows   = 0;
	colums = 0;

	width  = 0;
	height = 0;

	tileWidth  = 0;
	tileHeight = 0;

	image  = nullptr;
	source = dir;

}

//-----------------------------------------------------------

TileSet::~TileSet() {
	Resource::destroyResource( image ); // Destruimos a imagem
}

//-----------------------------------------------------------

void TileSet::parse( TiXmlNode* node ) {

	// Convertemos o node para element
	TiXmlElement* elem = node->ToElement();

	// Inciando os atributos do tileset
	name = elem->Attribute( "name" );
	elem->Attribute( "firstgid", &firstGid );
	elem->Attribute( "tilewidth",  &tileWidth  );
	elem->Attribute( "tileheight", &tileHeight );

	//----------------------------------------

	// Pegamos os atributos da imagem
	elem = node->FirstChildElement( "image" );

	// Pegamos os atributos da imagem
	elem->Attribute( "width",  &width  );
	elem->Attribute( "height", &height );

	// Capturamos o path da imagem
	std::string str = elem->Attribute( "source" );

	//------------------------------

	// Pegamos o path do arquivo .tmx
	unsigned found = source.find_last_of( "/" );

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

const std::string& TileSet::getName() const{
	return name;
}

//-----------------------------------------------------------

const std::string& TileSet::getSource() const{
	return source;
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
