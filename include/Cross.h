#ifndef CROSS_H
#define CROSS_H

#include <SFML/Graphics.hpp>

class Cross
{
public:
    Cross(int x, int y);
    ~Cross();

    void Move_to(int x, int y);
    void draw(sf::RenderWindow &window);
    int GetPosition_x();
    int GetPosition_y();
    bool IsAtPosition(int x, int y);
    void ChangeColour(int r, int g, int b);
    void ResetSpriteTexture();

protected:

private:
    int pos_x, pos_y;
    sf::Texture Cross_texture;
    sf::Sprite Cross_sprite;
};

#endif // CROSS_H
