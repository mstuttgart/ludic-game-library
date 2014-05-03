#pragma once

#include "sgl.h"
#include "image_resource.h"
#include "bouding_box.h"

namespace sgl {
namespace image {

/**
 * @file frame.h
 * @author Michell Stuttgart
 * @date 04/15/14
 * @class Frame
 * @brief
 */
class Frame {

private:

	int id;
	int width;
	int height;
	ImageResource* bitmap;

public:

	/**
	 * @brief
	 * @param _id
	 * @param w
	 * @param h
	 * @param _bitmap
	 */
	Frame( const int& _id, const int& w, const int& h, ImageResource* _bitmap );

	/**
	 * @brief
	 */
	virtual ~Frame();

	/**
	 * @brief
	 * @return
	 */
	inline operator ALLEGRO_BITMAP*() const;

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
	 * @return
	 */
	inline int getHeight() const;

	/**
	 * @brief
	 * @return
	 */
	inline int getWidth() const;

};

//--------------------------------------------------------

Frame::operator ALLEGRO_BITMAP*() const {
	return *bitmap;
}

//--------------------------------------------------------

const int& Frame::getId() const {
	return id;
}

//--------------------------------------------------------

int Frame::getHeight() const {
	return height;
}

//--------------------------------------------------------

int Frame::getWidth() const {
	return width;
}

//--------------------------------------------------------

}
} /* namespace */
