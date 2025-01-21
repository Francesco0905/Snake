#include "Game.h"
#include <fstream>
#include <iostream>
#include <unistd.h>

using namespace std;

void Game::run() {
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    bool running = true;

    while (running) {
        displayMenu();
        int choice = getch();
        switch (choice) {
            case '1':
                startNewGame();
                break;
            case '2':
                showLeaderboard();
                break;
            case '3':
                running = false;
                break;
            default:
                mvprintw(10, 0, "Scelta non valida. Premi un tasto per continuare...");
                getch();
        }
    }

    endwin();
}

void Game::displayMenu() {
    clear();
    mvprintw(0, 0, "---- SNAKE GAME ----");
    mvprintw(2, 0, "1. Nuova partita");
    mvprintw(3, 0, "2. Visualizza classifica");
    mvprintw(4, 0, "3. Esci");
    mvprintw(6, 0, "Scelta: ");
    refresh();
}

void Game::startNewGame() {
    Snake snake;
    Grid grid(20, 10); // Dimensioni della griglia: 20x10
    bool gameOver = false;
    int score = 0;
    time_t startTime = time(nullptr);

    while (!gameOver) {
        clear();

        // Mostra punteggio e tempo sopra la griglia
        mvprintw(0, 0, "Punteggio: %d", score);
        mvprintw(1, 0, "Tempo: %ld s", time(nullptr) - startTime);

        // Disegna la griglia e il serpente
        grid.draw(snake);

        // Abilita input non bloccante
        nodelay(stdscr, TRUE);
        int input = getch();
        char direction = snake.getDirection();
        if (input == KEY_UP) direction = 'U';
        if (input == KEY_DOWN) direction = 'D';
        if (input == KEY_LEFT) direction = 'L';
        if (input == KEY_RIGHT) direction = 'R';
        if (input == 'q') {
            gameOver = true;
            break;
        }

        // Muovi il serpente considerando le dimensioni interne della griglia
        snake.move(direction, 20, 10);

        // Controlla collisioni
        auto head = snake.getHeadPosition();
        if (snake.checkCollision()) {
            mvprintw(15, 0, "Hai perso! Premi un tasto per continuare...");
            getch();
            gameOver = true;
        }
        if (grid.isAppleEaten(head.first, head.second)) {
            score += 10;
            grid.placeApple();
        }

        refresh();
        usleep(200000);
    }

    saveScore(score);
    nodelay(stdscr, FALSE);
    mvprintw(15, 0, "Game Over! Punteggio finale: %d", score);
    getch();
}




void Game::showLeaderboard() {
    clear();
    ifstream file("leaderboard.txt");
    mvprintw(0, 0, "Classifica:");
    int line = 1;
    if (!file) {
        mvprintw(2, 0, "Nessuna classifica trovata.");
    } else {
        string entry;
        while (getline(file, entry)) {
            mvprintw(line++, 0, "%s", entry.c_str());
        }
        file.close();
    }
    mvprintw(line + 1, 0, "Premi un tasto per tornare al menu...");
    getch();
}

void Game::saveScore(int score) {
    ofstream file("leaderboard.txt", ios::app);
    if (file) {
        file << "Punteggio: " << score << "\n";
        file.close();
    }
}
