#pragma once
#include <math.h>
namespace sgl {
	class CollisionMask {};
	class RectangleMask: public CollisionMask {
	private:
		int xi, yi, xf, yf;
	public:
		int getXI() const;
		int getYI() const;
		int getXF() const;
		int getYF() const;
	public:
		RectangleMask(): RectangleMask(0, 0, 0, 0) {}
		RectangleMask(int, int, int, int);
		void setXI(int);
		void setYI(int);
		void setXF(int);
		void setYF(int);
	};
	class CircleMask: public CollisionMask {
	private:
		int xo, yo, r;
	public:
		int getXO() const;
		int getYO() const;
		int getR() const;
	public:
		CircleMask(): CircleMask(0, 0, 0) {}
		CircleMask(int, int, int);
		void setXO(int);
		void setYO(int);
		void setR(int);
	};

	class CollisionManager {
		static bool checkCollision(const RectangleMask&, const RectangleMask&);
		static int distance(int, int, int, int);
		static bool checkCollision(const CircleMask&, const CircleMask&);
		static bool checkCollision(const RectangleMask&, const CircleMask&);
		static bool checkCollision(int, int, const RectangleMask&);
		static bool checkCollision(int, int, const CircleMask&);
		static bool checkCollision(const CircleMask&, const RectangleMask&);
	};
}