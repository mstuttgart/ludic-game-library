#pragma once
#include "point.h"
namespace sgl {
	class Circle;
	class Rectangle: public Point {
	private:
		int w, h;
	public:
		int getW() const;
		int getH() const;
		int getXI() const;
		int getYI() const;
		int getXF() const;
		int getYF() const;
	public:
		Rectangle(); // Eu mudei aqui
		Rectangle(int x, int y, int w, int h);
		void setW(int value);
		void setH(int value);
	public:
		bool checkIntersection(int x, int y) const;
		bool checkIntersection(const Rectangle& r) const;
		bool checkIntersection(const Circle& c) const;
	};
}