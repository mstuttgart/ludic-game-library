#pragma once

#include "sgl.h"

namespace sgl {

/**
 * @file scene.h
 * @author Michell Stuttgart
 * @date 04/03/14
 * @class Scene
 * @brief
 */
class Scene {

private:

	bool exitLoop;

public:

	/**
	 * @brief 
	 */
	Scene();
	
	/**
	 * @brief 
	 * @return 
	 */
	virtual ~Scene();

	/**
	 * @brief 
	 */
	virtual void initialize() = 0;

	/**
	 * @brief 
	 */
	virtual void logic() = 0;

	/**
	 * @brief 
	 */
	virtual void render() = 0;

	/**
	 * @brief 
	 */
	virtual void finalize() = 0;

	/**
	 * @brief 
	 * @param exitLoop
	 */
	void setExitLoop(bool exitLoop);
	
	/**
	 * @brief 
	 * @return 
	 */
	bool isExitLoop() const;

};

} /* namespace */
