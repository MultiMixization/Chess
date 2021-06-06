#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#include <Menu.h>
#include <Board.h>

class game
{
private:
    menu main_menu;
    sf::RenderWindow main_window;
    Board *play_board;

    int state=0;    //0-initializing, 1-in_menu, 2-in_game, 3-closing

    void start();
    void close();
    void main();

public:
    game();
    ~game();
};

#endif // GAME_H
