#include "Grid.h"
#include <cstdlib>
#include <ctime>
#include <curses.h>

using namespace std;

Grid::Grid(int width, int height) : width(width), height(height) {
    srand(time(nullptr));
    placeApple();
}

void Grid::draw(Snake& snake) {
    // Disegna i bordi della griglia
    for (int i = 0; i <= height + 1; ++i) {
        for (int j = 0; j <= width + 1; ++j) {
            if (i == 0 || i == height + 1 || j == 0 || j == width + 1) {
                mvaddch(i + 2, j, '#'); // Bordi esterni
            } else {
                mvaddch(i + 2, j, ' '); // Spazio interno
            }
        }
    }

    // Aggiungi la mela all'interno della griglia
    mvaddch(appleX + 2, appleY + 1, 'A');

    // Disegna il corpo del serpente all'interno della griglia
    for (auto segment : snake.getBody()) {
        mvaddch(segment.first + 2, segment.second + 1, 'O');
    }

    refresh();
}

bool Grid::isAppleEaten(int x, int y) {
    // Controlla se il serpente ha mangiato la mela
    return (x == appleX && y == appleY);
}

void Grid::placeApple() {
    // Posiziona la mela in una posizione casuale all'interno della griglia (escludendo i bordi)
    appleX = rand() % height + 1; // Altezza interna (da 1 a height)
    appleY = rand() % width + 1;  // Larghezza interna (da 1 a width)
}

