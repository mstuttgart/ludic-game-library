/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is FREE SOFTWARE released under the BSD License.                //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "sgl.hpp"
#include "image_resource.hpp"

#include <vector>

namespace Ludic
{

class CollisionMask
{

private:

	int width;
	int height;
	std::vector<bool> bits;

private:

	bool isColorEqual(ALLEGRO_COLOR col1, ALLEGRO_COLOR col2);
	bool isTransparent(ALLEGRO_COLOR col1);

public:

	CollisionMask();

	CollisionMask( Ludic::ImageResource* imgResource );

	virtual ~CollisionMask();

	void initMask( Ludic::ImageResource* imgResource );

	bool collisionVerify( const CollisionMask& mask, int xoffset, int yoffset ) const;

	int GetHeigth() const {
		return height;
	}

	int GetWidth() const {
		return width;
	}

};

} /* namespace */
