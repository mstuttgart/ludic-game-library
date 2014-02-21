#include "collision_rect.h"
#include "collision_circle.h"

using namespace sgl;

//---------------------------------------
CollisionRect::CollisionRect() : Point(), w(0), h(0) {}

//---------------------------------------

CollisionRect::CollisionRect(int x, int y, int w, int h):Point(x, y), w(w), h(h) {}

//---------------------------------------

int CollisionRect::getW() const {
	return w;
}

//---------------------------------------

int CollisionRect::getH() const {
	return h;
}

//---------------------------------------

int CollisionRect::getXI() const {
	return x;
}

//---------------------------------------

int CollisionRect::getYI() const {
	return y;
}

//---------------------------------------

int CollisionRect::getXF() const {
	return x+w;
}

//---------------------------------------

int CollisionRect::getYF() const {
	return y+h;
}

//---------------------------------------

void CollisionRect::setW(int value) {
	w=value;
}

//---------------------------------------

void CollisionRect::setH(int value) {
	h=value;
}

//---------------------------------------

void CollisionRect::setDimension(int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

//----------------------------------------
bool CollisionRect::checkCollision(int x, int y) const {
	return x>getXI() && x<getXF() && y>getYI() && y<getYF();
}

//---------------------------------------

bool CollisionRect::checkCollision(const CollisionRect& r) const {
	return getXI()<r.getXF() && getXF()>r.getXI() &&
	       getYI()<r.getYF() && getYF()>r.getYI();
}

//---------------------------------------

bool CollisionRect::checkCollision(const CollisionCircle& c) const {
	return c.checkCollision(*this);
}

//---------------------------------------
