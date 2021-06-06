#include "Piece.h"

Piece::Piece(bool C, int x, int y):
    colour(C),
    pos_x(x),
    pos_y(y)
{
    alive=1;
    moved=0;
}

Piece::~Piece()
{

}

void Piece::Move_to(int x, int y)
{
    pos_x=x;
    pos_y=y;
    moved=1;
}

int Piece::GetPosition_x()
{
    return pos_x;
}

int Piece::GetPosition_y()
{
    return pos_y;
}

bool Piece::IsAtPosition(int x, int y)
{
    if(pos_x==x && pos_y==y)
    {
        return 1;
    }
    return 0;
}

bool Piece::IsAlive()
{
    return alive;
}

void Piece::Kill()
{
    alive=0;
    Move_to(-1, -1);
}

void Piece::Resurect(int x, int y)
{
    alive=1;
    Move_to(x, y);
}

void Piece::draw(sf::RenderWindow &window)
{
    if(IsAlive())
    {
        Piece_sprite.setPosition(window.getSize().x/8.0*(float)pos_x, window.getSize().y/8.0*(float)pos_y); //Zmiana rozmiaru okna wzgledem oryginalu psuje
        Piece_sprite.setScale((window.getSize().x)/8.0/(Piece_texture.getSize().x), (window.getSize().y)/8.0/(Piece_texture.getSize().y));
        window.draw(Piece_sprite);
    }
}
