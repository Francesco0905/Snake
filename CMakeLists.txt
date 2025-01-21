cmake_minimum_required(VERSION 3.15)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)

# Aggiungi il percorso di ncurses installato tramite Homebrew
include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

# Aggiungi i file sorgenti
add_executable(SnakeGame main.cpp Game.cpp Snake.cpp Grid.cpp)

# Collega la libreria ncurses
target_link_libraries(SnakeGame ncurses)
