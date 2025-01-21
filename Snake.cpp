#include "Snake.h"

using namespace std;

Snake::Snake() {
    body.push_back({5, 5});
    currentDirection = 'R';
}

void Snake::move(char direction, int gridWidth, int gridHeight) {
    currentDirection = direction;
    auto head = body.front();

    // Calcola la nuova posizione della testa del serpente
    switch (currentDirection) {
        case 'U':
            head.first = (head.first - 1 + gridHeight) % gridHeight;
        if (head.first == 0) head.first = gridHeight - 2; // Evita il bordo superiore
        break;
        case 'D':
            head.first = (head.first + 1) % gridHeight;
        if (head.first == gridHeight - 1) head.first = 1; // Evita il bordo inferiore
        break;
        case 'L':
            head.second = (head.second - 1 + gridWidth) % gridWidth;
        if (head.second == 0) head.second = gridWidth - 2; // Evita il bordo sinistro
        break;
        case 'R':
            head.second = (head.second + 1) % gridWidth;
        if (head.second == gridWidth - 1) head.second = 1; // Evita il bordo destro
        break;
    }

    // Aggiungi la nuova testa e rimuovi la coda
    body.insert(body.begin(), head);
    body.pop_back();
}

bool Snake::checkCollision() {
    auto head = body.front();
    for (size_t i = 1; i < body.size(); i++) {
        if (body[i] == head) return true;
    }
    return false;
}

pair<int, int> Snake::getHeadPosition() {
    return body.front();
}

char Snake::getDirection() const {
    return currentDirection;
}

const vector<pair<int, int>>& Snake::getBody() const {
    return body;
}
