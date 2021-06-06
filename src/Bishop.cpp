#include "Bishop.h"

Bishop::Bishop(bool C, int x, int y):
    Piece(C, x, y)
{
    switch(colour)
    {
    case 0:
        if(!Piece_texture.loadFromFile("textures/White_Bishop.png"))
        {
            //error
        }
        break;
    case 1:
        if(!Piece_texture.loadFromFile("textures/Black_Bishop.png"))
        {
            //error
        }
        break;
    }
    Piece_sprite.setTexture(Piece_texture);
}

Bishop::~Bishop()
{
    //dtor
}

bool Bishop::CanLegalyGoThere(int x, int y)
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
    return 0;
}
