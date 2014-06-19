#include "frame.hpp"

using namespace sgl::image;

//////////////////////////////////////////////////////////////

Frame::Frame( const int& _id, const int& w, const int& h, ImageResource* _bitmap ) :
	id( _id ), width(w), height(h), bitmap( _bitmap ) {}

//////////////////////////////////////////////////////////////

Frame::~Frame() {
	delete bitmap;
}

//////////////////////////////////////////////////////////////
