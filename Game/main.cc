#include "game.h"
#include "Menu.h"
#include <iostream>

int main()
{
    Menu menu{1200,800};
    sf::RenderWindow window;

    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width/2)-755,
			      (sf::VideoMode::getDesktopMode().height/2)-390);
    window.create(sf::VideoMode(1200,800), "ME WANT COOKIE!!",
		  sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    window.setKeyRepeatEnabled(true);
    

bool quit = false;
     while(!quit)
     {
	 if(menu.run(window) == 0)
	 {
	     Game game{"level1.txt"};
	     game.run(window);
	 }
	 else
	 {
	     quit = true;
	 }
	 
     }
 
}
