#include "Horse.h"

Horse::Horse(bool C, int x, int y):
    Piece(C, x, y)
{
    switch(colour)
    {
    case 0:
        if(!Piece_texture.loadFromFile("textures/White_Horse.png"))
        {
            //error
        }
        break;
    case 1:
        if(!Piece_texture.loadFromFile("textures/Black_Horse.png"))
        {
            //error
        }
        break;
    }
    Piece_sprite.setTexture(Piece_texture);
}

Horse::~Horse()
{
    //dtor
}

bool Horse::CanLegalyGoThere(int x, int y)
{
    if(x==pos_x && y==pos_y)
    {
        return 0;
    }
    if(x==pos_x+1 && y==pos_y+2)
    {
        return 1;
    }
    if(x==pos_x-1 && y==pos_y+2)
    {
        return 1;
    }
    if(x==pos_x+2 && y==pos_y+1)
    {
        return 1;
    }
    if(x==pos_x-2 && y==pos_y+1)
    {
        return 1;
    }
    if(x==pos_x+2 && y==pos_y-1)
    {
        return 1;
    }
    if(x==pos_x-2 && y==pos_y-1)
    {
        return 1;
    }
    if(x==pos_x+1 && y==pos_y-2)
    {
        return 1;
    }
    if(x==pos_x-1 && y==pos_y-2)
    {
        return 1;
    }
    return 0;
}
