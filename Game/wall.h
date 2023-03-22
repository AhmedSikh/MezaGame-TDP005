#ifndef WALL_H
#define WALL_H
#include<SFML/Graphics.hpp>
#include "object.h"

/**
 * Defines the walls in the game
 */

class Wall : public Object
{
public:
    /**
     * Constructor that takes 4 floats that represent the size and placement of the wall.  
     */
    Wall(float,float,float,float);
    /**
     * Destructor set to default.
     */
    ~Wall() = default;

    /**
     * Walls update does not do anything.
     */
    void update(Player &object, sf::Time time){}

};
#endif
