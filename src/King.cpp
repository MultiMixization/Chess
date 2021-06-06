#include "King.h"

King::King(bool C, int x, int y):
    Piece(C, x, y)
{
    switch(colour)
    {
    case 0:
        if(!Piece_texture.loadFromFile("textures/White_King.png"))
        {
            //error
        }
        break;
    case 1:
        if(!Piece_texture.loadFromFile("textures/Black_King.png"))
        {
            //error
        }
        break;
    }
    Piece_sprite.setTexture(Piece_texture);
}

King::~King()
{
    //dtor
}

bool King::CanLegalyGoThere(int x, int y)
{
    if(x==pos_x && y==pos_y)
    {
        return 0;
    }

    if(x==pos_x+1 && y==pos_y)
    {
        return 1;
    }
    if(x==pos_x+1 && y==pos_y+1)
    {
        return 1;
    }
    if(x==pos_x && y==pos_y+1)
    {
        return 1;
    }
    if(x==pos_x-1 && y==pos_y+1)
    {
        return 1;
    }
    if(x==pos_x-1 && y==pos_y)
    {
        return 1;
    }
    if(x==pos_x-1 && y==pos_y-1)
    {
        return 1;
    }
    if(x==pos_x && y==pos_y-1)
    {
        return 1;
    }
    if(x==pos_x+1 && y==pos_y-1)
    {
        return 1;
    }
    return 0;
}
