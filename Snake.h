#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include <utility>

using namespace std;

class Snake {
public:
    Snake();
    void move(char direction, int gridWidth, int gridHeight);
    bool checkCollision();
    pair<int, int> getHeadPosition();
    char getDirection() const;
    const vector<pair<int, int>>& getBody() const;

private:
    vector<pair<int, int>> body;
    char currentDirection;
};

#endif
