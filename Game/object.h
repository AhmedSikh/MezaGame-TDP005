#ifndef OBJECT_H
#define OBJECT_H
#include<SFML/Graphics.hpp>

class Player;

class World;

/*
 * Defines our objects
 */
class Object
{
 public:
    /**
     * Constructor that takes texture, the scale and position as parameters for the objects sprite.  
     */
    Object(std::string text, float w, float h, float x, float y);
    /**
     * Default destructor.  
     */
    virtual ~Object() = default;

    /**
     * Draws the saved sprite to a RenderWindow.
     */
    void draw(sf::RenderWindow &window) const;
    /**
     * Defines how the player will be updated in the game loop.
     */
    virtual void update(Player &object, sf::Time time) = 0;
    /**
     * Defines when tow objects have collided with eachother.
     */
    virtual bool collision(Object const& other) const;
    
    /**
     * Returns the saved sprite.
     */
    sf::Sprite getsprite() const;

 protected:
    /**
     * Private variable that holdes the sprite that represents the object.
     */
    sf::Sprite sprite;

    /**
     * Private variable that contains the texter that the sprite has.
     */
    sf::Texture texture;
    
};

#endif
