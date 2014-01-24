#include "circle.h"
using namespace sgl;
//------------------------------------------------------------------------------
Circle::Circle():Point(),r(0) {}

Circle::Circle(int x, int y, int r):Point(x, y), r(r) {}

int Circle::getR() const {
	return r;
}

void Circle::setR(int value) {
	r=value;
}
bool Circle::checkIntersection(int x, int y) const {
	return distance(x, y)<r;
}
bool Circle::checkIntersection(const Circle& c) const {
	int d=r+c.getR();
	return distance(c.getX(), c.getY())<d;
}
bool Circle::checkIntersection(const Rectangle& r) const {
	int rxi=r.getXI(), ryi=r.getYI(), rxf=r.getXF(), ryf=r.getYF();
	return checkIntersection(rxi, ryi)||checkIntersection(rxi, ryf)||
		checkIntersection(rxf, ryi)||checkIntersection(rxf, ryf)||
		r.checkIntersection(x+getR(), y)||r.checkIntersection(x-getR(), y)||
		r.checkIntersection(x, y+getR())||r.checkIntersection(x, y-getR());
}