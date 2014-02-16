#pragma once

#include "tile.h"
#include "image_resource.h"

namespace sgl {
namespace image {

class TileSet {

private:

	int firstGid;
	const char* name;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	ImageResource* image;
	std::map<int, Tile*> tiles;

public:
	TileSet();
	virtual ~TileSet();

};

}
} /* namespace */
