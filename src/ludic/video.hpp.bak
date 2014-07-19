#pragma once

#include "sgl.hpp"
#include "vector2_d.hpp"
#include "color.hpp"

namespace Ludic {

/**
 * @enum DISPLAY_MODE
 * @brief Represents the operating modes of the display.
 *
 */
enum class DisplayMode : std::uint8_t {
    WINDOWED   = ALLEGRO_WINDOWED, /**< The display will be set up in windowed mode. */
    FULLSCREEN = ALLEGRO_FULLSCREEN /**< The display will be set up in fullscreen mode. */
};

/**
 * @file video.h
 * @author Michell Stuttgart
 * @date 01/07/14
 * @class Video
 * @brief Class responsible for managing all the resources of video SGL.
 *
 * Class responsible for managing all the resources of video SGL. The class
 * is a singleton, ie, allows only a single instance of itself. Through it,
 * you have access to all relevant routines (screen refresh, positioning,
 * and other routine events) for managing video SGL.
 *
 */
class Video {

private:

	ALLEGRO_DISPLAY* display;
	Color backGroundColor;

public:

	/**
	 * @brief
	 */
	Video();

	/**
	 * @brief
	 * @param width
	 * @param height
	 * @param mode
	 */
	Video( unsigned int width, unsigned int height,
	       DisplayMode mode = DisplayMode::WINDOWED );

	/**
	 * @brief Default Destructor
	 *
	 * */
	virtual ~Video();

	/**
	 * @brief Defining the new position of the window
	 * @param pos_x the new position x of window.
	 * @param pos_y the new position y of window.
	 */
	void setPosition( int pos_x, int pos_y );


	/**
	 * @brief Sets the window title.
	 * @param title the title of window.
	 */
	void setTitle( const String& title );


	/**
	 * @brief Sets the window icon.
	 *
	 * Work with .PNG, .JPG and outhers format image supported
	 * for Allegro lib.
	 *
	 * @param fileName the path of image file.
	 */
	void setIcon( const String& fileName );


	/**
	 * @brief Adjust the contents of the window to the monitor.
	 *
	 * The contents of the window remains the same size window mode and the
	 * rest of the monitor screen will be filled with the background
	 * color chosen.
	 *
	 * @param fit true if you want to enable adjustment of the screen,
	 * false if you want to disable it.
	 * @see setBackgroundColor
	 */
	void setFitToScreen( bool fit );


	/**
	 * @brief Set the background color of the display.
	 * @param color
	 */
	void setBackgroundColor( const Color& color );


	/**
	 * @brief Returns the vector2D position of the window
	 * relative to monitor.
	 *
	 * The point (0,0) is the upper left corner of the monitor.
	 * @see setPosition
	 */
	Vector2D getPosition();


	/**
	 * @brief Returns the width of the display.
	 * @return Returns the width of the display.
	 */
	int getWidth() const;


	/**
	 * @brief Returns the height of the display.
	 * @return Returns the height of the display.
	 */
	int getHeight() const;


	/**
	 * @brief
	 * @return
	 */
	operator ALLEGRO_DISPLAY*();


	/**
	 * @brief Refreshes the screen entirely.
	 *
	 * Uses the color set in setBackgroundColor as background.
	 * @see refreshScreenRegion
	 */
	void refresh();

	/**
	 * @brief Used to update a screen area determined by the rectangle of
	 * dimensions (width, height) that is positioned at the point (x, y).
	 * @param xy
	 * @param width width The width of the rectangular area.
	 * @param height height The height of the rectangular area.
	 * @see refresh
	 */
	void refreshRegion( const Vector2D& xy, int width, int height );


	/**
	 * @brief Disable screen saver during the use of SGL.
	 * @param disable true if you want to disable the screensaver,
	 * false otherwise. The default value is false
	 */
	void disableScreenSaver( bool disable );

	/**
	 * @brief
	 */
	void setAsTarger();

	/**
	 * @brief Return the number of resolutions supported by the monitor.
	 * @return the number of resolutions supported by the monitor
	 * @see getResolution
	 */
	static int sizeResolutions();


	/**
	 * @brief Returns the dimensions of a specific resolution by index.
	 *
	 * index values ​​(all positive) cover the range
	 * [0, getNumDisplayResolutions -1 ]. For each value within that range,
	 * we have a specific resolution. The higher the index value, the less will
	 * be its corresponding resolution, ie, the lowest resloução supported by
	 * the monitor, index (getNumDisplayResolutions -1) must hold.
	 * To get the maximum supported resolution, index must be worth 0.
	 *
	 * @param index Specifies the desired resolution.
	 * @param width Receives the resolution width
	 * @param height Receives the resolution height
	 * @see getNumDisplayResolutions
	 *
	 */
	static void getResolution( unsigned int index, int& width, int& height );

};

}//namespace
