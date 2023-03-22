#include "player.h"
#include "world.h"
#include "object.h"


#include<SFML/Graphics.hpp>



Player::Player()
    :Entity{"images/player.png", 0.3, 0.3, 200, 200}, lives{3},speed{150.0f}
{}

//used when collision with wall occurs in
void Player::input(int direction, sf::Time time)
{
    move_direction = direction;
    movement = time;
    move(time);
}

//checks if player can move and if so moves it
void Player::move(sf::Time time)
{
    float moving_speed = speed * time.asSeconds();
   
    if(move_direction == 1)//move up
    {
	if(canMoveUp)
	{
	    sprite.move(0, -moving_speed);
	}
    }
    else if(move_direction == 2)//move down
    {
	if(canMoveDown)
	{
	    sprite.move(0, moving_speed);
	}
    }
    else if(move_direction == 3)//move left
    {
	if(canMoveLeft)
	{
	    sprite.move(-moving_speed, 0);
	}
    }
    else if(move_direction == 4)//move right
    {
	if(canMoveRight)
	{
	    sprite.move(moving_speed, 0);
	}
    }
    canMoveUp = true;
    canMoveDown = true;
    canMoveLeft = true;
    canMoveRight = true;
}

//If player collides with wall it is "pushed out" from wall so as to not get stuck
void Player::collision_with_wall()
{
    if(move_direction == 1)
    {
	canMoveUp = false;
        input(2,movement);
    }
    else if(move_direction == 2)
    {
	canMoveDown =  false;
	input(1,movement);
    }
    else if(move_direction == 3)
    {
	canMoveLeft = false;
        input(4,movement);
    }
    else if(move_direction == 4)
    {
	canMoveRight = false;
        input(3,movement);
    }
}


void Player::set_points(int new_points)
{
    points = new_points;
}

int Player::get_points() const
{
    return points;
}

void Player::set_lives(int new_lives)
{
    lives = new_lives;
}

int Player::get_lives() const
{
    return lives;
}

void Player::set_speed(float new_speed)
{
    speed = new_speed;
}


void Player::change_coordinates(float x, float y)
{
    sprite.setPosition(x, y);
}

