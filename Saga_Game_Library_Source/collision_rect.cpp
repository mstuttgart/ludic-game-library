#include "collision_rect.h"
//#include "collision_circle.h"

using namespace sgl;

//---------------------------------------
CollisionRect::CollisionRect() : w(0), h(0) {

	vertices.push_back( new Point( 0, 0 ) );
	vertices.push_back( new Point( 0, 0 ) );

}

//---------------------------------------

CollisionRect::CollisionRect(int _x, int _y, int _w, int _h) : w(_w), h(_h) {

	// Inicializamos os pontos inicial e final do retangulo
	vertices.push_back( new Point( _x, _y ) );
	vertices.push_back( new Point( _x + _w, _y + _h ) );

}

//---------------------------------------

CollisionRect::~CollisionRect() {

	for( unsigned int i=0; i<vertices.size(); i++) {
		delete vertices[i];
	}//for

	vertices.clear();
}

//---------------------------------------

void CollisionRect::setXi(int x) {
	vertices[VERTICE_I]->setX( x );
	vertices[VERTICE_F]->setX( x + w );
}

//---------------------------------------

void CollisionRect::setYi(int y) {
	vertices[VERTICE_I]->setY( y );
	vertices[VERTICE_F]->setY( y + h );
}

//---------------------------------------

int CollisionRect::getW() const {
	return w;
}

//---------------------------------------

int CollisionRect::getH() const {
	return h;
}

//---------------------------------------

int CollisionRect::getXi() const {
	return vertices[VERTICE_I]->getX();
}

//---------------------------------------

int CollisionRect::getYi() const {
	return vertices[VERTICE_I]->getY();
}

//---------------------------------------

int CollisionRect::getXf() const {
	return vertices[VERTICE_F]->getX();
}

//---------------------------------------

int CollisionRect::getYf() const {
	return vertices[VERTICE_F]->getY();
}

//---------------------------------------

void CollisionRect::setW(int value) {

	// Atualizamos a largura do retangulo
	w = value;

	// Atualizamos as coordenadas do vertice final
	vertices[VERTICE_F]->setX( vertices[VERTICE_I]->getX() + value );
}

//---------------------------------------

void CollisionRect::setH(int value) {

	// Atualizamos a largura do retangulo
	h = value;

	// Atualizamos as coordenadas do vertice final
	vertices[VERTICE_F]->setY( vertices[VERTICE_I]->getY() + value );
}

//---------------------------------------

bool CollisionRect::checkCollision(const CollisionRect& r) const {

	if( getXi() < r.getXf() ) return false;

	if( getXf() > r.getXi() ) return false;

	if( getYi() < r.getYf() ) return false;

	if( getYf() > r.getYi() ) return false;

	return true;
}

//---------------------------------------

void CollisionRect::moveRectangle(int dx, int dy) {
	
	// Movimentamos o ponto inicial e final do retangulo
	vertices[VERTICE_I]->move( dx, dy );
	vertices[VERTICE_F]->move( dx, dy );
}

//---------------------------------------
