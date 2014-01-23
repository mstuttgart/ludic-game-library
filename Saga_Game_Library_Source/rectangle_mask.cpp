#include "rectangle_mask.h"
using namespace sgl;
//------------------------------------------------------------------------------
int RectangleMask::getW() const {
	return w;
}
int RectangleMask::getH() const {
	return h;
}
int RectangleMask::getXI() const {
		return x;
	}
int RectangleMask::getYI() const {
	return y;
}
int RectangleMask::getXF() const {
		return x+w;
	}
int RectangleMask::getYF() const {
	return y+h;
}
RectangleMask::RectangleMask(int x, int y, int w, int h):
	x(x), y(y), w(w), h(h) {}
void RectangleMask::setX(int value) {
	x=value;
}
void RectangleMask::setY(int value) {
	y=value;
}
void RectangleMask::setW(int value) {
	w=value;
}
void RectangleMask::setH(int value) {
	h=value;
}