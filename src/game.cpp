#include "game.h"

game::game()
{
    start();
}

game::~game()
{
    close();
}

void game::start()
{
    main_window.create(sf::VideoMode(720, 720), "SFML PWR CHESS", sf::Style::Default);
    main_window.setFramerateLimit(60);

    main_menu.menu_size(main_window.getSize().x, main_window.getSize().y);
    state=1;

    play_board = new Board();

    main();
}

void game::main()
{
    int SelectedX=5, SelectedY=0;
    while(main_window.isOpen()) //Glowna petla programu
    {
        sf::Event event;
        while(main_window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                close();
                break;
            case sf::Event::Resized:
                break;
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Up:
                    switch(state)
                    {
                    case 1:
                        main_menu.MoveUp();
                        break;
                    case 2:
                        if(SelectedY>0)
                        {
                            SelectedY--;
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                case sf::Keyboard::Down:
                    switch(state)
                    {
                    case 1:
                        main_menu.MoveDown();
                        break;
                    case 2:
                        if(SelectedY<7)
                        {
                            SelectedY++;
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                case sf::Keyboard::Right:
                    switch(state)
                    {
                    case 2:
                        if(SelectedX<7)
                        {
                            SelectedX++;
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                case sf::Keyboard::Left:
                    switch(state)
                    {
                    case 2:
                        if(SelectedX>0)
                        {
                            SelectedX--;
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                case sf::Keyboard::Enter:
                    switch(state)
                    {
                    case 1:
                        switch(main_menu.GetCurrOpt())
                        {
                        case 0:
                            state=2;
                            break;
                        case 1:
                            delete play_board;
                            play_board = new Board();
                            break;
                        case 2:
                            state=3;
                            break;
                        default:
                            break;
                        }
                        break;
                    case 2:
                        play_board->MakeMove();
                        break;
                    default:
                        break;
                    }
                    break;
                case sf::Keyboard::Escape:
                    switch(state)
                    {
                    case 1:
                        state=3;
                        break;
                    case 2:
                        if(play_board->IsSelected())
                        {
                            play_board->MoveBack();
                        }
                        else
                        {
                            state=1;
                        }
                        break;
                    }
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }

            switch(state)
            {
            case 0:
                start();
                break;
            case 1:     //Menu
                main_window.clear();
                main_menu.draw(main_window);
                main_window.display();
                break;
            case 2:     //Game
                play_board->SelectField(SelectedX, SelectedY);
                main_window.clear();
                play_board->draw(main_window);
                main_window.display();
                break;
            case 3:
                close();
            default:
                break;
            }
        }
    }
}

void game::close()
{
    main_window.clear();
    main_window.close();
}
