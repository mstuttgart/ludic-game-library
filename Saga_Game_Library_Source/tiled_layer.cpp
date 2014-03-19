#include "tiled_layer.h"

#include <cmath>
#include <stdexcept>

using namespace sgl::image;
using namespace std;

int* TiledLayer::colums = nullptr;

short int* TiledLayer::displayW = nullptr;
short int* TiledLayer::displayH = nullptr;

short int* TiledLayer::tileWidth  = nullptr;
short int* TiledLayer::tileHeight = nullptr;

//-----------------------------------------------------------

TiledLayer::TiledLayer( const char* _name,
                        int& _colums,
                        int& _tileWidth,
                        int& _tileHeight,
                        int& _displayW,
                        int& _displayH,
                        std::map<int, Tile*>* _mapTiles ) :
	Layer(),
	name( _name ),
	vel_x( 1 ),
	vel_y( 1 ),
	mapTiles( _mapTiles ) {

	// Recebemos o numero de colunas
	TiledLayer::colums = new int( _colums );

	// Recebemos as dimensoes dos tiles
	TiledLayer::tileWidth  = new short int( _tileWidth );
	TiledLayer::tileHeight = new short int( _tileHeight );

	// Recebemos as dimensoes do monitor
	TiledLayer::displayW = new short int( _displayW );
	TiledLayer::displayH = new short int( _displayH );

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

	if( colums )
		delete colums;

	if( tileWidth )
		delete tileWidth;

	if( tileHeight )
		delete tileHeight;

	if( displayW )
		delete displayW;

	if( displayH )
		delete displayH;

	colums = nullptr;

	tileWidth  = nullptr;
	tileHeight = nullptr;

	displayW = nullptr;
	displayH = nullptr;

};

//-----------------------------------------------------------

void TiledLayer::setPosition( int x, int y ) {

	// Calculamos o deslocamento necessario
	int dx = x - getX();
	int dy = y - getY();

	// Atualizamos a posicao do mapa
	Layer::setPosition( x, y );

	// Movemos os tiles que constituem este tiledlayer
	for( it = mapTiles->begin(); it != mapTiles->end(); ++it ) {
		it->second->move( dx, dy );
	}

}

//-----------------------------------------------------------
void TiledLayer::scrool( unsigned int dx, unsigned int dy ) {

	int deslx = dx * vel_x;
	int desly = dy * vel_y;

	// Atualizamos a coordenada principal do tiledLayer
	Layer::move( deslx, desly );

	// Realizamos o scrool do Tile
	for( it = mapTiles->begin(); it != mapTiles->end(); ++it ) {
		it->second->move( deslx, desly );
	}

}

//-----------------------------------------------------------

void TiledLayer::setScroolSpeed( int vx, int vy ) {
	this->vel_x = vx;
	this->vel_y = vy;
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
			if( dx >= -( *tileWidth ) && dx <= *displayW &&
			        dy >= -( *tileHeight ) && dy <= *displayH )
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
    Sprite& spr, int movX, int movY, int tileId ) {

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
	int iMaxX = ( offsetX + spr.getXf() + movX ) / ( *tileWidth );

	// Calculamos a fileira referente a localizacao do ponto Yf do Sprite
	int iMaxY = ( offsetY + spr.getYf() + movY ) / ( *tileHeight );

	// Criamos um BoundingBox na futura posicao do sprite
	BoundingBox box1( auxX, auxY, spr.getWidth(), spr.getHeight() );

	// Criamos um BoundingBox para representar o tile que estamos procurando
	BoundingBox box2( 0, 0, *tileWidth, *tileHeight );

	// Variavel auxiliar
	const Tile* t = nullptr;

	// Percorremos do tile (X,Y) ate o tile (Xf,Yf)
	for( int j = iY; j <= iMaxY; j++ ) {

		for( int i = iX; i <= iMaxX; i++ ) {

			// Calculamos o id do tile ep egamos o tile no layer
			// e com o id calculado
			t = this->getTile( i + j * (*colums) );

			// Verificamos se o t é != NULL e se o Id do tile no layer
			// e o id que estamos procurando (tileId)
			if( t != nullptr && t->getId() == tileId ) {

				// Setamos as coordenadas do box2 de acordo com o tile
				box2.setXL( offsetX + t->getX() );
				box2.setYU( offsetY + t->getY() );

				// Verificamos se ocorreu uma colisao
				if( box2.checkCollision( box1 ) )
					return true;

			}//if

		}//for i

	}//for j

	return false;
}
