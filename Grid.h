#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include "Snake.h"

using namespace std;

class Grid {
public:
    Grid(int width, int height);
    void draw(Snake& snake);
    bool isAppleEaten(int x, int y);
    void placeApple();

private:
    int width, height;
    int appleX, appleY;
};

#endif
