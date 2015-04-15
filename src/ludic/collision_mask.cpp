#include "collision_mask.hpp"
#include <cmath>

using namespace sgl::image;

//////////////////////////////////////////////////////////////////

CollisionMask::CollisionMask() : width(0), heigth(0) {
}

//////////////////////////////////////////////////////////////////

CollisionMask::CollisionMask( ImageResource* imgResource ) {
	
	initMask( imgResource );
}

//////////////////////////////////////////////////////////////////

CollisionMask::~CollisionMask() {
}

//////////////////////////////////////////////////////////////////

void CollisionMask::initMask( ImageResource* imgResource)
{
	
	width  = al_get_bitmap_width( *imgResource );
	heigth = al_get_bitmap_height( *imgResource );

	ALLEGRO_COLOR pixel;
	bits.reserve( width * heigth );

	for( int i = 0; i < width; i++ ) {

		for( int j = 0; j < heigth; j++ ) {
			
			pixel = al_get_pixel( *imgResource, i, j );
			
			bits[ i * width + j] = ( pixel.a == 0 ) ? true : false;
		}

	}
}

//////////////////////////////////////////////////////////////////

bool CollisionMask::collisionVerify( const CollisionMask& mask, 
												int xoffset, int yoffset) {
													
	int xover = ( width  + mask.width  ) * 0.5 - std::abs(xoffset);
	int yover = ( heigth + mask.heigth ) * 0.5 - std::abs(yoffset);
	
	if ( xover <= 0 || yover <= 0) 
		return false;
		
	int x1 = ( width  - xover )      * ( ( xoffset < 0 ) ? 1 : 0 );
	int y1 = ( heigth - yover )      * ( ( yoffset < 0 ) ? 1 : 0 );
	int x2 = ( mask.width  - xover ) * ( ( xoffset < 0 ) ? 0 : 1 );
	int y2 = ( mask.heigth - yover ) * ( ( yoffset < 0 ) ? 0 : 1 );
	
	for( int i = 0; i < xover; i++ ) {

		for( int j = 0; j < yover; j++ ) {
			
			if( bits[( x1 + i ) * width + y1 + j] && 
								mask.bits[( x2 + i ) * mask.width + y2 + j] )
			{
				return true;
			}
			
		}//for j

	}//for i
	
	return false;
}

//////////////////////////////////////////////////////////////////

