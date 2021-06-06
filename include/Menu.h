#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

#define MENU_SIZE 3

class menu
{
private:
    int CurrSelected=0, NumOfOptions=MENU_SIZE;
    int height, width;

    sf::Font font;
    sf::Text text[MENU_SIZE];
    sf::Text Title;
    sf::Texture background_tx;
    sf::Sprite background;

public:
    menu();
    menu(int H, int W);
    ~menu();


    void menu_size(int H, int W);
    void MoveUp();
    void MoveDown();
    void Move_to(int x);
    int GetCurrOpt();

    void draw(sf::RenderWindow &window);
};

#endif // MENU_H
