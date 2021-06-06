#ifndef HORSE_H
#define HORSE_H

#include <Piece.h>


class Horse : public Piece
{
public:
    Horse(bool C, int x, int y);
    ~Horse();
    bool CanLegalyGoThere(int x, int y);
protected:

private:
};

#endif // HORSE_H
