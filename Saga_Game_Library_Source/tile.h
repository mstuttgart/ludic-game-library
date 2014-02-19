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
	const int index;

public:

	/**
	 * @brief
	 * @param node
	 */
	Tile( int _x, int _y, ALLEGRO_BITMAP* _bitmap, int _index );

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
	ALLEGRO_BITMAP* getBitmap();
	
	/**
	 * @brief 
	 * @return 
	 */
	int getX() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	int getY() const;
	
	/**
	 * @brief
	 */
	void draw();

};

}
} /* namespace */
