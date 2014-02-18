#pragma once

#include "tmx_base.h"
#include "sgl.h"

namespace sgl {
namespace image {


/**
 * @file tile.h
 * @author Michell Stuttgart
 * @date 02/16/14
 * @class Tile
 * @brief
 */
class Tile : public TmxBase {

private:

	ALLEGRO_BITMAP* bitmap;
	const int x;
	const int y;

public:



	/**
	 * @brief
	 * @param node
	 */
	Tile( int _x, int _y, ALLEGRO_BITMAP* _bitmap );

	/**
	 * @brief
	 * @return
	 */
	virtual ~Tile() {};


	/**
	 * @brief
	 * @param elem
	 */
	virtual void parse( TiXmlNode* node );

	/**
	 * @brief
	 * @return
	 */
	//inline int getId() { return id;	}
	
	void draw();

};

}
} /* namespace */
