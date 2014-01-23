#include "circle_mask.h"
using namespace sgl;
//------------------------------------------------------------------------------
int CircleMask::getX() const {
	return x;
}
int CircleMask::getY() const {
	return y;
}
int CircleMask::getR() const {
	return r;
}
CircleMask::CircleMask(int x, int y, int r):
	x(x), y(y), r(r) {}
void CircleMask::setX(int value) {
	x=value;
}
void CircleMask::setY(int value) {
	y=value;
}
void CircleMask::setR(int value) {
	r=value;
}