#pragma once

#include "sgl.hpp"
#include "display_listener.hpp"

namespace sgl
{

/**
 * @file scene.h
 * @author Michell Stuttgart
 * @date 04/03/14
 * @class Scene
 * @brief
 */
class Scene : public sgl::event::DisplayListener
{

private:

    bool exitLoop;

public:

    /**
     * @brief
     */
    Scene();

    /**
     * @brief
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
