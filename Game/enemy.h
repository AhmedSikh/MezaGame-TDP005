#ifndef ENEMY_H
#define ENEMY_H
#include <vector>
#include <iostream>
#include "entity.h"
#include<SFML/Graphics.hpp>

class World;

class Object;

class Player;

/**
 * Defines the games enemies.
 */

class Enemy : public Entity
{
public:
    /**
     * Constructor that takes the texture, coordinates and route of the enemy as well as how far it walks and how many lives it takes.
     */
    Enemy(std::string,float, float, int, int, int, int, float,int);
    /**
     * The enemys destructor set to default.
     */
    ~Enemy() = default;
    /**
     * Moves the enemy according to it's route.
     */
    void move(sf::Time);
    /**
     * Updates enemy and player in the game loop.
     */
    void update(Player &object,  sf::Time time);
    
 private:
    /**
     * Sets move_direction according to the route.
     */
    void enemy_route(sf::Time);
    /**
     * Private variable that contains the time an enemy walk a certain direction.
     */
    float distance{};
    /**
     * Private variable that contains the amount of lives the enemy takes from the player.
     */
    int lives_to_take{};
    /**
     * Private variable that contains the enemys route.
     */
    std::vector<int> route{};
    
};

/**
 * Defines the carrot.
 */

class Carrot : public Enemy
{
public:
    
    /**
     * Construcor that takes the carrots possition, route and distance as paramenters.
     */
    Carrot(float x, float y, int dir_1, int dir_2, int dir_3, int dir_4,float dist);
    /**
     * Destructor set to default.
     */
    ~Carrot() = default;

    
};
/**
 * Defines the chili.
 */

class Chili : public Enemy
{
public:
    
    /**
     * Construcor that takes the chilis possition, route and distance as paramenters.
     */
    Chili(float x, float y, int dir_1, int dir_2, int dir_3, int dir_4,float dist);
    /**
     * Destructor set to default.
     */
    ~Chili() = default;

    /**
     * Checks if the player is within a certain range of the chili.
     */
    bool collision(Object const& object) const override;

    
};

#endif
