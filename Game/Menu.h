#ifndef MENU_H
#define MENU_H

//Max number of items in array defined, change for bigger array.
#define MAX_NUMBER_OF_ITEMS 2

#include <SFML/Graphics.hpp>
/**
 * Handles showing the menu and selecting options on screen.
 */

class Menu 
{
public:
    /**
     * The constructor takes the width and height to know how to center the menu.
     */
    Menu( float width, float height);
    /**
     * Returns the ItemIndex variable to find which button was pressed.
     */

    int getPressedItem();
    /**
     * Function that runs the menu loop and checks if a button has been pressed.
     */
    int run(sf::RenderWindow &window);

private:

    /**
     * Loops though the array that contains all the elements and displays them on screen
     */
    void draw(sf::RenderWindow &window);
    /**
     * Subtracts from the ItemIndex variable and changes the color of the text depending on what Index the ItemIdex variable has.
     */
    void MoveUp();
    /**
     *Adds to the ItemIndex variable and changes the color of the text depending on what Index the ItemIdex variable has.
     */
    void MoveDown();

    
    /**
     * Private variable that holds the position of the selected button in the menu.
     */
    int ItemIndex{};
    /**
     * Private variable that contains the font that the displayed text has.
     */
    sf::Font font{};
    /**
     * Private variable that contains the array of elements that is shown on screen.
     */
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};


#endif
