#include "Cross.h"

Cross::Cross(int x, int y)
{
    Move_to(x, y);
    if(!Cross_texture.loadFromFile("textures/Cross.png"))
    {
        //error
    }
    Cross_sprite.setTexture(Cross_texture);
}

Cross::~Cross()
{
    //dtor
}

void Cross::Move_to(int x, int y)
{
    pos_x=x;
    pos_y=y;
}

void Cross::draw(sf::RenderWindow &window)
{
    Cross_sprite.setPosition(window.getSize().x/8.0*(float)pos_x, window.getSize().y/8.0*(float)pos_y); //Zmiana rozmiaru okna wzgledem oryginalu psuje
    Cross_sprite.setScale((window.getSize().x)/8.0/(Cross_texture.getSize().x), (window.getSize().y)/8.0/(Cross_texture.getSize().y));
    window.draw(Cross_sprite);
}

int Cross::GetPosition_x()
{
    return pos_x;
}

int Cross::GetPosition_y()
{
    return pos_y;
}

void Cross::ResetSpriteTexture()
{
    Cross_sprite.setTexture(Cross_texture);
}

void Cross::ChangeColour(int r, int g, int b)
{
    Cross_sprite.setColor(sf::Color(r, g, b, 128));
}

bool Cross::IsAtPosition(int x, int y)
{
    if(pos_x==x && pos_y==y)
    {
        return 1;
    }
    return 0;
}
