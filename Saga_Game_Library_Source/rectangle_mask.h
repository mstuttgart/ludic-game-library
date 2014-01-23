#pragma once
#include "collision_mask.h"
namespace sgl {
	class RectangleMask: public CollisionMask {
	private:
		int x, y, w, h;
	public:
		int getW() const;
		int getH() const;
		int getXI() const;
		int getYI() const;
		int getXF() const;
		int getYF() const;
	public:
		RectangleMask(): RectangleMask(0, 0, 0, 0) {}
		RectangleMask(int x, int y, int w, int h);
		void setX(int value);
		void setY(int value);
		void setW(int value);
		void setH(int value);
	};
}