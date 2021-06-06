#ifndef PAWN_H
#define PAWN_H

#include <Piece.h>


class Pawn : public Piece
{
public:
    Pawn(bool C, int x, int y);
    ~Pawn();
    bool CanLegalyGoThere(int x, int y, bool EnFr, bool EnFr2, bool EnDiLe, bool EnDiRi);  //Enemy front, Enemy diagonaly left, Enemy diagonaly right
protected:

private:
};

#endif // PAWN_H
