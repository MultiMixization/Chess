#ifndef TOWER_H
#define TOWER_H

#include <Piece.h>


class Tower : public Piece
{
    public:
        Tower(bool C, int x, int y);
        ~Tower();
        bool CanLegalyGoThere(int x, int y);
    protected:

    private:
};

#endif // TOWER_H
