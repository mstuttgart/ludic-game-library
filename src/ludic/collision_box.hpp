/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is a FREE SOFTWARE released under the BSD License.              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "vector2_d.hpp"

namespace Ludic
{

#define VERTEX_I    0
#define VERTEX_F    1

/**
 * @file collisionBox.hpp
 * @author Michell Stuttgart
 * @date 02/20/14
 * @class CollisionBox
 * @brief Class used for collision checking by rectangles.
 *
 * Prove own methods of collision checking and positioning.
 * The Sprite, and AnimatedSprite StaticSprite class have
 * supports collision detection provided by CollisionBox class.
 */
class CollisionBox
{

private:

    Vector2D positions[2];
    float w, h;

public:

    /**
     * @brief Default Constructor. The initial dimension of box will be 0x0
     */
    CollisionBox();

    /**
     * @brief Parameter Constructor
     * @param position Vector2D object indicating the coordinates x, y CollisionBox on screen.
     * @param w The width of CollisionBox.
     * @param h The height of CollisionBox.
     */
    CollisionBox( const Vector2D &position, float _w, float _h );

    /**
     * @brief Default Destructor.
     */
    ~CollisionBox();

    /**
     * @brief Set the position of CollisionBox on screen.
     * @param position The Vector2D object initialized with desired coordinates.
     */
    void setPosition( const Vector2D &position );

    /**
    * @brief Set the dimension of CollisionBox.
    * @param w The new width of CollisionBox.
    * @param h The new height of CollisionBox.
    */
    void setDimension( float w, float h );

    /**
     * @brief performs a shift in the CollisionBox.
     * @param Vector2D represents the shift.
     */
    void move( const Vector2D &vec );

    /**
     * @brief Get the width of CollisionBox.
     * @return The width of CollisionBox.
     */
    int getWidth() const;

    /**
     * @brief Get the height of CollisionBox.
     * @return The height of ColissionBox.
     */
    int getHeight() const;


    /**
     * @brief Get the position of left-up corner of CollisionBox.
     * @return The Vector2D object containing the coordinates of left-up corner of CollisioBox.
     */
    const Vector2D &getPosition_i() const;

    /**
     * @brief Get the position of right-down corner of CollisionBox.
     * @return The Vector2D object containing the coordinates of right-down corner of CollisioBox.
     */
    const Vector2D &getPosition_f() const;

    /**
     * @brief Check the collision of other CollisionBox object.
     * Verify directly a collision between two CollisionBox.
     * @param r The reference a CollisionBox object that will be checked.
     * @return True id the collision occurred. False, otherwise.
     */
    bool checkCollision(const CollisionBox &r) const;

    /**
     * @brief Check the collision of other rectangle.
     *
     * @param x The x coordinate of rectangle.
     * @param y The y coordinate of rectangle.
     * @param w The width of rectangle.
     * @param h The height of rectangle.
     * @return True if the collision curred. False, otherwise.
     */
    bool checkCollision( int x, int y, int w, int h ) const;

};

} /* namespace */
