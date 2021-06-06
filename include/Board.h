#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

#include <Team.h>
#include <Cross.h>

#define BOARD_SIZE 8

class Board
{
private:
    int size_x=BOARD_SIZE, size_y=BOARD_SIZE;
    int sel_x, sel_y;
    int player=0;   //0=white, 1=black
    int state=0;    //0=nothing selected, 1=source selected
    sf::Texture background_tx;
    sf::Sprite bacground;
    Team White;
    Team Black;
    Cross Pointer;

public:
    Board();
    ~Board();

    void MakeMove();
    void SelectField(int x, int y);
    void MoveBack();
    bool IsSelected();
    //void change_size(sf::RenderWindow &window);   //Nie potrzebne, robi sie samo
    void draw(sf::RenderWindow &window);
};


#endif // BOARD_H
