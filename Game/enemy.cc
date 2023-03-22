#include "enemy.h"
#include "entity.h"
#include "world.h"
#include "object.h"
#include "player.h"
#include <math.h>

/*
Class where we define our enemy and how it walks around the game field.
*/


Enemy::Enemy(std::string image, float x, float y, int dir_1, int dir_2, int dir_3, int dir_4,float dist,int lives)
    :Entity{image,0.3,0.3, x, y},distance{dist},lives_to_take{lives}
     
     //Vector with enemy's route on gamefield
{
    route.push_back(dir_1);
    route.push_back(dir_2);
    route.push_back(dir_3);
    route.push_back(dir_4);
    move_direction = route[0];
}

void Enemy::update(Player &object,  sf::Time time)
{
    move(time);
    
    if (collision(object))
    {
	object.set_lives(object.get_lives() - lives_to_take);
    }
}

void Enemy::move(sf::Time time)
{
    if(move_direction == 1)//move up
    {	
	sprite.move(0, -100.0f * time.asSeconds());	    
    }
    
    else if(move_direction == 2)//move down
    {      
	sprite.move(0, 100.0f * time.asSeconds());	    
    }
    
    else if(move_direction == 3)//move left
    {
	sprite.move(-100.0f * time.asSeconds(), 0);	   
    }
    else if(move_direction == 4)//move down
    {
	sprite.move(100.0f * time.asSeconds(), 0);
    }
    enemy_route(time);
 
}

//Changes direction of the sprite, according to it's route
void Enemy::enemy_route(sf::Time time)
{
    movement -= time;
    if(movement < sf::Time{})
    {
	if(move_direction == route[0] )
	{
	    move_direction = route[1];
	}
	else if(move_direction == route[1])
	        
	{
	    move_direction = route[2];
	    
	}
	else if(move_direction == route[2])
	{
	    move_direction = route[3];
	}
	else
	{
	    move_direction = route[0];
	}
        movement = sf::seconds(distance);
    }    
}



Carrot::Carrot(float x, float y, int dir_1, int dir_2, int dir_3, int dir_4,float dist)
    :Enemy{"images/carrot.png",x, y, dir_1, dir_2, dir_3, dir_4, dist, 1}
{}


Chili::Chili(float x, float y, int dir_1, int dir_2, int dir_3, int dir_4,float dist)
    :Enemy{"images/chilli.png", x, y, dir_1, dir_2, dir_3, dir_4, dist, 2}
{}

//Collision with chili when within its range.
bool Chili::collision(Object const& object) const
{
    float a = pow(object.getsprite().getPosition().x
		  - sprite.getPosition().x,2);
    float b = pow(object.getsprite().getPosition().y
		  - sprite.getPosition().y,2);
    float c = sqrt(b+a);
    if(c < 80)
    {
        return true;
    }
    return false;	
}


