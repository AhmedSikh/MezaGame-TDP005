#include "player.h"
#include "world.h"
#include "object.h"

#include <iostream>

/*
Here we define all our objects
*/

Object::Object(std::string text,float w, float h, float x, float y)
{
    if(!texture.loadFromFile(text))
    {
	std::cerr << "Error: Texture can't load";
    }

    //Om tid lägg till default texture

    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setScale(w,h);
}

void Object::draw(sf::RenderWindow &window) const
{
    window.draw(sprite);
}

bool Object::collision(Object const& other) const
{
    if(sprite.getGlobalBounds( ).intersects( other.getsprite().getGlobalBounds( ) ))
    {
	return true;
    }
    else
    {
	return false;
    }
}

//Used to check collision
sf::Sprite Object::getsprite() const
{
    return sprite;
}




