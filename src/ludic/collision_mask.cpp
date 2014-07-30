#include "collision_mask.hpp"
#include <cmath>

using namespace Ludic;

//////////////////////////////////////////////////////////////////

CollisionMask::CollisionMask() : width(0), height(0) {}

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

    // Pegamos as dimensoes da imagem que sera a base
    // para a mascara de bits
    width  = al_get_bitmap_width( *imgResource );
    height = al_get_bitmap_height( *imgResource );

    // Cor que recebera os pixel da imagem base
    ALLEGRO_COLOR pixel;

    //  Cor transparente usada como referencia
    ALLEGRO_COLOR transColor = al_map_rgb(255, 0, 255);

    // Criamos uma matriz reservando a dimensao da imagem 
    bits.reserve( width * height );

    // Travamos o bitmap para que possamos analisar seus pixel de maneira otimizada
    al_lock_bitmap(*imgResource, ALLEGRO_PIXEL_FORMAT_ANY, ALLEGRO_LOCK_READONLY);

    // Criamos o mapa de bits da imagem base
    for ( int i = 0; i < height; i++ )
    {
        for ( int j = 0; j < width; j++ )
        {
        	// Pegamos um pixel da imagem base
            pixel = al_get_pixel( *imgResource, j, i );

            // Verificamos se o pixel e ou nao transparente.
            if ( !isColorEqual(pixel, transColor) && pixel.a != 0 )
            {
                bits[ j + i * width ] = true;
            }
            else
            {
                bits[ j + i * width ] = false;
            }

        }//for j

    }//for i

    // Destrancamos os pixels da imagem
    al_unlock_bitmap(*imgResource);

}

//////////////////////////////////////////////////////////////////

bool CollisionMask::collisionVerify( const CollisionMask &mask, int xoffset, int yoffset) const
{

	// Inicialmente verificamos se as imagens esta sobrepostas
    int xover = ( width  + mask.width  ) * 0.5 - std::abs(xoffset);
    int yover = ( height + mask.height ) * 0.5 - std::abs(yoffset);

    if ( xover < 0 || yover < 0 )
        return false;

    if ( xoffset < 0 )
    {
        x1 = std::abs( width - xover );
        x2 = 0;
    }
    else
    {
        x1 = 0;
        x2 = std::abs( mask.width - xover );
    }

    if ( yoffset < 0 )
    {
        y1 = std::abs( height - yover );
        y2 = 0;
    }
    else
    {
        y1 = 0;
        y2 = std::abs( mask.height - yover );
    }

    for ( int i = 0; i < xover; i++ )
    {
        int idx1 = ( x1 + i );
        int idx2 = ( x2 + i );

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

int CollisionMask::getWidth() const
{
    return width;
}

//////////////////////////////////////////////////////////////////

int CollisionMask::getHeigth() const
{
    return height;
}

//////////////////////////////////////////////////////////////////