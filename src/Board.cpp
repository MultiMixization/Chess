#include "Board.h"

Board::Board():
    White(false),
    Black(true),
    Pointer(5,5)
{
    White.GetIntel(&Black);
    Black.GetIntel(&White);
    sel_x=-1;
    sel_y=-1;
    if(!background_tx.loadFromFile("textures/board.png"))
    {
        //error
    }
    bacground.setTexture(background_tx);
}

Board::~Board()
{

}

void Board::SelectField(int x, int y)
{
    sel_x=x;
    sel_y=y;
    Pointer.Move_to(x, y);
}

void Board::MoveBack()
{
    switch(state)
    {
    case 1:
        if(player==0)
        {
            White.DeselectSource();
        }
        if(player==1)
        {
            Black.DeselectSource();
        }
        state=0;
        break;
    case 2:
        if(player==0)
        {
            White.DeselectDestination();
        }
        if(player==1)
        {
            Black.DeselectDestination();
        }
        state=1;
        break;
    default:
        break;
    }

}

bool Board::IsSelected()
{
    if(state==1 || state==2)
    {
        return 1;
    }

    return 0;
}

void Board::MakeMove()
{
    switch(state)
    {
    case 0:
        if(player==0)
        {

            White.SelectSource(sel_x, sel_y);
            state=1;
        }
        if(player==1)
        {
            Black.SelectSource(sel_x, sel_y);
            state=1;
        }
        break;
    case 1:
        if(player==0)
        {
            White.SelectDestination(sel_x, sel_y);
            if(White.MovePiece())
            {
                if(White.CheckForCheck())
                {
                    White.MoveBack();
                    state=0;
                }
                else
                {
                    if(!Black.IsEmpty(sel_x, sel_y))
                    {
                        if(Black.KingX()==sel_x && Black.KingY()==sel_y)
                        {
                            White.MoveBack();
                            state=0;
                        }
                        else
                        {
                            Black.KillOnPos(sel_x, sel_y);
                        }
                    }
                    if(state==1)
                    {
                        player=1;
                    }
                }
            }
        }
        if(player==1)
        {
            Black.SelectDestination(sel_x, sel_y);
            if(Black.MovePiece())
            {
                if(Black.CheckForCheck())
                {
                    Black.MoveBack();
                    state=0;
                }
                else
                {
                    if(!White.IsEmpty(sel_x, sel_y))
                    {
                        if(White.KingX()==sel_x && White.KingY()==sel_y)
                        {
                            Black.MoveBack();
                            state=0;
                        }
                        else
                        {
                            White.KillOnPos(sel_x, sel_y);
                        }
                    }
                    if(state==1)
                    {
                        player=0;
                    }
                }
            }
        }
        state=0;
        break;
    default:
        break;
    }
}

/*void Board::change_size(sf::RenderWindow &window)
{
    bacground.setScale(sf::Vector2f(window.getSize().x/background_tx.getSize().x, window.getSize().y/background_tx.getSize().y));
}*/

void Board::draw(sf::RenderWindow &window)
{
    window.draw(bacground);
    White.draw(window);
    Black.draw(window);
    switch(state)
    {
    case 0:
        //Pointer.ResetSpriteTexture();
        Pointer.ChangeColour(0, 0, 255);
        break;
    case 1:
        //Pointer.ResetSpriteTexture();
        Pointer.ChangeColour(255, 0, 0);
        break;
    default:
        break;
    }
    Pointer.draw(window);
}
