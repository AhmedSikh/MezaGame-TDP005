#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "player.h"
#include "cookie.h"
#include "wall.h"
#include "enemy.h"
#include "world.h"

/**
 * Runs and updates the game.
 */

class Game
{
 public:
    
    /**
     * The constructor takes the name of the file that contains the level the game will run as parameter.
     */
    Game(std::string const& level);

    /**
     * Runs the game loop.
     */
    void run(sf::RenderWindow &window);
 
 private:
    /**
     * Displays all objects in the level on the window.
     */
    void draw(sf::RenderWindow &window);
    /**
     * Handles input recievec from the user that moves the player or exites the game loop.
     */
    void input();
    /**
     * Updates player when collided with objects, moves enemys on their route and updates the text that displays the amount of points and lives the player has.
     */
    void update();
    /**
     * Changes the text on screen to displsy if the player has won the game.
     */
    void win_state();
    /**
     *  Changes the text on screen to displsy if the player has lost the game.
     */
    void lose_state();

    /**
     * Private bool variable that is change if the loop should break.
     */
    bool close = false;
    /**
     * Private variable that contains the text string that is shown on screen. 
     */
    sf::Text text;
    /**
     * Private variable that contains the font that the displayed text has.
     */
    sf::Font font;

    /**
     * Holds the game time.
     */
    sf::Clock clock;
    /**
     * Holds the frame time.
     */
    sf::Time time;

    /**
     * Object of type world that contains the objects that is being displayd on screen. 
     */
    World world;
    /**
     * Is changed if a player has won.
     */
    int if_won{};

};


#endif
