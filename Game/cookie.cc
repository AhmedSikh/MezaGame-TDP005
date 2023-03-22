#include "cookie.h"
#include "player.h"
#include "world.h"


Cookie::Cookie(std::string image, float x, float y,int points)
    :Object{image, 0.35, 0.35, x, y},points{points}
{}

void Cookie::update(Player &object, sf::Time time)
{
    if(object.get_points() + points >= 0)
    {	
	if (collision(object))
        {
	    object.set_points(object.get_points() + points);
	}
    }
}



BadCookie::BadCookie(float x, float y)
    :Cookie("images/bad.png",x, y, -3)
{}



GoodCookie::GoodCookie(float x, float y)
    :Cookie("images/good.png",x, y, 5)
{}







