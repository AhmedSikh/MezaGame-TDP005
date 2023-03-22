#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <string>
#include "player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Wall;

class Player;

class Cookie;

class Enemy;

class Object;


/**
 * Holds all the game objects, and reads them from a file.
 */

class World {

public:
    /**
     *  The constructor takes the name of the file that contains the level.
     */
     World(std::string levelname);
    /**
     * Deletes all objects that are stored on the heap.
     */
    ~World();
    /**
     * Removes one object from the entities vector.
     */
    void remove_object(Object &object);
    /**
     * Public variable that contains wall objects.
     */
    std::vector<Object*> walls;
    /**
     * Public variable that contains entity objects.
     */
    std::vector<Object*> entities;
    /**
     * Public variable an object of type player.
     */
    Player myPlayer;
    /**
     * A sprite that represent the goal for the player to reach.
     */
    sf::Sprite win{};
private:
    /**
     * Reads the level from a file and initiates, and places objects on the game field. 
     */
    void read_level(const std::string levelname);
    /**
     * Private variable that holds the texture of the win sprite.
     */
    sf::Texture texture{};
   
};

#endif
