#include "collision.h"
using namespace sgl;
//------------------------------------------------------------------------------
bool Collision::checkCollision(const RectangleMask& rm1, const RectangleMask& rm2) {
	return rm1.getXI()<rm2.getXF() && rm1.getXF()>rm2.getXI() &&
		rm1.getYI()<rm2.getYF() && rm1.getYF()>rm2.getYI();
}
int Collision::squareRoot(int value) {
	long long square=1, delta=3;
	while(square<=value) {
		square+=delta;
		delta+=2;
	}
	return (delta/2-1);
}
int Collision::distance(int x1, int y1, int x2, int y2) {
	return squareRoot((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
bool Collision::checkCollision(const CircleMask& c1, const CircleMask& c2) {
	int d=c1.getR()+c2.getR();
	return distance(c1.getX(), c1.getY(), c2.getX(), c2.getY())<d;
}
bool Collision::checkCollision(const RectangleMask& r, const CircleMask& c) {
	return checkCollision(c, r);
}
bool Collision::checkCollision(int x, int y, const RectangleMask& r) {
	return x>r.getXI()&&x<r.getXF()&&y>r.getYI()&&y<r.getYF();
}
bool Collision::checkCollision(int x, int y, const CircleMask& c) {
	return distance(x, y, c.getX(), c.getY())<c.getR();
}
bool Collision::checkCollision(const CircleMask& c, const RectangleMask& r) {
	int cx=c.getX(), cy=c.getY(), cr=c.getR();
	if(checkCollision(cx+cr, cy, r)) return true;
	else if(checkCollision(cx-cr, cy, r)) return true;
	else if(checkCollision(cx, cy+cr, r)) return true;
	else if(checkCollision(cx, cy-cr, r)) return true;
	else {
		int rxi=r.getXI(), ryi=r.getYI(), rxf=r.getXF(), ryf=r.getYF();
		if(checkCollision(rxi, ryi, c)) return true;
		else if(checkCollision(rxi, ryf, c)) return true;
		else if(checkCollision(rxf, ryi, c)) return true;
		else if(checkCollision(rxf, ryf, c)) return true;
		else return false;
	}
}