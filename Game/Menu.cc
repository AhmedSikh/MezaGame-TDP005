#include "Menu.h"
#include<SFML/Graphics.hpp>
#include <iostream>

//Constructor
Menu::Menu(float width, float height)
{
    //Loads font
    if(!font.loadFromFile("arial.ttf"))
    {
    	std::cerr << "Error: Can't load font" << std::endl;
    }
    //Lägg till default font om möjligt

    //Array content
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2, height/ (MAX_NUMBER_OF_ITEMS +1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Exit");
    menu[1].setPosition(sf::Vector2f(width/2, height/ (MAX_NUMBER_OF_ITEMS +1) * 2));

    ItemIndex = 0;
}

//Draws the array conent
void Menu::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
	    window.draw(menu[i]);
    }
}
//Navigates the menu
void Menu::MoveUp()
{
    if(ItemIndex - 1 >= 0)
    {
	menu[ItemIndex].setFillColor(sf::Color::White);
	ItemIndex--;
	menu[ItemIndex].setFillColor(sf::Color::Red);
    }
}

//Navigates the menu
void Menu::MoveDown()
{
    if(ItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
	menu[ItemIndex].setFillColor(sf::Color::White);
	ItemIndex++;
	menu[ItemIndex].setFillColor(sf::Color::Red);
    }
}

//Checks input, updates, render and displays
int Menu::run(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.waitEvent(event)) {
         switch (event.type) {

	 case sf::Event::KeyPressed:

	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	    {
		MoveUp();
		break;
	    }

	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	    {
	        MoveDown();
		break;
	    }
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	    {
		return ItemIndex;
	    }

         default:
             break;
         }


	window.clear();
	draw(window);
	window.display();
    }
    return 0;

}

int Menu::getPressedItem()
  {
      return ItemIndex;
  }







