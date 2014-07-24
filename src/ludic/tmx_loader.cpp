#include "tmx_loader.hpp"
#include "util.hpp"

using namespace Ludic;
using namespace std;

//////////////////////////////////////////////////////////////

TMXLoader::TMXLoader() : version( 0.0f ),
	rows ( 0 ), colums ( 0 ), width ( 0 ), height ( 0 ),
	tileWidth ( 0 ), tileHeight ( 0 ), root( nullptr ) {}

//////////////////////////////////////////////////////////////

TMXLoader::TMXLoader( const String& file ) : version( 0.0f ),
	rows ( 0 ), colums ( 0 ), width ( 0 ), height ( 0 ),
	tileWidth ( 0 ), tileHeight ( 0 ), root( nullptr ) {

	// Chamamos o metodo load.
	// Em caso de erro lancamos uma excecao
	if( !this->load( file ) )
		throw Ludic::Exception( "Error to create TMXLoader" );

}

//////////////////////////////////////////////////////////////

TMXLoader::~TMXLoader() {
	// Chamamos o release para liberar os dados
	release();
}

//////////////////////////////////////////////////////////////

bool TMXLoader::load( const String& file ) {

	// Verificamos se a extensao do arquivo esta correta
	ALLEGRO_PATH* tmxFilePath = al_create_path( file.c_str() );

	if( !tmxFilePath ) {
		std::cout << "Error in create path in TMXMoader class." << std::endl;
		return false;
	}
	
	// Convertemos a string para lower case
	String ext = Ludic::Util::toLower( al_get_path_extension( tmxFilePath ) );

	// Verificamos a extensao do arquivo
	if( ext.compare( ".tmx" ) != 0 ) {
		cout << "Invalid extension of file " << file << endl;
		return false;
	}

	// Se o documento ja tiver sido usado, nos o reiniciamos
	release();

	this->file = file;

	// Carregamos o documento
	if ( !doc.LoadFile ( file.c_str() ) ) {
		cout << doc.ErrorDesc() << endl;
		return false;
	}//if

	// Carregamos o elemento root
	root = doc.FirstChild ( "map" );

	if ( root == nullptr ) {
		cout << "Failed to read tmx file: No root element." << endl;
		return false;
	}//if

	// Capturamos o no raiz
	TiXmlElement* elem = root->ToElement();

	// Pegamos os atributos do mapa
	elem->Attribute( "version", &version );
	elem->Attribute( "width", &colums   );
	elem->Attribute( "height", &rows    );
	elem->Attribute( "tilewidth", &tileWidth   );
	elem->Attribute( "tileheight", &tileHeight );

	orientation = elem->Attribute( "orientation" );

	// Calculamos as dimensoes do mapa em pixels
	width  = colums * tileWidth;
	height = rows   * tileHeight;

	// Realizamos o parse das properties
	parseProperty();

	return true;

}

//////////////////////////////////////////////////////////////

void TMXLoader::parseProperty() {

	// Ponteiro para primeiro elemento de properties
	TiXmlNode* node    = nullptr;
	TiXmlElement* elem = nullptr;

	// Recebemos o no de properties
	node = root->FirstChild( "properties" );

	// Se o no existir, lemos o primeiro elemento
	if( node != nullptr )
		elem = node->FirstChildElement( "property" );

	// variavel auxiliar
	//const char* aux = nullptr;

	while( elem != nullptr ) {

		// Lemos o conteudo do elemento
		const char* aux = elem->Attribute( "name" );

		// Inserimos no mapa a property e seu valor
		if( aux != nullptr )
			properties[ aux ] = elem->Attribute( "value" );

		// Pegamos o proximos elemento
		elem = elem->NextSiblingElement( "property" );

	}//while

}

//////////////////////////////////////////////////////////////

void TMXLoader::parseLayers() {

	// Primeiro no com tileset
	TiXmlNode* node = root->FirstChild ( "layer" );

	while ( node != nullptr ) {

		// Criamos o tileset
		TMXLayer* l = new TMXLayer();

		// Realizamos o parser
		l->parse( node );

		// Armazenamos o tileset
		tmx_layers.push_back( l );

		// Proximo no com tileset
		node = node->NextSibling ( "layer" );

	}//while

}

//////////////////////////////////////////////////////////////

void TMXLoader::parseTileset() {

	// Primeiro no com tileset
	TiXmlNode* node = root->FirstChild( "tileset" );

	while ( node != nullptr ) {

		// Criamos o tileset
		TMXTileSet* t = new TMXTileSet();

		// Realizamos o parser
		t->parse( node, file );

		// Armazenamos o tileset
		tmx_tilesets.push_back( t );

		// Proximo no com tileset
		node = node->NextSibling ( "tileset" );

	}//while

}

//////////////////////////////////////////////////////////////

void TMXLoader::release() {

	// Percorremo os vetores deletando os tilesets
	for( unsigned int i = 0; i < tmx_layers.size(); i++ ) {
		delete tmx_layers[i];
	}

	// Percorremo os vetores deletando os layers
	for( unsigned int i = 0; i < tmx_tilesets.size(); i++ ) {
		delete tmx_tilesets[i];
	}

	// Limpamos os mapas
	tmx_tilesets.clear();
	tmx_layers.clear();

	// Fechamos o documento
	doc.Clear();

	// Reiniciamos os atributos
	version = 0.0f;
	orientation.clear();

	rows       = 0;
	colums     = 0;
	width      = 0;
	height     = 0;
	tileWidth  = 0;
	tileHeight = 0;

	root = nullptr;

}

//////////////////////////////////////////////////////////////

int TMXLoader::getColums() const {
	return colums;
}

//////////////////////////////////////////////////////////////

int TMXLoader::getHeight() const {
	return height;
}

//////////////////////////////////////////////////////////////

const String& TMXLoader::getOrientation() const {
	return orientation;
}

//////////////////////////////////////////////////////////////

int TMXLoader::getRows() const {
	return rows;
}

//////////////////////////////////////////////////////////////

int TMXLoader::getTileHeight() const {
	return tileHeight;
}

//////////////////////////////////////////////////////////////

int TMXLoader::getTileWidth() const {
	return tileWidth;
}

//////////////////////////////////////////////////////////////

const std::vector<TMXLayer*>& TMXLoader::getTmxLayers() const {
	return tmx_layers;
}

//////////////////////////////////////////////////////////////

const std::vector<TMXTileSet*>& TMXLoader::getTmxTilesets() const {
	return tmx_tilesets;
}

//////////////////////////////////////////////////////////////

const std::map<String, String>& TMXLoader::getProperties() const {
	return properties;
}

//////////////////////////////////////////////////////////////

double TMXLoader::getVersion() const {
	return version;
}

//////////////////////////////////////////////////////////////

int TMXLoader::getWidth() const {
	return width;
}

//////////////////////////////////////////////////////////////
