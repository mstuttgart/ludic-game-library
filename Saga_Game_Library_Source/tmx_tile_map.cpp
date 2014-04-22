#include "tmx_tile_map.h"
#include "video.h"
#include "color.h"

using namespace sgl::image;
using namespace sgl;
using namespace std;

//-------------------------------------------------

TMXTileMap::TMXTileMap() : rows ( 0 ), colums ( 0 ),
	width ( 0 ), height ( 0 ), tileWidth ( 0 ), tileHeight ( 0 ) {}

//-------------------------------------------------

TMXTileMap::~TMXTileMap() {
	// Deletamos cada um dos tiledLayers
	for( auto & x : tiledLayers )
		delete x.second;
}

//-------------------------------------------------

bool TMXTileMap::load( const String& file ) {

	// Criamos o loader
	TMXLoader loader;

	// Carregamos o arquivo .TMX. Se o load der errado retorna false.
	if( !loader.load( file ) )
		return false;

	// Carregamos o mapa
	load( &loader );

	return true;

}

//-------------------------------------------------

bool TMXTileMap::load( TMXLoader* loader ) {

	if( !loader )
		return false;

	// Realizamos o parser dos tilesets e layers
	loader->parseTileset();
	loader->parseLayers();

	// Inicializamos os atributos basicos da classe
	rows       = loader->getRows();
	colums     = loader->getColums();
	width      = loader->getWidth();
	height     = loader->getHeight();
	tileWidth  = loader->getTileWidth();
	tileHeight = loader->getTileHeight();

	// Iniciamos o tiledLayers
	initTilesLayers( *loader );

	cout << "TMXTileMap loaded successfully!" << endl;

	return true;

}

//-------------------------------------------------

void TMXTileMap::initTilesLayers( const TMXLoader& loader ) {

	// Recebemos os vetores que foram carregados pelo loader
	const vector< TMXTileSet* >& tmx_tilesets = loader.getTmxTilesets();
	const vector< TMXLayer* >&   tmx_layers   = loader.getTmxLayers();

	// Criamos um vetor para receber as ImageResource que servirao
	// como base para os tiles
	ImageResource* baseImage[ tmx_tilesets.size() ];

	cout << endl;

	// Carregamos as imagens
	for( unsigned int i = 0; i < tmx_tilesets.size(); i++ ) {

		try {
			// Criamos a imageResource
			baseImage[i] = ImageResource::createImageResource(
			                   tmx_tilesets[i]->getSource() );
		}
		catch( sgl::Exception& ex ) {
			cout << ex.what() << endl;
			return;
		}

		// Setamos a colorkey da imagem, se houver
		if( !tmx_tilesets[i]->getColorkey().empty() ) {
			baseImage[i]->setColorKey( Color( tmx_tilesets[i]->getColorkey() ) );
		}

	}//for i

	cout << endl;

	// Criamos o layer
	TiledLayer* l;

	for( unsigned int i = 0; i < tmx_layers.size(); i++ ) {

		// Recebemos o vetor de dados do tmx_layer
		const vector< TMXLayer::DataInfo >& data = tmx_layers[i]->getData();

		// Criamos o layer
		l = new TiledLayer( tmx_layers[i]->getName(), colums,
		                    width, height, tileWidth, tileHeight,
		                    data, tmx_tilesets, baseImage );

		// Setamos a visibilidade do layer de acordo com a visibilidade
		// do tmx_layer no editor Tiled
		l->setVisible( tmx_layers[i]->isVisible() );

		// Armazenamos o novo layer
		tiledLayers[ tmx_layers[i]->getName() ] = l;

	}//for i

}

//-------------------------------------------------

TiledLayer* TMXTileMap::getLayer ( const String& layerName ) {
	if ( hasLayer ( layerName ) )
		return tiledLayers.at ( layerName );

	cout << "Layer with layerName " << layerName << " no exist!" << endl;
	return nullptr;
}

//-----------------------------------------------------

void TMXTileMap::drawLayer ( const String& layerName ) {
	try {
		tiledLayers.at ( layerName )->draw();
	}
	catch ( const out_of_range& ex ) {
		cout << "Invalid value of layerName " << layerName << endl;
	}
}

//------------------------------------------------------

int TMXTileMap::getTileId ( const Vector2D& position ) {

	// Encontramos a coluna e fileria referente as coordenadas
	Vector2D bloc = position / Vector2D( tileWidth, tileHeight );

	// Calculamos o id global do tile
	return ( bloc.getX() + bloc.getY() * colums );
}

//----------------------------------------------

bool TMXTileMap::checkCollision ( const Sprite& spr, int movX, int movY,
                                  const String& layerName, int tileId ) {

	try {
		return tiledLayers.at ( layerName )->checkCollision (
		           spr, movX, movY, tileId );
	}
	catch ( const out_of_range& ex ) {
		cout << "Invalid value of layerName " << layerName << endl;
	}//catch

	// Mensagem caso o layer nao exista
	cout << "Layer with layerName " << layerName << " no exist!" << endl;

	return false;
}

//--------------------------------------------------------

void TMXTileMap::scroll ( float desloc ) {

	// Percorremo o mapa deletando os tiles deletaveis
	for ( auto & it : tiledLayers )
		it.second->scrool ( desloc );

}

//--------------------------------------------------------

void TMXTileMap::setScrollVelocity ( const String& layerName,
                                     const Vector2D& vel ) {

	try {
		// Aqui verificamos se o existe se layerName e valido.
		tiledLayers.at ( layerName )->setScroolSpeed( vel );
	}
	catch ( const out_of_range& ex ) {
		cout << "Invalid value of layerName " << layerName << endl;
	}
}

//--------------------------------------------------------

void TMXTileMap::setVisible ( bool visible ) {

	// Percorremo o mapa deletando os tiles deletaveis
	for ( auto & it : tiledLayers )
		it.second->setVisible ( visible );
}

//---------------------------------------------------------

bool TMXTileMap::hasLayer ( const String& name ) {

	// Iterator do map de layers
	itrL = tiledLayers.find ( name );

	return itrL != tiledLayers.end() ? true : false;

}

//--------------------------------------------------------

void TMXTileMap::setPosition ( const Vector2D& position ) {
	
	// Percorremo o mapa deletando os tiles deletaveis
	for ( auto & it : tiledLayers )
		it.second->setPosition ( position );
}

//-------------------------------------------------------

void TMXTileMap::setScreenDimension(int displayW, int displayH)
{
	// Percorremo o mapa deletando os tiles deletaveis
	for ( auto & it : tiledLayers )
		it.second->setScreenDimension( displayW, displayH );
}

//-------------------------------------------------------