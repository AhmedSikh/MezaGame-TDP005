#ifndef ENTITY_H
#define ENTITY_H
#include "object.h"
#include<SFML/Graphics.hpp>

/**
 * Defines the entities in the game.
 */

class Entity : public Object
{
public:
    /**
     * Constructor that takes 4 floats as parameter that represent the size and placement of the entity. The constructor also takes the texture that the sprite will be set to.
     */
    Entity(std::string text, float w, float h, float x, float y);
    /**
     * Default destructor.
     */
    ~Entity() = default;
    /**
     * Defines how the entities move in the game.
     */
    virtual void move(sf::Time) = 0;
    /**
     * Defines how the object and player will be updated in the game loop.
     */
    virtual void update(Player &object, sf::Time time) = 0;
    
protected:
    /**
     * Private variable that contains an integer that represent the direction that the entity is moving.
     */
    int move_direction{};
    /**
     * Private varaiable that is used to check how the entity should moves.
     */
    sf::Time movement{};
};

#endif
