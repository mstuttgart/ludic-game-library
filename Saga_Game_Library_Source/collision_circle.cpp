#include "collision_circle.h"

using namespace sgl;

//---------------------------------------------

CollisionCircle::CollisionCircle():Point(),r(0) {}

//---------------------------------------------

CollisionCircle::CollisionCircle(int x, int y, int r):Point(x, y), r(r) {}

//---------------------------------------------

int CollisionCircle::getR() const {
	return r;
}

//---------------------------------------------

void CollisionCircle::setR(int value) {
	r=value;
}

//---------------------------------------------

bool CollisionCircle::checkIntersection(int x, int y) const {
	return distance(x, y)<r;
}

//---------------------------------------------

bool CollisionCircle::checkIntersection(const CollisionCircle& c) const {
	int d=r+c.getR();
	return distance(c.getX(), c.getY())<d;
}

//---------------------------------------------

bool CollisionCircle::checkIntersection(const CollisionRect& r) const {
	int rxi=r.getXI(), ryi=r.getYI(), rxf=r.getXF(), ryf=r.getYF();
	return checkIntersection(rxi, ryi)||checkIntersection(rxi, ryf)||
	       checkIntersection(rxf, ryi)||checkIntersection(rxf, ryf)||
	       r.checkIntersection(x+getR(), y)||r.checkIntersection(x-getR(), y)||
	       r.checkIntersection(x, y+getR())||r.checkIntersection(x, y-getR());
}

//---------------------------------------------