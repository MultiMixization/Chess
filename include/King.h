#ifndef KING_H
#define KING_H

#include <Piece.h>


class King : public Piece
{
public:
    King(bool C, int x, int y);
    ~King();
    bool CanLegalyGoThere(int x, int y);
private:
};

#endif // KING_H
