#pragma once

#include "sgl.hpp"
#include "image_resource.hpp"

#include <vector>

namespace sgl {
namespace image {

class CollisionMask {

private:

	int width;
	int heigth;
	std::vector<bool> bits;

public:

	CollisionMask();

	CollisionMask( sgl::image::ImageResource* imgResource );

	virtual ~CollisionMask();

	void initMask( sgl::image::ImageResource* imgResource );

	bool collisionVerify( const CollisionMask& mask, int xoffset, int yoffset );

	const std::vector<bool>& GetBits() const {
		return bits;
	}
	int GetHeigth() const {
		return heigth;
	}
	int GetWidth() const {
		return width;
	}

};

}
} /* namespace */
