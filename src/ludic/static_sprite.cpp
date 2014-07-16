#include "static_sprite.hpp"
#include "resource_manager.hpp"

using namespace Ludic;
using namespace std;

//////////////////////////////////////////////////////////////

StaticSprite::StaticSprite() : imgRsc( nullptr ), bitmapAux( nullptr ) {}

//////////////////////////////////////////////////////////////

StaticSprite::StaticSprite( const String &fileName ) : imgRsc( nullptr ), bitmapAux( nullptr )
{

	// Carregamos o sprite
	if ( !load( fileName ) )
		throw Ludic::Exception( "Error in load file " + fileName );

}

//////////////////////////////////////////////////////////////

bool StaticSprite::load( const String &fileName )
{

	try {
		// Criamos o resource
		imgRsc = ImageResource::loadImageResource( fileName );
	} catch ( Ludic::Exception &ex ) {
		std::cout << ex.what() << std::endl;
		return false;
	}

	// Setamos o bitmap. Isso e feito apenas por questoes de desempenho
	// para que nao tenhamos que chamar getBitmap() durante o draw()
	bitmapAux = *imgRsc;

	// Ajustamos a dimesao do retangulo de colisao
	collisionBox.setPosition( Vector2D( getX(), getY() ) );
	collisionBox.setDimension( getWidth(), getHeight() );

	// Inciamos a mascara de bits para colisao por pixel
	mask.initMask( imgRsc );

	return true;
}

//////////////////////////////////////////////////////////////

float StaticSprite::getHeight() const
{
	return al_get_bitmap_height( bitmapAux );
}

//////////////////////////////////////////////////////////////

float StaticSprite::getWidth() const
{
	return al_get_bitmap_width( bitmapAux );
}

//////////////////////////////////////////////////////////////

void StaticSprite::draw()
{

	if ( isVisible() )
		al_draw_bitmap( bitmapAux, getX(), getY(), getFlip() );

	/*al_draw_scaled_rotated_bitmap( bitmapAux, getRefX(), getRefY(),
	getX(), getY(), getScaleX(), getScaleY(), getAngle(), getFlip

	*/

	//mask.draw( getX(), getY() );

	al_draw_rectangle( getX(), getY(), getX()+ getWidth(), getY()+getHeight(), al_map_rgb(255, 0, 255), 1.0 );
}

//////////////////////////////////////////////////////////////

const ImageResource *StaticSprite::getImageResource() const
{
	return imgRsc;
}

//////////////////////////////////////////////////////////////

const CollisionMask& StaticSprite::getMask() const
{
	return mask;
}

//////////////////////////////////////////////////////////////
