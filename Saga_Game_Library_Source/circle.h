#pragma once
#include "point.h"
#include "rectangle.h"
namespace sgl {
	class Circle: public Point {
	private:
		int r;
	public:
		int getR() const;
	public:
		Circle(): Circle(0, 0, 0) {}
		Circle(int x, int y, int r);
		void setR(int value);
	public:
		bool checkIntersection(int x, int y) const;
		bool checkIntersection(const Circle& c) const;
		bool checkIntersection(const Rectangle& r) const;
	};
}