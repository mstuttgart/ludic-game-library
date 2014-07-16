#include "collision_box.hpp"
#include <cmath>

using namespace Ludic;

//////////////////////////////////////////////////////////////////

CollisionBox::CollisionBox() : w( 0.0f ), h( 0.0f ) {

	/*positions.push_back( Vector2D() );
	positions.push_back( Vector2D() );*/

}

//////////////////////////////////////////////////////////////////

CollisionBox::CollisionBox( const Vector2D& position, float _w, float _h ) :
	w( _w ), h( _h ) {

	// Inicializamos os pontos inicial e final do retangulo
	positions[ VERTEX_I] = position;
	positions[ VERTEX_F] = position + Vector2D( _w, _h );

}

//////////////////////////////////////////////////////////////////

CollisionBox::~CollisionBox() {

	/*for( unsigned int i=0; i<vertices.size(); i++) {
		delete vertices[i];
	}//for*/

	//positions.clear();
}

//////////////////////////////////////////////////////////////////

void CollisionBox::setDimension( float w, float h ) {

	// Atualizamos a largura do retangulo
	this->w = w;
	this->h = h;

	// Atualizamos as coordenadas do vertice final
	positions[VERTEX_F] = positions[VERTEX_I] + Vector2D( w, h );
}

//////////////////////////////////////////////////////////////////

void CollisionBox::move( const Vector2D& vec ) {

	// Movimentamos o ponto inicial e final do retangulo
	positions[VERTEX_I] += vec;
	positions[VERTEX_F] += vec;
}

//////////////////////////////////////////////////////////////////

bool CollisionBox::checkCollision( const CollisionBox& r ) const {

	if( positions[ VERTEX_F ].getX() <= r.positions[ VERTEX_I ].getX() )
		return false;

	if( positions[ VERTEX_I ].getX() >= r.positions[ VERTEX_F ].getX() )
		return false;

	if( positions[ VERTEX_F ].getY() <= r.positions[ VERTEX_I ].getY() )
		return false;

	if( positions[ VERTEX_I ].getY() >= r.positions[ VERTEX_F ].getY() )
		return false;

	return true;
}

//////////////////////////////////////////////////////////////////

bool CollisionBox::checkCollision( int x, int y, int w, int h ) const {

	if( positions[ VERTEX_F ].getX() <= x )
		return false;

	if( positions[ VERTEX_I ].getX() >= x + w )
		return false;

	if( positions[ VERTEX_F ].getY() <= y )
		return false;

	if( positions[ VERTEX_I ].getY() >= y + h )
		return false;

	return true;

}

//////////////////////////////////////////////////////////////////

void CollisionBox::setPosition( const Vector2D& position ) {

	// Verificamos se o inidice e valido
	positions[ VERTEX_I ] = position;
	positions[ VERTEX_F ] = positions[ VERTEX_I ] + Vector2D( w, h );

}

//////////////////////////////////////////////////////////////////
