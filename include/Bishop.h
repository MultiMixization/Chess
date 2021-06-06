#ifndef BISHOP_H
#define BISHOP_H

#include <Piece.h>


class Bishop : public Piece
{
public:
    Bishop(bool C, int x, int y);
    ~Bishop();
    bool CanLegalyGoThere(int x, int y);
protected:

private:
};

#endif // BISHOP_H
