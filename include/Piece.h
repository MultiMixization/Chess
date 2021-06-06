#ifndef PIECE_H
#define PIECE_H

#include <vector>

#include <SFML/Graphics.hpp>

class Piece
{
public:
    Piece(bool C, int x, int y);
    ~Piece();


    void Move_to(int x, int y);
    void draw(sf::RenderWindow &window);
    int GetPosition_x();
    int GetPosition_y();
    bool IsAtPosition(int x, int y);
    bool IsAlive();
    void Kill();
    void Resurect(int x, int y);

protected:
    bool colour;    //0=white, 1=black
    bool alive;
    bool moved;

    int pos_x, pos_y;
    sf::Texture Piece_texture;
    sf::Sprite Piece_sprite;
};

#endif // PIECE_H
