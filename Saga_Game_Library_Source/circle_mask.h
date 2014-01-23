#pragma once
#include "collision_mask.h"
namespace sgl {
	class CircleMask: public CollisionMask {
	private:
		int x, y, r;
	public:
		int getX() const;
		int getY() const;
		int getR() const;
	public:
		CircleMask(): CircleMask(0, 0, 0) {}
		CircleMask(int x, int y, int r);
		void setX(int value);
		void setY(int value);
		void setR(int value);
	};
}