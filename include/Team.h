#ifndef TEAM_H
#define TEAM_H

#include <Queen.h>
#include <King.h>
#include <Horse.h>
#include <Tower.h>
#include <Bishop.h>
#include <Pawn.h>

class Team
{
    public:
        Team();
        Team(bool C);
        ~Team();

        void GetIntel(Team *E); //I love this fc name
        void SelectSource(int x, int y);
        void DeselectSource();
        void DeselectDestination();
        void SelectDestination(int x, int y);
        int GetSourceX();
        int GetSourceY();
        bool IsEmpty(int x, int y);
        bool MovePiece();
        void MoveBack();
        bool CheckForCheck();
        bool NothingInBetween(int Xsource, int Ysource, int Xdestination, int Ydestination);
        void draw(sf::RenderWindow &window);
        void KillOnPos(int x, int y);
        void KingSideCastling();
        void QueenSideCastling();
        bool FieldUnderAttack(int x, int y);
        int KingX();
        int KingY();

    private:
        bool colour;
        int xs=-1, ys=-1, xd=-1, yd=-1;
        Team *Enemy;        //This is brilliant
        Queen Q;
        King K;
        Horse H1;
        Horse H2;
        Tower T1;
        Tower T2;
        Bishop B1;
        Bishop B2;
        Pawn P1, P2, P3, P4, P5, P6, P7, P8;
};

#endif // TEAM_H
