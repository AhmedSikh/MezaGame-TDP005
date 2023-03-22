#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include<SFML/Graphics.hpp>
#include "entity.h"

/**
 * Defines the player.
 */

class Player : public Entity
{
public:
    /**
     * The constructor does not take any parameters.
     */
    Player();

    /**
     * Takes the input from game and initializes movement. 
     */
    void input(int,sf::Time);
    /**
     * Checks if player can move in said direction and then execute.
     */
    void move(sf::Time);
    /**
     * Players update does not do anything.
     */
    void update(Player &object, sf::Time time){}
    /**
     * Checks if player collides with wall and change direction.
     */
    void collision_with_wall();
    /**
     * Changes the points variable.
     */
    void set_points(int new_points);
    /**
     * Retrieves the amount of points the player has.
     */
    int get_points() const;
    /**
     * Changes the lives variable.
     */
    void set_lives(int new_lives);
    /**
     *  Retrieves the amount of lives the player has.
     */
    int get_lives() const;
    /**
     * Changes the speed variable.
     */
    void set_speed(float);
    /**
     * Changes players coordinates when initialized in world.
     */
    void change_coordinates(float, float);
    
private:
    /**
     * Private variable that contains the players points
     */
    int points{};
    /**
     * Private variable that contains the players lives.
     */
    int lives{};
    /**
     * Private variable that decides the players speed. 
     */
    float speed{};
    /**
     * Private variable that shows if tha player can move up.
     */
    bool canMoveUp = true;
    /**
     * Private variable that shows if tha player can move down.
     */
    bool canMoveDown = true;
    /**
     * Private variable that shows if tha player can move left.
     */
    bool canMoveLeft = true;
    /**
     * Private variable that shows if tha player can move right.
     */
    bool canMoveRight = true;

};

#endif
