#pragma once

#include "AllegroAddON.h" // Base class: sgl::AllegroAddON

namespace sgl {

/**
 * @enum DISPLAY_MODE
 * @brief Represents the operating modes of the display.
 *
 */
enum class DISPLAY_MODE {
    WINDOWED = ALLEGRO_WINDOWED, /**< The display will be set up in windowed mode. */
    FULLSCREEN = ALLEGRO_FULLSCREEN /**< The display will be set up in fullscreen mode. */
};

/**
 * @enum DISPLAY_EVENT
 * @brief Represents the event that the display can generate.
 * */
enum class DISPLAY_EVENT {
    DISPLAY_CLOSE = ALLEGRO_EVENT_DISPLAY_CLOSE, /**< Display close event */
    //DISPLAY_SWITCH_OUT = ALLEGRO_EVENT_DISPLAY_SWITCH_OUT, /**< Display lose focus event */
    //DISPLAY_SWITCH_IN = ALLEGRO_EVENT_DISPLAY_SWITCH_IN /**< Display get focus event */
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
class VideoManager: public AllegroAddON {

private:

	static VideoManager* instance;
	static ALLEGRO_DISPLAY* display;
	static ALLEGRO_COLOR backGroundColor;
	static ALLEGRO_EVENT_QUEUE* eventQueue;

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
	 * @see
	 */
	static VideoManager* createVideoManager( unsigned int width,
	        unsigned int height, DISPLAY_MODE mode = DISPLAY_MODE::WINDOWED );
			

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
	static VideoManager* getVideoManager();
	

	/**
	 * @brief Defining the new position of the window
	 * @param pos_x the new position x of window.
	 * @param pos_y the new position y of window.
	 */
	void setWindowPosition( int pos_x, int pos_y );
	

	/**
	 * @brief Define the window dimensions.
	 * @param w the new window width
	 * @param h the new window height
	 */
	void setWindowDimension( unsigned int w, unsigned int h );
	

	/**
	 * @brief Sets the window title.
	 * @param title the title of window.
	 */
	void setWindowTitle( const char* title );
	

	/**
	 * @brief Sets the window icon. 
	 * 
	 * Work with .PNG, .JPG and outhers format image supported 
	 * for Allegro lib.
	 * 
	 * @param the path of image file.
	 */
	void setWindowIcon( const char* fileName );
	

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
	 * @param r the value of the green component. Valid values ​​are from 0 to 255.
	 * @param g the value of the red component. Valid values ​​are from 0 to 255
	 * @param b the value of the blue component. Valid values ​​are from 0 to 255
	 */
	void setBackgroundColor( unsigned char r, unsigned char g, unsigned char b );
	

	/**
	 * @brief Returns the position of the window relative to monitor. 
	 * 
	 * The point (0,0) is the upper left corner of the monitor.
	 * 
	 * @param pos_x the x coordenate of window position.
	 * @param pos_y the y coordenate of window position.
	 * @see setWindowPosition
	 */
	void getWindowPosition( int& pos_x, int& pos_y );
	

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
	 * @brief Returns a pointer to ALLEGRO_DISPLAY used by VideoManager
	 * @return Returns a pointer of ALLEGRO DISPLAY.
	 */
	ALLEGRO_DISPLAY* getDisplay() const;
	

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
	 * @param x The x coordinate of the left edge of the rectangular area.
	 * This position is given relative to the upper left corner of the display.
	 * @param y The y coordinate of the top edge of the rectangular area.
	 * This position is given relative to the upper left corner of the display.
	 * @param width The width of the rectangular area.
	 * @param height The height of the rectangular area.
	 * @see refreshScreen
	 */
	void refreshScreenRegion( int x, int y, int width, int height );
	

	/**
	 * @brief Disable screen saver during the use of SGL.
	 * @param disable true if you want to disable the screensaver,
	 * false otherwise. The default value is false
	 */
	void disableScreenSaver( bool disable );
	

	/**
	 * @brief Used to check if the display has launched a specific event.
	 * @param event The event type DISPLAY_EVENT you want to verify the occurrence.
	 * @return true if the event occurred, false otherwise
	 */
	bool getDisplayEvent( DISPLAY_EVENT event );
	

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

};

}//namespace
