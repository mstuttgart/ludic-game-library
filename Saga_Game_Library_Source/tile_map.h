#pragma once

#include "tile_set.h"
#include "layer.h"

namespace sgl {
namespace image {

class TileMap : public TmxBase {

private:

	int width;
	int height;
	int tileWidth;
	int tileheight;

	std::map<int, TileSet*> tilesetMap;
	std::map<const char*, Layer*> layerMap;
	
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
	void loadMap( const char* tmxFile );

};

}
} /* namespace */
