#pragma once
#include <math.h>
#include "rectangle_mask.h"
#include "circle_mask.h"
namespace sgl {
	class Collision {
	public:
		static bool checkCollision(const RectangleMask& rm1, const RectangleMask& rm2);
		static int squareRoot(int value);
		static int distance(int x1, int y1, int x2, int y2);
		static bool checkCollision(const CircleMask& cm1, const CircleMask& cm2);
		static bool checkCollision(const RectangleMask& rm, const CircleMask& cm);
		static bool checkCollision(int x, int y, const RectangleMask& rm);
		static bool checkCollision(int x, int y, const CircleMask& cm);
		static bool checkCollision(const CircleMask& cm, const RectangleMask& rm);
	};
}