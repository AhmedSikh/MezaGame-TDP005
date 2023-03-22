#include "game.h"

#include <iostream>
#include <SFML/Graphics.hpp>

//Constructor
Game::Game(std::string const& level)
    :world{level}
{
    if(!font.loadFromFile("arial.ttf"))
    {
    	std::cerr << "Error: Can't load font" << std::endl;
    }
    //Lägg till default font

    text.setFont(font);
    text.setFillColor(sf::Color::Red);
    text.setString("Points: 0 Lives 3");
}

//Contains our game loop, updates our game, renders and displays.
void Game::run(sf::RenderWindow &window)
{
    sf::Event event;
    
    while(!close)
    {
	    while(window.pollEvent(event))
	    {
	        switch(event.type)
	        {
	        case sf::Event::Closed:
	            close = true;
		    break;
	        case sf::Event::KeyPressed:
		    if(event.key.code == sf::Keyboard::Escape)
		    {
			close = true;
			break;
		    }
		}
	    }
	    if(close)
	    {
		break;
	    }

	    input(); 
	    update();
	    time = clock.restart();
	    window.clear();
	    draw(window);
	    window.display();	
    }
   
}

//Draws our objects to the screen
void Game::draw(sf::RenderWindow &window)
{
    for(Object* entity: world.entities)
    {
	entity -> draw(window);
    }
    
    world.myPlayer.draw(window);

    for(Object* wall: world.walls )
    {
     	wall -> draw(window);
    }

    window.draw(text);
    window.draw(world.win);

    
}

//Checks collision with objects on gamefield. Updates enemy movement
void Game::update()
{
    lose_state();
    win_state();
       for( auto it{ begin(world.entities) }; it != end(world.entities); ++it )
       {
	   (*it) -> update(world.myPlayer, time);
       	   if((*it) -> collision(world.myPlayer))
       	   {
	       text.setString("Points: " + std::to_string(world.myPlayer.get_points())
			      + "  Lives: " + std::to_string(world.myPlayer.get_lives()));
       	       world.remove_object(**it); 
       	       --it;
       	   }
       }
           
       for( auto it{ begin(world.walls)}; it != end(world.walls); ++it )
       {
       	   if(world.myPlayer.collision(**it))
       	   {
	       world.myPlayer.collision_with_wall();
       	       --it;    
       	   }
     
       }
       
}

void Game::input()
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
	world.myPlayer.input(1, time);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
	world.myPlayer.input(2, time);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
	world.myPlayer.input(3, time);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
	world.myPlayer.input(4,time);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        close = true;
    }

}

void Game::win_state()
{
    if (abs(world.myPlayer.getsprite().getPosition().x
	    - world.win.getPosition().x)< 10
	&& abs(world.myPlayer.getsprite().getPosition().y
	       - world.win.getPosition().y) < 10)
    {
	if(if_won == 0)
	{
	    world.myPlayer.set_points(world.myPlayer.get_points() + world.myPlayer.get_lives() * 10);
	    ++if_won;
	}
	   
        text.setFont(font);
        text.setScale(3, 3);
        text.setPosition(50, 300);
        text.setFillColor(sf::Color::Green);
        text.setString("Congratulations You Won\nPoints: "
		       + std::to_string(world.myPlayer.get_points()));
        text.setStyle(sf::Text::Bold);
	world.myPlayer.set_speed(0);
        clock.restart();
    }
}
								 

void Game::lose_state()
{
     if (world.myPlayer.get_lives() <= 0)
    {
        text.setFont(font);
        text.setScale(4, 4);
        text.setPosition(200, 300);
        text.setFillColor(sf::Color::Red);
        text.setString("GAME OVER\nPoints: "
		       + std::to_string(world.myPlayer.get_points()));
        text.setStyle(sf::Text::Bold);
	world.myPlayer.set_speed(0);
        clock.restart();
    }
}
