#pragma once

#include "tile_set.h"
#include "layer.h"
#include "object_group.h"

#include <dirent.h>

namespace sgl {
namespace image {

class TileMap : public TmxBase {

private:

	const char* tileSetsDir;
	int width;
	int height;
	int tileWidth;
	int tileHeight;

	std::vector<TileSet*> tilesets;
	std::vector<Layer*> layers;
	std::vector<ObjectGroup*> objects;

	virtual void parse( TiXmlNode* root );

public:

	/**
	 * @brief
	 */
	TileMap();

	/**
	 * @brief
	 * @param tmxFile
	 */
	virtual ~TileMap();

	/**
	 * @brief
	 * @param tmxFile
	 */
	void loadMap( const char* tmxFileName );


	/**
	 * @brief 
	 * @param idx
	 * @return 
	 */
	Layer* getLayer( int idx );

	/**
	 * @brief 
	 * @return 
	 */
	int getSizeLayers() {
		return layers.size();
	}

};

}
} /* namespace */
