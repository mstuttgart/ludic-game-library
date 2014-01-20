#include "collision.h"
using namespace sgl;
//------------------------------------------------------------------------------
int RectangleMask::getXI() const {
		return xi;
	}
int RectangleMask::getYI() const {
	return yi;
}
int RectangleMask::getXF() const {
	return xf;
}
int RectangleMask::getYF() const {
	return yf;
}
RectangleMask::RectangleMask(int xi, int yi, int xf, int yf):
	xi(xi), yi(yi), xf(xf), yf(yf) {}
void RectangleMask::setXI(int value) {
	xi=value;
}
void RectangleMask::setYI(int value) {
	yi=value;
}
void RectangleMask::setXF(int value) {
	xf=value;
}
void RectangleMask::setYF(int value) {
	yf=value;
}
//------------------------------------------------------------------------------
int CircleMask::getXO() const {
	return xo;
}
int CircleMask::getYO() const {
	return yo;
}
int CircleMask::getR() const {
	return r;
}
CircleMask::CircleMask(int xo, int yo, int r):
	xo(xo), yo(yo), r(r) {}
void CircleMask::setXO(int value) {
	xo=value;
}
void CircleMask::setYO(int value) {
	yo=value;
}
void CircleMask::setR(int value) {
	r=value;
}
//------------------------------------------------------------------------------
bool CollisionManager::checkCollision(const RectangleMask& r1, const RectangleMask& r2) {
	return r2.getXF()>r1.getXI() && r2.getXI()<r1.getXF() &&
		r2.getYF()>r1.getYI() && r2.getYI()<r1.getYF();
}
int CollisionManager::distance(int x1, int y1, int x2, int y2) {
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
bool CollisionManager::checkCollision(const CircleMask& c1, const CircleMask& c2) {
	int D=distance(c1.getXO(), c1.getYO(), c2.getXO(), c2.getYO());
	int d=c1.getR()+c2.getR();
	return D<d;
}
bool CollisionManager::checkCollision(const RectangleMask& r, const CircleMask& c) {
	return checkCollision(c, r);
}
bool CollisionManager::checkCollision(int x, int y, const RectangleMask& r) {
	return x>r.getXI()&&x<r.getXF()&&y>r.getYI()&&y<r.getYF();
}
bool CollisionManager::checkCollision(int x, int y, const CircleMask& c) {
	return distance(x, y, c.getXO(), c.getYO())<c.getR();
}
bool CollisionManager::checkCollision(const CircleMask& c, const RectangleMask& r) {
	int cx=c.getXO(), cy=c.getYO(), cr=c.getR();
	bool ct1=checkCollision(cx+cr, cy, r)||checkCollision(cx-cr, cy, r)||
		checkCollision(cx, cy+cr, r)||checkCollision(cx, cy-cr, r);
	int rxi=r.getXI(), ryi=r.getYI(), rxf=r.getXF(), ryf=r.getYF();
	bool ct2=checkCollision(rxi, ryi, c)||checkCollision(rxf, ryi, c)||
		checkCollision(rxi, ryf, c)||checkCollision(rxf, ryf, c);
	return ct1||ct2;
}