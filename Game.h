#ifndef GAME_HPP
#define GAME_HPP

#include <curses.h>
#include <ctime>
#include "Snake.h"
#include "Grid.h"

using namespace std;

class Game {
public:
    void run();
private:
    void startNewGame();
    void showLeaderboard();
    void displayMenu();
    void saveScore(int score);
};

#endif
