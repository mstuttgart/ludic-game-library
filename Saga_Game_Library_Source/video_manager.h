#pragma once

#include "sgl.h"
#include "vector2_d.h"
#include "color.h"

#include <memory>

namespace sgl {

/**
 * @enum DISPLAY_MODE
 * @brief Represents the operating modes of the display.
 *
 */
enum class Display_Mode : std::uint8_t {
    WINDOWED   = ALLEGRO_WINDOWED, /**< The display will be set up in windowed mode. */
    FULLSCREEN = ALLEGRO_FULLSCREEN /**< The display will be set up in fullscreen mode. */
};

/**
 * @file VideoManager.h
 * @author Michell Stuttgart
 * @date 01/07/14
 * @class VideoManager
 * @brief Class responsible for managing all the resources of video SGL.
 *
 * Class responsible for managing all the resources of video SGL. The class
 * is a singleton, ie, allows only a single instance of itself. Through it,
 * you have access to all relevant routines (screen refresh, positioning,
 * and other routine events) for managing video SGL.
 */
class VideoManager {

private:

	static std::unique_ptr<VideoManager> ms_instance;
	ALLEGRO_DISPLAY* display;
	Color backGroundColor;

private:

	/**
	 * @brief Default Constructor
	 *
	 */
	VideoManager( ALLEGRO_DISPLAY* _display );

public:

	/**
	 * @brief Default Destructor
	 *
	 * */
	virtual ~VideoManager();


	/**
	 * @brief Return one instance of VideoManager.
	 *
	 * Allows a detailed configuration of the display being used. Once this
	 * method has been called, a subsequent call it will do nothing.
	 * if @see mode is omitted when calling the function, a screen with the
	 * specified dimensions be created using window mode @see WINDOWED.
	 *
	 * @param width the width of window.
	 * @param height the height of window.
	 * @param mode the mode of window.
	 * @return the instance of VideoManager.
	 * @see getVideoManager
	 */
	static VideoManager* createVideoManager( unsigned int width,
	        unsigned int height, Display_Mode mode = Display_Mode::WINDOWED );


	/**
	 * @brief Return one instance of VideoManager.
	 *
	 * If @see createVideoManager method has not been called, this method
	 * returns an instance with default values​​, ie, a window with the
	 * dimensions 640 x 480 and the @see DISPLAY_MODE DISPLAY_MODE.
	 * If @see createVideoManager method is called after this method,
	 * nothing will happen. If you want a display with own startup
	 * configuration, use the @see createVideoManager method.
	 *
	 * @return the instance of VideoManager.
	 * @see createVideoManager
	 */
	static VideoManager* Instance();


	/**
	 * @brief Defining the new position of the window
	 * @param pos_x the new position x of window.
	 * @param pos_y the new position y of window.
	 */
	void setWindowPosition( int pos_x, int pos_y );


	/**
	 * @brief Sets the window title.
	 * @param title the title of window.
	 */
	void setWindowTitle( const String& title );


	/**
	 * @brief Sets the window icon.
	 *
	 * Work with .PNG, .JPG and outhers format image supported
	 * for Allegro lib.
	 *
	 * @param the path of image file.
	 */
	void setWindowIcon( const String& fileName );


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
	 * @see setWindowPosition
	 */
	Vector2D getWindowPosition();


	/**
	 * @brief Returns the width of the display.
	 * @return Returns the width of the display.
	 * @see setWindowDimension
	 */
	int getDisplayWidth() const;


	/**
	 * @brief Returns the height of the display.
	 * @return Returns the height of the display.
	 * @see setWindowDimension
	 */
	int getDisplayHeight() const;


	/**
	 * @brief
	 */
	operator ALLEGRO_DISPLAY*();


	/**
	 * @brief Refreshes the screen entirely.
	 *
	 * Uses the color set in setBackgroundColor as background.
	 * @see refreshScreenRegion
	 */
	void refreshScreen();

	/**
	 * @brief Used to update a screen area determined by the rectangle of
	 * dimensions (width, height) that is positioned at the point (x, y).
	 * @param xy
	 * @param width width The width of the rectangular area.
	 * @param height height The height of the rectangular area.
	 * @see refreshScreen
	 */
	void refreshScreenRegion( const Vector2D& xy, int width, int height );


	/**
	 * @brief Disable screen saver during the use of SGL.
	 * @param disable true if you want to disable the screensaver,
	 * false otherwise. The default value is false
	 */
	void disableScreenSaver( bool disable );

	/**
	 * @brief Return the number of resolutions supported by the monitor.
	 * @return the number of resolutions supported by the monitor
	 * @see getResolution
	 */
	static int getNumDisplayResolutions();


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

	/**
	 * @brief Destroy the VideoManager and you atributs.
	 */
	static void destroy();

};

}//namespace
