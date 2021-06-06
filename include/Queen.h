#ifndef QUEEN_H
#define QUEEN_H

#include <vector>

#include <Piece.h>

class Queen : public Piece
{
public:
    Queen(bool C, int x, int y);
    ~Queen();
    bool CanLegalyGoThere(int x, int y);
private:
};

#endif // QUEEN_H
