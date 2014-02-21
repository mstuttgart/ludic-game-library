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

bool CollisionCircle::checkCollision(int x, int y) const {
	return distance(x, y)<r;
}

//---------------------------------------------

bool CollisionCircle::checkCollision(const CollisionCircle& c) const {
	int d=r+c.getR();
	return distance(c.getX(), c.getY())<d;
}

//---------------------------------------------

bool CollisionCircle::checkCollision(const CollisionRect& r) const {
	int rxi=r.getXI(), ryi=r.getYI(), rxf=r.getXF(), ryf=r.getYF();
	return checkCollision(rxi, ryi)||checkCollision(rxi, ryf)||
	       checkCollision(rxf, ryi)||checkCollision(rxf, ryf)||
	       r.checkCollision(x+getR(), y)||r.checkCollision(x-getR(), y)||
	       r.checkCollision(x, y+getR())||r.checkCollision(x, y-getR());
}

//---------------------------------------------