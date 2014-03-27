#include "bouding_box.h"
#include <cmath>

using namespace sgl;

//---------------------------------------
BoundingBox::BoundingBox() : w(0), h(0) {

	vertices.push_back( new Point( 0, 0 ) );
	vertices.push_back( new Point( 0, 0 ) );

}

//---------------------------------------

BoundingBox::BoundingBox(int _x, int _y, int _w, int _h) : w(_w), h(_h) {

	// Inicializamos os pontos inicial e final do retangulo
	vertices.push_back( new Point( _x, _y ) );
	vertices.push_back( new Point( _x + _w, _y + _h ) );

}

//---------------------------------------

BoundingBox::~BoundingBox() {

	for( unsigned int i=0; i<vertices.size(); i++) {
		delete vertices[i];
	}//for

	vertices.clear();
}

//---------------------------------------

void BoundingBox::setXL(int x) {
	vertices[VERTICE_I]->setX( x );
	vertices[VERTICE_F]->setX( x + w );
}

//---------------------------------------

void BoundingBox::setYU(int y) {
	vertices[VERTICE_I]->setY( y );
	vertices[VERTICE_F]->setY( y + h );
}

//---------------------------------------

void BoundingBox::setW(int value) {

	// Atualizamos a largura do retangulo
	this->w = value;

	// Atualizamos as coordenadas do vertice final
	vertices[VERTICE_F]->setX( vertices[VERTICE_I]->getX() + value );
}

//---------------------------------------

void BoundingBox::setH(int value) {

	// Atualizamos a largura do retangulo
	this->h = value;

	// Atualizamos as coordenadas do vertice final
	vertices[VERTICE_F]->setY( vertices[VERTICE_I]->getY() + value );
}

//---------------------------------------

void BoundingBox::moveRectangle(int dx, int dy) {

	// Movimentamos o ponto inicial e final do retangulo
	vertices[VERTICE_I]->move( dx, dy );
	vertices[VERTICE_F]->move( dx, dy );
}

//---------------------------------------

bool BoundingBox::checkCollision(const BoundingBox& r) const {

	if( getXR() <= r.getXL() ) return false;

	if( getXL() >= r.getXR() ) return false;

	if( getYB() <= r.getYU() ) return false;

	if( getYU() >= r.getYB() ) return false;

	return true;
}

//------------------------------------------------------------

bool BoundingBox::checkCollision(int x, int y, int w, int h) const {

	if( getXR() <= x ) return false;

	if( getXL() >= x + w ) return false;

	if( getYB() <= y ) return false;

	if( getYU() >= y + h ) return false;

	return true;

}

//---------------------------------------

bool BoundingBox::checkHorizontalCollision(const BoundingBox& r) {

	if( getXR() <= r.getXL() ) return false;

	if( getXL() >= r.getXR() ) return false;

	return true;
}

//---------------------------------------

bool BoundingBox::checkVerticalCollision(const BoundingBox& r) {

	if( getYB() <= r.getYU() ) return false;

	if( getYU() >= r.getYB() ) return false;

	return true;
}

//------------------------------------------------------------

bool BoundingBox::checkHorizontalCollision( int x, int w ) {

	if( getXR() <= x ) return false;

	if( getXL() >= x + w ) return false;

	return true;

}

//------------------------------------------------------------

bool BoundingBox::checkVerticalCollision(int y, int h) {
	
	if( getYB() < y ) return false;

	if( getYU() > y + h ) return false;

	return true;
}

//------------------------------------------------------------
