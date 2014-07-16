#include "collision_mask.hpp"
#include <cmath>

using namespace Ludic;

//////////////////////////////////////////////////////////////////

CollisionMask::CollisionMask() : width(0), heigth(0)
{
}

//////////////////////////////////////////////////////////////////

CollisionMask::CollisionMask( ImageResource *imgResource )
{
    initMask( imgResource );
}

//////////////////////////////////////////////////////////////////

CollisionMask::~CollisionMask()
{
}

//////////////////////////////////////////////////////////////////

void CollisionMask::initMask( ImageResource *imgResource )
{

    width  = al_get_bitmap_width( *imgResource );
    heigth = al_get_bitmap_height( *imgResource );

    ALLEGRO_COLOR pixel;
	ALLEGRO_COLOR transColor = al_map_rgb(255, 0, 255);
	
    bits.reserve( width * heigth );

	al_lock_bitmap(*imgResource, ALLEGRO_PIXEL_FORMAT_ANY, ALLEGRO_LOCK_READONLY);
	
    for ( int i = 0; i < heigth; i++ )
    {
        for ( int j = 0; j < width; j++ )
        {
            pixel = al_get_pixel( *imgResource, j, i );
			
			if( !isColorEqual(pixel, transColor) && !isTransparent(pixel))
			{
				//bits.push_back(true);
				bits[ j + i * width ] = true;
			}
			else{
				//bits.push_back(false);
				bits[ j + i * width ] = false;
			}
							
        }//for j
		
    }//for i
	
	al_unlock_bitmap(*imgResource);
	
}

//////////////////////////////////////////////////////////////////

bool CollisionMask::collisionVerify( const CollisionMask &mask, int xoffset, int yoffset) const
{

    int xover = ( width  + mask.width  ) * 0.5 - std::abs(xoffset);
    int yover = ( heigth + mask.heigth ) * 0.5 - std::abs(yoffset);

    if ( xover < 0 || yover < 0 )
        return false;
		
	int x1;// = std::abs( width  - xover )      * ( ( xoffset < 0 ) ? 1 : 0 );
    int y1;// = std::abs( heigth - yover )      * ( ( yoffset < 0 ) ? 1 : 0 );
    int x2;// = std::abs( mask.width  - xover ) * ( ( xoffset < 0 ) ? 0 : 1 );
    int y2;// = std::abs( mask.heigth - yover ) * ( ( yoffset < 0 ) ? 0 : 1 );
	
	if( xoffset < 0 )
	{
		x1 = std::abs( width - xover );
		x2 = 0;
	}
	else{
		x1 = 0;
		x2 = std::abs( mask.width - xover );
	}
	
	if( yoffset < 0 )
	{
		y1 = std::abs( heigth - yover );
		y2 = 0;
	}
	else{
		y1 = 0;
		y2 = std::abs( mask.heigth - yover );
	}
	
	int idx1;
	int idx2;

    for ( int i = 0; i < xover; i++ )
    {
		idx1 = ( x1 + i );
		idx2 = ( x2 + i );
		
        for ( int j = 0; j < yover; j++ )
        {
	
            if ( bits[ idx1 + width * ( j + y1 )] && mask.bits[ idx2 + mask.width * ( j + y2 )] )
            {
                return true;
            }

        }//for j

    }//for i

    return false;
}

//////////////////////////////////////////////////////////////////

bool CollisionMask::isColorEqual(ALLEGRO_COLOR col1, ALLEGRO_COLOR col2)
{
	return col1.r == col2.r && col1.g == col2.g && col1.b == col2.b && col1.a == col2.a;
}

//////////////////////////////////////////////////////////////////

bool CollisionMask::isTransparent(ALLEGRO_COLOR col1)
{
	return col1.a == 0;
}

//////////////////////////////////////////////////////////////////