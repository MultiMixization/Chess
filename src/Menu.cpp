#include "Menu.h"

menu::menu()
{
    width=100;
    height=100;

    if(!font.loadFromFile("arial.ttf"))
    {
        //error
    }

    Title.setFont(font);
    Title.setFillColor(sf::Color::White);
    Title.setOutlineColor(sf::Color::Black);
    Title.setString("Szachy Konrad Siudzinski 252862");
    Title.setPosition(sf::Vector2f(width/2-Title.getLocalBounds().width/2.0,50));

    text[0].setFont(font);
    text[0].setFillColor(sf::Color::White);
    text[0].setOutlineColor(sf::Color::Black);
    text[0].setString("Graj");
    text[0].setPosition(sf::Vector2f(width/2-text[0].getLocalBounds().width/2.0,height/(MENU_SIZE+1)*1));

    text[1].setFont(font);
    text[1].setFillColor(sf::Color::White);
    text[1].setOutlineColor(sf::Color::Black);
    text[1].setString("Restartuj");
    text[1].setPosition(sf::Vector2f(width/2-text[1].getLocalBounds().width/2.0,height/(MENU_SIZE+1)*2));

    text[2].setFont(font);
    text[2].setFillColor(sf::Color::White);
    text[2].setOutlineColor(sf::Color::Black);
    text[2].setString("Wyjdz");
    text[2].setPosition(sf::Vector2f(width/2-text[2].getLocalBounds().width/2.0,height/(MENU_SIZE+1)*3));

    text[CurrSelected].setFillColor(sf::Color::Red);

    if(!background_tx.loadFromFile("textures/background.jpg"))
    {
        //error
    }
    background.setTexture(background_tx);
}

menu::menu(int H, int W)
{
    width=W;
    height=H;

    if(!font.loadFromFile("arial.ttf"))
    {
        //error
    }

    Title.setFont(font);
    Title.setFillColor(sf::Color::White);
    Title.setOutlineColor(sf::Color::Black);
    Title.setString("Szachy Konrad Siudzinski 252862");
    Title.setPosition(sf::Vector2f(width/2-Title.getLocalBounds().width/2.0,50));

    text[0].setFont(font);
    text[0].setFillColor(sf::Color::White);
    text[0].setOutlineColor(sf::Color::Black);
    text[0].setString("Graj");
    text[0].setPosition(sf::Vector2f(width/2-text[0].getLocalBounds().width/2.0,height/(MENU_SIZE+1)*1));

    text[1].setFont(font);
    text[1].setFillColor(sf::Color::White);
    text[1].setOutlineColor(sf::Color::Black);
    text[1].setString("Wyjdz");
    text[1].setPosition(sf::Vector2f(width/2-text[1].getLocalBounds().width/2.0,height/(MENU_SIZE+1)*2));

    text[2].setFont(font);
    text[2].setFillColor(sf::Color::White);
    text[2].setOutlineColor(sf::Color::Black);
    text[2].setString("Wyjdz");
    text[2].setPosition(sf::Vector2f(width/2-text[2].getLocalBounds().width/2.0,height/(MENU_SIZE+1)*3));

    text[CurrSelected].setFillColor(sf::Color::Red);
}

menu::~menu()
{

}

void menu::menu_size(int H, int W)
{
    width=W;
    height=H;

    Title.setPosition(sf::Vector2f(width/2-Title.getLocalBounds().width/2.0,50));

    text[0].setPosition(sf::Vector2f(width/2-text[0].getLocalBounds().width/2.0,height/(MENU_SIZE+1)*1));
    text[1].setPosition(sf::Vector2f(width/2-text[1].getLocalBounds().width/2.0,height/(MENU_SIZE+1)*2));
    text[2].setPosition(sf::Vector2f(width/2-text[2].getLocalBounds().width/2.0,height/(MENU_SIZE+1)*3));
}

void menu::MoveUp()
{
    if(CurrSelected>0)
    {
        text[CurrSelected].setFillColor(sf::Color::White);
        CurrSelected--;
        text[CurrSelected].setFillColor(sf::Color::Red);
    }
}

void menu::MoveDown()
{
    if(CurrSelected<NumOfOptions-1)
    {
        text[CurrSelected].setFillColor(sf::Color::White);
        CurrSelected++;
        text[CurrSelected].setFillColor(sf::Color::Red);
    }
}

void menu::Move_to(int x)
{

    if(x>=0 && x<=MENU_SIZE)
    {
        text[CurrSelected].setFillColor(sf::Color::White);
        CurrSelected=x;
        text[CurrSelected].setFillColor(sf::Color::Red);
    }
}

int menu::GetCurrOpt()
{
    return CurrSelected;
}

void menu::draw(sf::RenderWindow &window)
{
    window.draw(background);
    window.draw(Title);
    for(int i=0;i<MENU_SIZE;i++)
    {
        window.draw(text[i]);
    }
}
