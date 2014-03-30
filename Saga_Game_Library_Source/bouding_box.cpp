#include "bouding_box.h"
#include <cmath>

using namespace sgl;

//---------------------------------------
BoundingBox::BoundingBox() : w( 0.0f ), h( 0.0f ) {

	/*positions.push_back( Vector2D() );
	positions.push_back( Vector2D() );*/

}

//---------------------------------------

BoundingBox::BoundingBox( const Vector2D& position, float _w, float _h ) :
	w( _w ), h( _h ) {

	// Inicializamos os pontos inicial e final do retangulo
	positions[ VERTICE_I] = position;
	positions[ VERTICE_F] = position + Vector2D( _w, _h );

}

//---------------------------------------

BoundingBox::~BoundingBox() {

	/*for( unsigned int i=0; i<vertices.size(); i++) {
		delete vertices[i];
	}//for*/

	//positions.clear();
}


//---------------------------------------

void BoundingBox::setDimension( float w, float h ) {

	// Atualizamos a largura do retangulo
	this->w = w;
	this->h = h;

	// Atualizamos as coordenadas do vertice final
	positions[VERTICE_F] = positions[VERTICE_I] + Vector2D( w, h );
}

//---------------------------------------

void BoundingBox::move( const Vector2D& vec ) {

	// Movimentamos o ponto inicial e final do retangulo
	positions[VERTICE_I] += vec;
	positions[VERTICE_F] += vec;
}

//---------------------------------------

bool BoundingBox::checkCollision( const BoundingBox& r ) const {

	if( positions[ VERTICE_F ].getX() <= r.positions[ VERTICE_I ].getX() )
		return false;

	if( positions[ VERTICE_I ].getX() >= r.positions[ VERTICE_F ].getX() )
		return false;

	if( positions[ VERTICE_F ].getY() <= r.positions[ VERTICE_I ].getY() )
		return false;

	if( positions[ VERTICE_I ].getY() >= r.positions[ VERTICE_F ].getY() )
		return false;

	return true;
}

//------------------------------------------------------------

bool BoundingBox::checkCollision( int x, int y, int w, int h ) const {

	if( positions[ VERTICE_F ].getX() <= x )
		return false;

	if( positions[ VERTICE_I ].getX() >= x + w )
		return false;

	if( positions[ VERTICE_F ].getY() <= y )
		return false;

	if( positions[ VERTICE_I ].getY() >= y + h )
		return false;

	return true;

}


//------------------------------------------------------------

void BoundingBox::setPosition( const Vector2D& position ) {

	// Verificamos se o inidice e valido
	positions[ VERTICE_I ] = position;
	positions[ VERTICE_F ] = positions[ VERTICE_I ] + Vector2D( w, h );

}

//------------------------------------------------------------
