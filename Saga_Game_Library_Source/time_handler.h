#pragma once

#include "sgl.h"

namespace sgl {

/**
 * @file time_handler.h
 * @author Michell Stuttgart
 * @date 03/27/14 
 * @class TimeHandler
 * @brief 
 */
class TimeHandler {

private:

	double startTicks;
	double pausedTicks;
	bool started;
	bool paused;

public:

	/**
	 * @brief 
	 */
	TimeHandler();

	/**
	 * @brief 
	 */
	virtual ~TimeHandler(){};

	/**
	 * @brief 
	 */
	void start();

	/**
	 * @brief 
	 */
	void stop();

	/**
	 * @brief 
	 */
	void pause();

	/**
	 * @brief 
	 */
	void resume();

	/**
	 * @brief 
	 * @return 
	 */
	double getTicks() const;

	/**
	 * @brief 
	 * @return 
	 */
	bool isStarted() const;

	/**
	 * @brief 
	 * @return 
	 */
	bool isPaused() const;
	
	/**
	 * @brief 
	 * @param seconds
	 */
	static void sleep( double seconds );

};

} /* namespace */
