#include "Queen.h"

Queen::Queen(bool C, int x, int y):
    Piece(C, x, y)
{
    switch(colour)
    {
    case 0:
        if(!Piece_texture.loadFromFile("textures/White_Queen.png"))
        {
            //error
        }
        break;
    case 1:
        if(!Piece_texture.loadFromFile("textures/Black_Queen.png"))
        {
            //error
        }
        break;
    }
    Piece_sprite.setTexture(Piece_texture);
}

Queen::~Queen()
{
    //dtor
}

bool Queen::CanLegalyGoThere(int x, int y)  //I have a feeling its extreamly inefficient
{
    if(x==pos_x && y==pos_y)
    {
        return 0;
    }
    int tx=pos_x, ty=pos_y;
    while(tx>=0 && ty>=0 && tx<8 && ty<8)   //Down and Right
    {
        tx++;
        ty++;
        if(x==tx && y==ty)
        {
            return 1;
        }
    }
    tx=pos_x;
    ty=pos_y;
    while(tx>=0 && ty>=0 && tx<8 && ty<8)   //Up and Left
    {
        tx--;
        ty--;
        if(x==tx && y==ty)
        {
            return 1;
        }
    }
    tx=pos_x;
    ty=pos_y;
    while(tx>=0 && ty>=0 && tx<8 && ty<8)   //Up and Right
    {
        tx++;
        ty--;
        if(x==tx && y==ty)
        {
            return 1;
        }
    }
    tx=pos_x;
    ty=pos_y;
    while(tx>=0 && ty>=0 && tx<8 && ty<8)   //Down and Left
    {
        tx--;
        ty++;
        if(x==tx && y==ty)
        {
            return 1;
        }
    }
    //Diagonals end here

    tx=pos_x;
    ty=pos_y;
    while(tx>=0 && ty>=0 && tx<8 && ty<8)   //Right
    {
        tx++;
        if(x==tx && y==ty)
        {
            return 1;
        }
    }

    tx=pos_x;
    while(tx>=0 && ty>=0 && tx<8 && ty<8)   //Left
    {
        tx--;
        if(x==tx && y==ty)
        {
            return 1;
        }
    }
    tx=pos_x;
    while(tx>=0 && ty>=0 && tx<8 && ty<8)   //Down
    {
        ty++;
        if(x==tx && y==ty)
        {
            return 1;
        }
    }
    ty=pos_y;
    while(tx>=0 && ty>=0 && tx<8 && ty<8)   //Up
    {
        ty--;
        if(x==tx && y==ty)
        {
            return 1;
        }
    }
    return 0;
}
