#include "rectangle.h"
#include "circle.h"
using namespace sgl;
//------------------------------------------------------------------------------
Rectangle::Rectangle() : Point(), w(0), h(0) {}

Rectangle::Rectangle(int x, int y, int w, int h):Point(x, y), w(w), h(h) {}

int Rectangle::getW() const {
	return w;
}
int Rectangle::getH() const {
	return h;
}
int Rectangle::getXI() const {
		return x;
	}
int Rectangle::getYI() const {
	return y;
}
int Rectangle::getXF() const {
		return x+w;
	}
int Rectangle::getYF() const {
	return y+h;
}

void Rectangle::setW(int value) {
	w=value;
}
void Rectangle::setH(int value) {
	h=value;
}
//------------------------------------------------------------------------------
bool Rectangle::checkIntersection(int x, int y) const {
	return x>getXI() && x<getXF() && y>getYI() && y<getYF();
}
bool Rectangle::checkIntersection(const Rectangle& r) const {
	return getXI()<r.getXF() && getXF()>r.getXI() &&
		getYI()<r.getYF() && getYF()>r.getYI();
}
bool Rectangle::checkIntersection(const Circle& c) const {
	return c.checkIntersection(*this);
}