#pragma once

#include "sgl.h"
#include "image_resource.h"
#include "bouding_box.h"


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

	int id;
	Vector2D position;
	ImageResource* bitmap;
	BoundingBox box;

public:

	/**
	 * @brief
	 * @param node
	 */
	Tile( int& _x, int& _y, const int& _id, int& w, int& h, ImageResource* _bitmap );

	/**
	 * @brief
	 * @return
	 */
	virtual ~Tile();

	/**
	 * @brief
	 * @return
	 */
	inline operator ALLEGRO_BITMAP*() const;

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
	inline const BoundingBox& getBoundingBox() const;

	/**
	 * @brief
	 * @return
	 */
	inline const int& getId() const;

	/**
	 * @brief
	 */
	inline void draw();

	/**
	 * @brief
	 * @param dx
	 * @param dy
	 */
	void move( const Vector2D& vec );

};

//-------------------------------------------------------

void Tile::draw() {
	al_draw_bitmap( *bitmap, position.getX(), position.getY(), 0 );
}

//-------------------------------------------------------

inline const BoundingBox& Tile::getBoundingBox() const {
	return box;
}

//--------------------------------------------------------

Tile::operator ALLEGRO_BITMAP*() const {
	return *bitmap;
}

//--------------------------------------------------------

int Tile::getX() const {
	return position.getX();
}

//--------------------------------------------------------

int Tile::getY() const {
	return position.getY();
}

//--------------------------------------------------------

const int& Tile::getId() const {
	return id;
}

//--------------------------------------------------------
}
} /* namespace */
