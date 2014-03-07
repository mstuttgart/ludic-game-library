#pragma once

#include "sgl.h"
#include "tinyxml/tinyxml.h"

namespace sgl {
namespace image {

/**
 * @file tile.h
 * @author Michell Stuttgart
 * @date 02/16/14
 * @class Tile
 * @brief
 */
class Tile {

private:

	ALLEGRO_BITMAP* bitmap;
	int x;
	int y;
	const int index;

public:

	/**
	 * @brief
	 * @param node
	 */
	Tile( int& _x, int& _y, ALLEGRO_BITMAP* _bitmap, int& _index );

	/**
	 * @brief
	 * @return
	 */
	virtual ~Tile() {};

	/**
	 * @brief
	 * @return
	 */
	inline ALLEGRO_BITMAP* getBitmap() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getX() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getY() const;

	/**
	 * @brief
	 */
	void draw();

	/**
	 * @brief
	 * @param dx
	 * @param dy
	 */
	void scroll( int& dx, int& dy );

};

//--------------------------------------------------------

ALLEGRO_BITMAP* Tile::getBitmap() const {
	return bitmap;
}

//--------------------------------------------------------

int Tile::getX() const {
	return x;
}

//--------------------------------------------------------

int Tile::getY() const {
	return y;
}

//--------------------------------------------------------
}
} /* namespace */
