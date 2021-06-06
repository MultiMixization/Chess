#include "Pawn.h"

Pawn::Pawn(bool C, int x, int y):
    Piece(C, x, y)
{
    switch(colour)
    {
    case 0:
        if(!Piece_texture.loadFromFile("textures/White_Pawn.png"))
        {
            //error
        }
        break;
    case 1:
        if(!Piece_texture.loadFromFile("textures/Black_Pawn.png"))
        {
            //error
        }
        break;
    }
    Piece_sprite.setTexture(Piece_texture);
}

Pawn::~Pawn()
{
    //dtor
}

bool Pawn::CanLegalyGoThere(int x, int y, bool EnFr, bool EnFr2, bool EnDiLe, bool EnDiRi)
{
    if(x==pos_x && y==pos_y)
    {
        return 0;
    }
    if(colour==0)
    {
        if(moved)
        {

            if(x==pos_x && y==pos_y-1 && !EnFr)
            {
                return 1;
            }
            if(x==pos_x+1 && y==pos_y-1 && EnDiRi)
            {
                return 1;
            }
            if(x==pos_x-1 && y==pos_y-1 && EnDiLe)
            {
                return 1;
            }
            return 0;
        }
        else        //Dla pierwszego ruchu
        {
            if(x==pos_x && ((y==pos_y-1 && !EnFr)||( y==pos_y-2 && !EnFr && !EnFr2)))
            {
                return 1;
            }
            if(x==pos_x+1 && y==pos_y-1 && EnDiRi)
            {
                return 1;
            }
            if(x==pos_x-1 && y==pos_y-1 && EnDiLe)
            {
                return 1;
            }
            return 0;
        }
    }
    else
    {
        if(moved)
        {
            if(x==pos_x && y==pos_y+1 && !EnFr)
            {
                return 1;
            }
            if(x==pos_x+1 && y==pos_y+1 && EnDiLe)
            {
                return 1;
            }
            if(x==pos_x-1 && y==pos_y+1 && EnDiRi)
            {
                return 1;
            }
            return 0;
        }
        else        //Dla pierwszego ruchu
        {
            if(x==pos_x && ((y==pos_y+1 && !EnFr)||( y==pos_y+2 && !EnFr && !EnFr2)))
            {
                return 1;
            }
            if(x==pos_x+1 && y==pos_y+1 && EnDiLe)
            {
                return 1;
            }
            if(x==pos_x-1 && y==pos_y+1 && EnDiRi)
            {
                return 1;
            }
            return 0;
        }
    }
}
