#include "tiled_layer.h"
#include "color.h"

#include <cmath>
#include <stdexcept>

using namespace sgl::image;
using namespace sgl;
using namespace std;

//-----------------------------------------------------------

TiledLayer::TiledLayer( const String& _name, int& _colums,
                        int& _width, int& _height,
                        int& _tileWidth, int& _tileHeight,
                        const vector< TMXLayer::DataInfo >& data, const vector< TMXTileSet* >& tmxTileset,
                        ImageResource* baseImages[] ) :
	Layer(),
	name( _name ),
	velocity( 0.0f, 0.0f ) {

	// Recebemos o numero de colunas
	TiledLayer::colums = &_colums;

	TiledLayer::width  = &_width;
	TiledLayer::height = &_height;

	// Recebemos as dimensoes dos tiles
	TiledLayer::tileWidth  = &_tileWidth;
	TiledLayer::tileHeight = &_tileHeight;

	// Guardamos a referencia do display
	displayW = _width;
	displayH = _height;

	// Variaveis temporarias
	int x, y, w, h;
	int firstGid;
	ImageResource* bitmap;

	for( unsigned int i = 0; i < data.size(); i++ ) {

		for( unsigned int j = 0; j < tmxTileset.size(); j++ ) {

			// Pegamos o primeiro id do tileset
			firstGid = tmxTileset[j]->getFirstGid();

			if( data[i].gid >= firstGid && data[i].gid <= tmxTileset[j]->getLastGid() ) {

				w = tmxTileset[j]->getTileWidth();
				h = tmxTileset[j]->getTileHeight();

				// Calculamos a posicao do tile dentro do seu respectivo
				// tileset
				x = ( ( data[i].gid - firstGid ) % tmxTileset[j]->getColums() ) * w;
				y = ( ( data[i].gid - firstGid ) / tmxTileset[j]->getColums() ) * h;

				// Criamos um subbitmap com estas coordenadas
				// Este subbitmap representa o tile em questao
				bitmap = baseImages[j]->getSubImageResource( x, y, w, h );

				// Calculamos as coordenadas do tile no display
				x = ( data[i].index % ( *colums ) ) * ( *tileWidth );
				y = ( data[i].index / ( *colums ) ) * ( *tileHeight ) - h + ( *tileHeight );

				// Criamos o Tile e inserimos no mapa
				mapTiles[ data[i].index ] =
				    new Tile( x, y, data[i].gid, *tileWidth, *tileHeight, bitmap );

			}//if

		}//for

	}//for i

}

//---------------------------------------------------------

TiledLayer::~TiledLayer() {

	// Deletamos cada um dos tiles
	for( auto & t : mapTiles ) {
		delete t.second;
	}

	// Limpamos o mapa de tiles
	mapTiles.clear();

	colums = nullptr;

	width  = nullptr;
	height = nullptr;

	tileWidth  = nullptr;
	tileHeight = nullptr;
}

//-----------------------------------------------------------

void TiledLayer::setPosition( const Vector2D& vec ) {

	// Calculamos o deslocamento necessario
	Vector2D desloc = vec - Vector2D( getX(), getY() );

	// Atualizamos a posicao do mapa
	Layer::setPosition( vec );

	// Movemos os tiles que constituem este tiledlayer
	for( it = mapTiles.begin(); it != mapTiles.end(); ++it ) {
		it->second->move( vec );
	}

}

//-----------------------------------------------------------
void TiledLayer::scrool( float desloc ) {

	// Atualizamos a coordenada principal do tiledLayer
	Layer::move( velocity * desloc );

	// Realizamos o scrool do Tile
	for( it = mapTiles.begin(); it != mapTiles.end(); ++it ) {
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
		for( it = mapTiles.begin(); it != mapTiles.end(); ++it ) {

			t = it->second;

			// Pegamos as coordenadas X, Y do tile
			dx = t->getX();
			dy = t->getY();

			// Verifizamos se as coordenadas estao dentro do display,
			// se estiverem, desenhamos o Tile
			if( dx >= -( *tileWidth ) && dx <= ( displayW ) &&
			        dy >= -( *tileHeight ) && dy <= ( displayH ) )
				t->draw();
		}

	}// if

}

//----------------------------------------------------------

const Tile* TiledLayer::getTile( int id ) {

	// Criamos um iterator para o mapa
	it = mapTiles.find( id );

	// Verificamos se o resource esta presente no mapa
	return it != mapTiles.end() ? it->second : nullptr;
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
	BoundingBox box1( Vector2D( auxX, auxY ), spr.getWidth(), spr.getHeight() );

	// Variavel auxiliar
	const Tile* t = nullptr;

	// Percorremos do tile (X,Y) ate o tile (Xf,Yf)
	for( int j = iY; j <= iMaxY; j++ ) {

		for( int i = iX; i <= iMaxX; i++ ) {

			// Calculamos o id do tile e pegamos o tile no layer
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

float TiledLayer::getWidth() const {
	return *width;
}
//-----------------------------------------------------------

float TiledLayer::getHeight() const {
	return *height;
}

//-----------------------------------------------------------

void TiledLayer::setScreenDimension( int width, int height ) {
	this->displayW = width;
	this->displayH = height;
}

//-------------------------------------------------------------