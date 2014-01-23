#pragma once
namespace sgl {
	class Point {
	protected:
		int x, y;
	public:
		int getX() const;
		int getY() const;
	public:
		Point(): Point(0, 0) {}
		Point(int x, int y);
		void setX(int value);
		void setY(int value);
	public:
		int distance(const Point& p) const;
		int distance(int x, int y) const;
		void move(int dx, int dy);
		bool checkIntersection(const Point& p) const;
		virtual bool checkIntersection(int x, int y) const;
	};
}