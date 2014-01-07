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
    DISPLAY_CLOSE = ALLEGRO_EVENT_DISPLAY_CLOSE,
    DISPLAY_SWITCH_OUT = ALLEGRO_EVENT_DISPLAY_SWITCH_OUT,
    DISPLAY_SWITCH_IN = ALLEGRO_EVENT_DISPLAY_SWITCH_IN
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
class VideoManager : public AllegroAddON {

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
	 * @brief 
	 * @param dWidth
	 * @param dHeight
	 * @param dMode
	 * @return 
	 */
	static VideoManager* createVideoManager ( unsigned int dWidth,
	        unsigned int dHeight, DISPLAY_MODE dMode = DISPLAY_MODE::WINDOWED );

	/**
	 * @brief 
	 * @return 
	 */
	static VideoManager* getVideoManager();

	/**
	 * @brief 
	 * @param pos_x
	 * @param pos_y
	 */
	void setWindowPosition ( int pos_x, int pos_y );

	/**
	 * @brief 
	 * @param w
	 * @param h
	 */
	void setWindowDimension ( unsigned int w, unsigned int h );

	/**
	 * @brief 
	 * @param title
	 */
	void setWindowTitle ( const char* title );

	/**
	 * @brief 
	 */
	void setWindowIcon();

	/**
	 * @brief 
	 * @param fit
	 */
	void setFitToScreen ( bool fit );

	/**
	 * @brief 
	 * @param r
	 * @param g
	 * @param b
	 */
	void setBackgroundColor ( unsigned char r, unsigned char g, unsigned char b );

	/**
	 * @brief 
	 */
	void setDisplayEventQueue();

	/**
	 * @brief 
	 * @param pos_x
	 * @param pos_y
	 */
	void getWindowPosition ( int* pos_x, int* pos_y );

	/**
	 * @brief 
	 * @return 
	 */
	int getDisplayWidth() const;

	/**
	 * @brief 
	 * @return 
	 */
	int getDisplayHeight() const;

	/**
	 * @brief 
	 * @return 
	 */
	ALLEGRO_DISPLAY* getDisplay() const;

	/**
	 * @brief Refreshes the screen entirely. 
	 * 
	 * Uses the color set in setBackgroundColor as background.
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
	 */
	void updateScreenRegion( int x, int y, int width, int height );

	/**
	 * @brief Disable screen saver during the use of SGL.
	 * @param disable true if you want to disable the screensaver, 
	 * false otherwise. The default value is false
	 */
	void disableScreenSaver ( bool disable );

	/**
	 * @brief Used to check if the display has launched a specific event. 
	 * @param event The event type DISPLAY_EVENT you want to verify the occurrence.
	 * @return true if the event occurred, false otherwise
	 */
	bool getDisplayStatus( DISPLAY_EVENT event );

};

}
