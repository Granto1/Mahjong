#include <cassert>
#include <iostream>
#include <array>
#include <string.h>
#include <Tile.cpp>
#include <vector>
class Wall
{
public:
    Wall()
    {
        for (int a = 0; a < 3; a++)
        {
            for (int b = 0; b < 10; b++)
            {
                wall.push_back(new Tile(a, b))
            }
        }
    }

private:
    vector<Tile> wall;
};