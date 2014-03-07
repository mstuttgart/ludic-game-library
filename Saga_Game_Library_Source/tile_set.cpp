#include "tile_set.h"
#include "color.h"

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
	//Resource::destroyResource( image ); // Destruimos a imagem
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
	
	// Capturamos a colorkey do tileset, se nao houver colorkey
	// trans sera igual a NULL
	const char* trans = elem->Attribute( "trans" );

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
	
	// Se o tileset possuir uma colorkey, nos a setamos na imagem resource
	if( trans )	{
		image->setColorKey( sgl::Color::getColorOf_HTML( trans ) );
	}

	//---------------------------------------

	// Calculamos o numero de colunas e linhas do tileset
	rows   = height / tileHeight;
	colums = width / tileWidth;

	// Calculamos o lastGid
	lastGid = rows * colums + firstGid - 1;

}

//---------------------------------------------------------------
