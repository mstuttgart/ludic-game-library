#include "point.h"
#include "util.h"
using namespace sgl;
//------------------------------------------------------------------------------
Point::Point() : x(0), y(0){} // Eu mudei aqui

Point::Point(int x, int y): x(x), y(y) {} 

int Point::getX() const {
	return x;
}
int Point::getY() const {
	return y;
}

void Point::setX(int value) {
	x=value;
}
void Point::setY(int value) {
	y=value;
}
int Point::distance(const Point& p) const {
	return distance(p.getX(), p.getY());
}
int Point::distance(int x, int y) const {
	return Util::squareRoot(
		Util::squarePow(this->x-x)+Util::squarePow(this->y-y));
}
void Point::move(int dx, int dy) {
	x+=dx;
	y+=dy;
}
bool Point::checkIntersection(const Point& p) const {
	return checkIntersection(p.getX(), p.getY());
}
bool Point::checkIntersection(int x, int y) const {
	return this->x==x && this->y==y;
}