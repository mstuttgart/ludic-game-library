#include "tiled_layer.h"

#include <cmath>
#include <stdexcept>

using namespace sgl::image;
using namespace sgl;
using namespace std;

int* TiledLayer::colums = nullptr;

int* TiledLayer::width  = nullptr;
int* TiledLayer::height = nullptr;

int* TiledLayer::tileWidth  = nullptr;
int* TiledLayer::tileHeight = nullptr;

int* TiledLayer::displayW = nullptr;
int* TiledLayer::displayH = nullptr;

//-----------------------------------------------------------

TiledLayer::TiledLayer( const String& _name, int& _colums,
                        int& _width, int& _height,
                        int& _tileWidth, int& _tileHeight,
                        int _displayW, int _displayH,
                        std::map<int, Tile*>* _mapTiles ) :
	Layer(),
	name( _name ),
	velocity( 0.0f, 0.0f ),
	mapTiles( _mapTiles ) {

	// Recebemos o numero de colunas
	TiledLayer::colums = &_colums;
	
	TiledLayer::width  = &_width;
	TiledLayer::height = &_height; 

	// Recebemos as dimensoes dos tiles
	TiledLayer::tileWidth  = &_tileWidth;
	TiledLayer::tileHeight = &_tileHeight;

	// Guardamos a referencia do display
	displayW = new int( _displayW );
	displayH = new int( _displayH );

}

//---------------------------------------------------------

TiledLayer::~TiledLayer() {

	// Percorremo o mapa deletando os tiles deletaveis
	for( it = mapTiles->begin(); it != mapTiles->end(); ++it ) {

		if( it->second )
			delete it->second; // Pegamos o Tile
	}//for

	// Limpamos o mapa de tiles
	mapTiles->clear();

	// Deletamos o mapa
	delete mapTiles;

	if( displayW )
		delete displayW;

	if( displayH )
		delete displayH;

	colums = nullptr;
	
	width  = nullptr;
	height = nullptr;

	tileWidth  = nullptr;
	tileHeight = nullptr;

	displayW = nullptr;
	displayH = nullptr;

}

//-----------------------------------------------------------

void TiledLayer::setPosition( const Vector2D& vec ) {

	// Calculamos o deslocamento necessario
	Vector2D desloc = vec - Vector2D( getX(), getY() );

	// Atualizamos a posicao do mapa
	Layer::setPosition( vec );

	// Movemos os tiles que constituem este tiledlayer
	for( it = mapTiles->begin(); it != mapTiles->end(); ++it ) {
		it->second->move( vec );
	}

}

//-----------------------------------------------------------
void TiledLayer::scrool( float desloc ) {

	// Atualizamos a coordenada principal do tiledLayer
	Layer::move( velocity * desloc );

	// Realizamos o scrool do Tile
	for( it = mapTiles->begin(); it != mapTiles->end(); ++it ) {
		it->second->move( velocity * desloc );
	}

}

//-----------------------------------------------------------

void TiledLayer::setScroolSpeed( const Vector2D& vec ) {
	velocity = vec;
}

//-----------------------------------------------------------

void TiledLayer::draw() {

	// Verificamos se o layer esta visivel
	if( isVisible() ) {

		// Variavel auxiliar
		Tile* t;
		int dx;
		int dy;

		// Desenhamos cada tile do layer
		for( it = mapTiles->begin(); it != mapTiles->end(); ++it ) {

			t = it->second;

			// Pegamos as coordenadas X, Y do tile
			dx = t->getX();
			dy = t->getY();

			// Verifizamos se as coordenadas estao dentro do display,
			// se estiverem, desenhamos o Tile
			if( dx >= -( *tileWidth ) && dx <= ( *displayW ) &&
			        dy >= -( *tileHeight ) && dy <= ( *displayH ) )
				t->draw();
		}

	}// if

}

//----------------------------------------------------------

const Tile* TiledLayer::getTile( int id ) {

	// Criamos um iterator para o mapa
	it = mapTiles->find( id );

	// Verificamos se o resource esta presente no mapa
	return it != mapTiles->end() ? it->second : nullptr;
}

//---------------------------------------------------------

bool TiledLayer::checkCollision(
    const Sprite& spr, int movX, int movY, int tileId ) {

	// Pegamos o offset do layer
	int offsetX = abs( this->getX() );
	int offsetY = abs( this->getY() );

	// Calculamos a nova coordenada x e y com o acrescimo do movimento
	int auxX = offsetX + spr.getX() + movX;
	int auxY = offsetY + spr.getY() + movY;

	// Calculamos a coluna referente a localizacao do ponto X do sprite
	int iX = auxX / ( *tileWidth );

	// Calculamos a fileira referente a localizacao do ponto Y do Sprite
	int iY = auxY / ( *tileHeight );

	// Calculamos a coluna referente a localizacao do ponto Xf do Sprite
	int iMaxX = ( auxX + spr.getWidth() ) / ( *tileWidth );

	// Calculamos a fileira referente a localizacao do ponto Yf do Sprite
	int iMaxY = ( auxY + spr.getHeight() ) / ( *tileHeight );

	// Criamos um BoundingBox na futura posicao do sprite
	BoundingBox box1( Vector2D(auxX, auxY), spr.getWidth(), spr.getHeight() );

	// Variavel auxiliar
	const Tile* t = nullptr;

	// Percorremos do tile (X,Y) ate o tile (Xf,Yf)
	for( int j = iY; j <= iMaxY; j++ ) {

		for( int i = iX; i <= iMaxX; i++ ) {

			// Calculamos o id do tile ep egamos o tile no layer
			// e com o id calculado
			t = this->getTile( i + j * ( *colums ) );

			// Verificamos se o t é != NULL e se o Id do tile no layer
			// e o id que estamos procurando (tileId)
			if( t != nullptr && t->getId() == tileId ) {

				// Verificamos se ocorreu uma colisao
				if( box1.checkCollision( t->getBoundingBox() ) )
					return true;

			}//if

		}//for i

	}//for j

	return false;
}

//-----------------------------------------------------------

float TiledLayer::getWidth() const{
	return *width;
}
//-----------------------------------------------------------

float TiledLayer::getHeight() const {
	return *height;
}

//-----------------------------------------------------------