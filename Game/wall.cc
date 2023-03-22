#include "wall.h"
#include "player.h"
#include <iostream>

Wall::Wall(float h,float w,float x,float y)
    :Object{"gray.jpg", w,h ,x, y}
{}


