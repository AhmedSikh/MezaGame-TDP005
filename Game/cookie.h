#ifndef CARROT_H
#define CARROT_H
#include <iostream>
#include<SFML/Graphics.hpp>
#include "object.h"
/**
 * Defines the cookies
 */

class Cookie : public Object
{
public:
    /**
     * Constructor that takes the texture, coordinates and the  amount of points the cookie will give to the player.
     */
    Cookie(std::string, float x, float y, int points);
    /**
     * Destructor set to default.
     */
    ~Cookie() = default;
    /**
     * Updates the player in the game loop when it has collided with a cookie.
     */
    void update(Player &object, sf::Time time);
    
private:
    /**
     * Private variable that contains the amount of points that the cookie will give to the player.
     */
    int points{};


};

/**
 * Defines the BadCookie.
 */

class BadCookie : public Cookie
{
public:
    /**
     * Constructor that takes coordinates as parameters.
     */
    BadCookie(float x, float y);
  
    
};
/**
 * Defines the GoodCookie.
 */
class GoodCookie : public Cookie
{
public:
    /**
     *  Constructor that takes coordinates as parameters.
     */
    GoodCookie(float x, float y);
};

#endif
