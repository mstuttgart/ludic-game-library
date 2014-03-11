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

	int x;
	int y;
	int id;
	ALLEGRO_BITMAP* bitmap;

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
	virtual ~Tile();

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
	 * @return
	 */
	inline int getId() const;

	/**
	 * @brief
	 */
	inline void draw();

	/**
	 * @brief
	 * @param dx
	 * @param dy
	 */
	void scroll( int& dx, int& dy );

};

//-------------------------------------------------------

void Tile::draw() {
	al_draw_bitmap( bitmap, x, y, 0 );
}

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

int Tile::getId() const {
	return id;
};

//--------------------------------------------------------
}
} /* namespace */
