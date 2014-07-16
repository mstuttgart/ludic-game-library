#include "tmx_tile_set.hpp"
#include "color.hpp"

#include <string>

using namespace Ludic;
using namespace std;

//////////////////////////////////////////////////////////////

TMXTileSet::TMXTileSet() :
	firstGid( 0 ), lastGid( 0 ), rows( 0 ), colums( 0 ), width( 0 ), height( 0 ),
	tileWidth( 0 ), tileHeight( 0 ), spacing( 0 ), margin( 0 ) {}

//////////////////////////////////////////////////////////////

void TMXTileSet::parse( TiXmlNode* node, const String& tmxFile ) {

	// Convertemos o node para element
	TiXmlElement* elem = node->ToElement();

	// Capturamos o nome do tileset
	name = elem->Attribute( "name" );

	// Capturamos os atributos do tileset
	elem->Attribute( "firstgid", &firstGid );
	elem->Attribute( "tilewidth",  &tileWidth  );
	elem->Attribute( "tileheight", &tileHeight );

	//----------------------------------------

	// Pegamos os atributos da offset
	elem = node->FirstChildElement( "tileoffset" );

	// Se elem nao fou NULL
	if( elem ) {

		int x, y;

		// Pegamos os atributos da imagem
		elem->Attribute( "x", &x );
		elem->Attribute( "y", &y );

		// Criamos o vetor offset
		offset = Ludic::Vector2D( x, y );

	}

	//----------------------------------------

	// Pegamos os atributos da imagem
	elem = node->FirstChildElement( "image" );

	// Variavel auxiliar
	const char* aux = elem->Attribute( "trans" );

	// Capturamos a colorkey do tileset, se nao houver colorkey
	// trans sera igual a NULL
	if( aux )
		colorkey = aux;

	// Pegamos os atributos da imagem
	elem->Attribute( "width",  &width  );
	elem->Attribute( "height", &height );

	//---------------------------------------

	// Salvamos o source da image
	source = elem->Attribute( "source" );

	//--------------------------------------

	// Criamos dois path baseados no source e no tmxFile
	ALLEGRO_PATH* sourcePath  = al_create_path( source.c_str()  );
	ALLEGRO_PATH* tmxFilePath = al_create_path( tmxFile.c_str() );

	if( !sourcePath || !tmxFilePath )
		std::cout << "Error in create path in TMXTileSet class." << std::endl;

	// Criamos a mascara que sera usada para ajustes do diretorio
	String mask( "../" );

	//Verificamos se os 3 primeiros caracteres sao iguais a mask
	while( !source.compare( 0, 3, mask ) ) {

		// Removemos a mascara do diretorio source
		al_remove_path_component( sourcePath, 0 );
		
		// Removemos um diretorio do tmxFile, de modo a deixar os dois
		// diretorios com o mesmo nivel
		al_remove_path_component( tmxFilePath, al_get_path_num_components( tmxFilePath ) - 1 );

		// Atualizamos o novo diretorio source
		source = al_path_cstr( sourcePath, ALLEGRO_NATIVE_PATH_SEP );
		
	}//while

	// Setamos como nova base de source, o diretorio tmxFilePath
	// ja configurado
	al_rebase_path( tmxFilePath, sourcePath );

	// Atualizamos o valor de source
	source = al_path_cstr( sourcePath, ALLEGRO_NATIVE_PATH_SEP );

	// Destruimos os paths
	al_destroy_path( sourcePath  );
	al_destroy_path( tmxFilePath );

	//---------------------------------------

	// Calculamos o numero de colunas e linhas do tileset
	rows   = height / tileHeight;
	colums = width / tileWidth;

	// Calculamos o lastGid
	lastGid = rows * colums + firstGid - 1;

}

//////////////////////////////////////////////////////////////
