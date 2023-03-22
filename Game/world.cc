#include "world.h"
#include "object.h"
#include "cookie.h"
#include "wall.h"
#include "player.h"
#include "enemy.h"
#include <fstream>

World::World(std::string levelname)
{
    read_level(levelname);
    if(!texture.loadFromFile("images/win.png"))
    {
	std::cerr << "Error: Texture can't load";
    }
    win.setTexture(texture);
    win.setScale(0.4,0.4);
    
}

World::~World()
{
    for(auto it{begin(entities)}; it != end(entities); ++it)
    {
	delete *it;
	entities.erase(it);
	--it;
    }
    
    for( auto it{ begin(walls)}; it != end(walls); ++it )
    {
	delete (*it);
	walls.erase(it);
	--it;
     } 
    
}

void World::read_level(const std::string levelname)
{
    std::ifstream ifs(levelname);
    std::string type{};
    float x_pos, y_pos, width, height, dist;
    int  first, second, third, fourth;
    
   
    while(ifs >> type)
    {
	if(type == "Player")
	{
	    ifs >> x_pos >> y_pos;
	    myPlayer.change_coordinates(x_pos, y_pos);
	    ifs.ignore(1000, '\n');
	}
	if(type == "Wall")
	{
	    ifs >> width >> height >> x_pos >> y_pos;
	    walls.push_back(new Wall{width, height, x_pos, y_pos});
	    ifs.ignore(1000, '\n');
	}
	
	if(type == "GoodCookie")
	{
	    ifs >> x_pos >> y_pos;
	    entities.push_back(new GoodCookie{x_pos, y_pos});
	    ifs.ignore(1000, '\n');
	    
	}

	if(type == "Carrot")
	{
	    ifs >> x_pos >> y_pos >> first >> second >> third >> fourth >> dist;
	    entities.push_back(new Carrot{x_pos, y_pos, first, second, third, fourth, dist});
	    ifs.ignore(1000, '\n');
	}
	
	if(type == "BadCookie")
	{
	    ifs >> x_pos >> y_pos;
	    entities.push_back(new BadCookie{x_pos, y_pos});
	    ifs.ignore(1000, '\n');
	    
	}

	if(type == "Chili")
	{
	    ifs >> x_pos >> y_pos >> first >> second >> third >> fourth >> dist;
	    entities.push_back(new Chili{x_pos, y_pos, first, second, third, fourth, dist});
	    ifs.ignore(1000, '\n');
	}
	if(type == "Win")
	{
	    ifs >> x_pos >> y_pos;
	    win.setPosition(x_pos, y_pos);
	    ifs.ignore(1000, '\n');
	}
    }
}


void World::remove_object(Object &object)
{
    for( auto it{ begin(entities)}; it != end(entities); ++it )
    {
        if(&object == *it)
        {
            delete (*it);
	    entities.erase(it);
	    --it;
 
    	 }
    }

}


