#pragma once

#include "surface.h"
#include "image_resource.h" 
#include "collision_rect.h"

#include <map>
#include <vector>

namespace sgl {
namespace image {

/**
 * @file ImageResource.h
 * @author Michell Stuttgart
 * @date 01/16/14
 * @class ImageResource
 * @brief
 */
class Image : public Surface {

private:

	ImageResource* ptr_rsc;
	ALLEGRO_BITMAP* bitmapAux;
	CollisionRect cRect;

public:

	/**
	 * @brief 
	 * @param fileName
	 */
	Image( const char* fileName );
	
	/**
	 * @brief 
	 * @param resource
	 */
	Image( ImageResource* resource );

	/**
	* @brief
	*/
	virtual ~Image();

	/**
	 * @brief
	 */
	ALLEGRO_BITMAP* getAllegroBitmap();


	/**
	 * @brief
	 * @return
	 */
	virtual int getWidth();


	/**
	 * @brief
	 * @return
	 */
	virtual int getHeight();


	/**
	 * @brief
	 */
	virtual void draw();
	
	/**
	 * @brief 
	 * @return 
	 */
	inline const CollisionRect& getCollisionRect() const;


};

}
} /* namespaces */


