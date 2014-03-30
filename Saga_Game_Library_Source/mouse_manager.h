#pragma once
#include "sgl.h"
#include "video_manager.h"
#include "image_resource.h"
#include "point.h"

typedef sgl::image::ImageResource ImageResource;
typedef sgl::VideoManager VideoManager;
typedef sgl::Point Point;

namespace sgl {
namespace input {

enum class SystemCursor : std::uint8_t {
	
    CURSOR_DEFAULT = ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT,
    CURSOR_ARROW   = ALLEGRO_SYSTEM_MOUSE_CURSOR_ARROW,
    CURSOR_BUSY    = ALLEGRO_SYSTEM_MOUSE_CURSOR_BUSY,
    CURSOR_QUESTIO = ALLEGRO_SYSTEM_MOUSE_CURSOR_QUESTION,
    CURSOR_EDIT    = ALLEGRO_SYSTEM_MOUSE_CURSOR_EDIT,
    CURSOR_MOVE    = ALLEGRO_SYSTEM_MOUSE_CURSOR_MOVE,
	
    CURSOR_RESIZE_N  = ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_N,
    CURSOR_RESIZE_W  = ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_W,
    CURSOR_RESIZE_S  = ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_S,
    CURSOR_RESIZE_E  = ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_E,
    CURSOR_RESIZE_NW = ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_NW,
    CURSOR_RESIZE_SW = ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_SW,
    CURSOR_RESIZE_SE = ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_SE,
    CURSOR_RESIZE_NE = ALLEGRO_SYSTEM_MOUSE_CURSOR_RESIZE_NE,
	
    CURSOR_PROGRESS    = ALLEGRO_SYSTEM_MOUSE_CURSOR_PROGRESS,
    CURSOR_PRECISION   = ALLEGRO_SYSTEM_MOUSE_CURSOR_PRECISION,
    CURSOR_LINK        = ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK,
    CURSOR_ALT_SELECT  = ALLEGRO_SYSTEM_MOUSE_CURSOR_ALT_SELECT,
    CURSOR_UNAVAILABLE = ALLEGRO_SYSTEM_MOUSE_CURSOR_UNAVAILABLE
};

/**
 * @file mouse_manager.h
 * @author Michell Stuttgart
 * @date 03/23/14
 * @class MouseManager
 * @brief
 */
class MouseManager {

private:

	static MouseManager* instance;
	VideoManager* display;
	ALLEGRO_MOUSE_CURSOR* cursor;
	
	bool visible;
	Point currentPoint;
	Point lastPoint;

	ALLEGRO_MOUSE_STATE last_state;
	ALLEGRO_MOUSE_STATE current_state;

private:

	/**
	 * @brief
	 */
	MouseManager( VideoManager* _videoManager );

	/**
	 * @brief
	 */
	virtual ~MouseManager();

public:

	/**
	 * @brief
	 * @return
	 */
	static MouseManager* Instance( VideoManager* _videoManager );

	/**
	 * @brief
	 */
	static void release();


	/**
	 * @brief
	 */
	void update();


	/**
	 * @brief 
	 * @param button
	 * @return 
	 */
	bool buttonDown( int button );

	/**
	 * @brief 
	 * @param button
	 * @return 
	 */
	bool buttonPressed( int button );

	/**
	 * @brief 
	 * @param button
	 * @return 
	 */
	bool buttonRelease( int button );

	/**
	 * @brief 
	 * @param x
	 * @param y
	 * @return 
	 */
	bool setMousePosition( int x, int y );

	/**
	 * @brief 
	 * @param bitmap
	 * @return 
	 */
	bool setMouseCursor( ImageResource* bitmap );

	/**
	 * @brief 
	 * @param cursor
	 * @return 
	 */
	bool setSystemMouseCursor( SystemCursor cursor );
	
	/**
	 * @brief 
	 * @param visible
	 */
	void setCursorVisible( bool visible );
	
	/**
	 * @brief 
	 * @return 
	 */
	const Point& getPosition();
	
	/**
	 * @brief 
	 * @param dx
	 * @param dy
	 */
	void getWarp( int* dx, int* dy );

	/**
	 * @brief 
	 * @return 
	 */
	unsigned int getAxesSize() const;

	/**
	 * @brief 
	 * @return 
	 */
	unsigned int getButtonSize() const;

	/**
	 * @brief 
	 * @return 
	 */
	bool isVisible() const;

};

}
} /* namespace */
