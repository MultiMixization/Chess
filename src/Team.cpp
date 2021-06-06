#include "Team.h"

Team::Team(bool C):
    colour(C),
    Q(colour, 3, (colour==0 ? 7 : 0)),
    K(colour, 4, (colour==0 ? 7 : 0)),
    H1(colour, 1, (colour==0 ? 7 : 0)),
    H2(colour, 6, (colour==0 ? 7 : 0)),
    T1(colour, 0, (colour==0 ? 7 : 0)),
    T2(colour, 7, (colour==0 ? 7 : 0)),
    B1(colour, 2, (colour==0 ? 7 : 0)),
    B2(colour, 5, (colour==0 ? 7 : 0)),
    P1(colour, 0, (colour==0 ? 6 : 1)),
    P2(colour, 1, (colour==0 ? 6 : 1)),
    P3(colour, 2, (colour==0 ? 6 : 1)),
    P4(colour, 3, (colour==0 ? 6 : 1)),
    P5(colour, 4, (colour==0 ? 6 : 1)),
    P6(colour, 5, (colour==0 ? 6 : 1)),
    P7(colour, 6, (colour==0 ? 6 : 1)),
    P8(colour, 7, (colour==0 ? 6 : 1))
{
}

Team::~Team()
{

}

void Team::GetIntel(Team *E)
{
    Enemy=E;
}

void Team::SelectSource(int x, int y)
{
    xs=x;
    ys=y;
}

void Team::SelectDestination(int x, int y)
{
    xd=x;
    yd=y;
}

void Team::DeselectSource()
{
    xs=-1;
    ys=-1;
}

void Team::DeselectDestination()
{
    xd=-1;
    yd=-1;
}

int Team::GetSourceX()
{
    return xs;
}

int Team::GetSourceY()
{
    return ys;
}

void Team::KillOnPos(int x, int y)
{
    if(Q.IsAtPosition(x, y)) {Q.Kill();}
    if(H1.IsAtPosition(x, y)) {H1.Kill();}
    if(H2.IsAtPosition(x, y)) {H2.Kill();}
    if(T1.IsAtPosition(x, y)) {T1.Kill();}
    if(T2.IsAtPosition(x, y)) {T2.Kill();}
    if(B1.IsAtPosition(x, y)) {B1.Kill();}
    if(B2.IsAtPosition(x, y)) {B2.Kill();}
    if(P1.IsAtPosition(x, y)) {P1.Kill();}
    if(P2.IsAtPosition(x, y)) {P2.Kill();}
    if(P3.IsAtPosition(x, y)) {P3.Kill();}
    if(P4.IsAtPosition(x, y)) {P4.Kill();}
    if(P5.IsAtPosition(x, y)) {P5.Kill();}
    if(P6.IsAtPosition(x, y)) {P6.Kill();}
    if(P7.IsAtPosition(x, y)) {P7.Kill();}
    if(P8.IsAtPosition(x, y)) {P8.Kill();}
}

bool Team::IsEmpty(int x, int y)
{
    if(Q.IsAtPosition(x, y)) {return 0;}
    if(K.IsAtPosition(x, y)) {return 0;}
    if(H1.IsAtPosition(x, y)) {return 0;}
    if(H2.IsAtPosition(x, y)) {return 0;}
    if(T1.IsAtPosition(x, y)) {return 0;}
    if(T2.IsAtPosition(x, y)) {return 0;}
    if(B1.IsAtPosition(x, y)) {return 0;}
    if(B2.IsAtPosition(x, y)) {return 0;}
    if(P1.IsAtPosition(x, y)) {return 0;}
    if(P2.IsAtPosition(x, y)) {return 0;}
    if(P3.IsAtPosition(x, y)) {return 0;}
    if(P4.IsAtPosition(x, y)) {return 0;}
    if(P5.IsAtPosition(x, y)) {return 0;}
    if(P6.IsAtPosition(x, y)) {return 0;}
    if(P7.IsAtPosition(x, y)) {return 0;}
    if(P8.IsAtPosition(x, y)) {return 0;}
    return 1;
}

bool Team::MovePiece()
{
    if(Q.GetPosition_x()==xs && Q.GetPosition_y()==ys)
    {
        if(Q.CanLegalyGoThere(xd, yd) && IsEmpty(xd, yd) && NothingInBetween(xs, ys, xd, yd))
        {
            Q.Move_to(xd, yd);
            return 1;
        }
        return 0;
    }

    if(K.GetPosition_x()==xs && K.GetPosition_y()==ys)
    {
        if(K.CanLegalyGoThere(xd, yd) && IsEmpty(xd, yd))
        {
            K.Move_to(xd, yd);
            return 1;
        }
        return 0;
    }

    if(T1.GetPosition_x()==xs && T1.GetPosition_y()==ys)
    {
        if(T1.CanLegalyGoThere(xd, yd) && IsEmpty(xd, yd) && NothingInBetween(xs, ys, xd, yd))
        {
            T1.Move_to(xd, yd);
            return 1;
        }
        return 0;
    }
    if(T2.GetPosition_x()==xs && T2.GetPosition_y()==ys)
    {
        if(T2.CanLegalyGoThere(xd, yd) && IsEmpty(xd, yd) && NothingInBetween(xs, ys, xd, yd))
        {
            T2.Move_to(xd, yd);
            return 1;
        }
        return 0;
    }

    if(H1.GetPosition_x()==xs && H1.GetPosition_y()==ys)
    {
        if(H1.CanLegalyGoThere(xd, yd) && IsEmpty(xd, yd))
        {
            H1.Move_to(xd, yd);
            return 1;
        }
        return 0;
    }
    if(H2.GetPosition_x()==xs && H2.GetPosition_y()==ys)
    {
        if(H2.CanLegalyGoThere(xd, yd) && IsEmpty(xd, yd))
        {
            H2.Move_to(xd, yd);
            return 1;
        }
        return 0;
    }

    if(B1.GetPosition_x()==xs && B1.GetPosition_y()==ys)
    {
        if(B1.CanLegalyGoThere(xd, yd) && IsEmpty(xd, yd) && NothingInBetween(xs, ys, xd, yd))
        {
            B1.Move_to(xd, yd);
            return 1;
        }
        return 0;
    }
    if(B2.GetPosition_x()==xs && B2.GetPosition_y()==ys)
    {
        if(B2.CanLegalyGoThere(xd, yd) && IsEmpty(xd, yd) && NothingInBetween(xs, ys, xd, yd))
        {
            B2.Move_to(xd, yd);
            return 1;
        }
        return 0;
    }

    if(P1.GetPosition_x()==xs && P1.GetPosition_y()==ys)
    {
        if(P1.CanLegalyGoThere(xd, yd, !Enemy->IsEmpty(xs, ys+(1*(colour?1:-1))), !Enemy->IsEmpty(xs, ys+(2*(colour?1:-1))), !Enemy->IsEmpty(xs-(1*(colour?-1:1)), ys+(1*(colour?1:-1))), !Enemy->IsEmpty(xs+(1*(colour?-1:1)), ys+(1*(colour?1:-1)))) && IsEmpty(xd, yd))
        {
            P1.Move_to(xd, yd);
            return 1;
        }
        return 0;
    }
    if(P2.GetPosition_x()==xs && P2.GetPosition_y()==ys)
    {
        if(P2.CanLegalyGoThere(xd, yd, !Enemy->IsEmpty(xs, ys+(1*(colour?1:-1))), !Enemy->IsEmpty(xs, ys+(2*(colour?1:-1))), !Enemy->IsEmpty(xs-(1*(colour?-1:1)), ys+(1*(colour?1:-1))), !Enemy->IsEmpty(xs+(1*(colour?-1:1)), ys+(1*(colour?1:-1)))) && IsEmpty(xd, yd))
        {
            P2.Move_to(xd, yd);
            return 1;
        }
        return 0;
    }
    if(P3.GetPosition_x()==xs && P3.GetPosition_y()==ys)
    {
        if(P3.CanLegalyGoThere(xd, yd, !Enemy->IsEmpty(xs, ys+(1*(colour?1:-1))), !Enemy->IsEmpty(xs, ys+(2*(colour?1:-1))), !Enemy->IsEmpty(xs-(1*(colour?-1:1)), ys+(1*(colour?1:-1))), !Enemy->IsEmpty(xs+(1*(colour?-1:1)), ys+(1*(colour?1:-1)))) && IsEmpty(xd, yd))
        {
            P3.Move_to(xd, yd);
            return 1;
        }
        return 0;
    }
    if(P4.GetPosition_x()==xs && P4.GetPosition_y()==ys)
    {
        if(P4.CanLegalyGoThere(xd, yd, !Enemy->IsEmpty(xs, ys+(1*(colour?1:-1))), !Enemy->IsEmpty(xs, ys+(2*(colour?1:-1))), !Enemy->IsEmpty(xs-(1*(colour?-1:1)), ys+(1*(colour?1:-1))), !Enemy->IsEmpty(xs+(1*(colour?-1:1)), ys+(1*(colour?1:-1)))) && IsEmpty(xd, yd))
        {
            P4.Move_to(xd, yd);
            return 1;
        }
        return 0;
    }
    if(P5.GetPosition_x()==xs && P5.GetPosition_y()==ys)
    {
        if(P5.CanLegalyGoThere(xd, yd, !Enemy->IsEmpty(xs, ys+(1*(colour?1:-1))), !Enemy->IsEmpty(xs, ys+(2*(colour?1:-1))), !Enemy->IsEmpty(xs-(1*(colour?-1:1)), ys+(1*(colour?1:-1))), !Enemy->IsEmpty(xs+(1*(colour?-1:1)), ys+(1*(colour?1:-1)))) && IsEmpty(xd, yd))
        {
            P5.Move_to(xd, yd);
            return 1;
        }
        return 0;
    }
    if(P6.GetPosition_x()==xs && P6.GetPosition_y()==ys)
    {
        if(P6.CanLegalyGoThere(xd, yd, !Enemy->IsEmpty(xs, ys+(1*(colour?1:-1))), !Enemy->IsEmpty(xs, ys+(2*(colour?1:-1))), !Enemy->IsEmpty(xs-(1*(colour?-1:1)), ys+(1*(colour?1:-1))), !Enemy->IsEmpty(xs+(1*(colour?-1:1)), ys+(1*(colour?1:-1)))) && IsEmpty(xd, yd))
        {
            P6.Move_to(xd, yd);
            return 1;
        }
        return 0;
    }
    if(P7.GetPosition_x()==xs && P7.GetPosition_y()==ys)
    {
        if(P7.CanLegalyGoThere(xd, yd, !Enemy->IsEmpty(xs, ys+(1*(colour?1:-1))), !Enemy->IsEmpty(xs, ys+(2*(colour?1:-1))), !Enemy->IsEmpty(xs-(1*(colour?-1:1)), ys+(1*(colour?1:-1))), !Enemy->IsEmpty(xs+(1*(colour?-1:1)), ys+(1*(colour?1:-1)))) && IsEmpty(xd, yd))
        {
            P7.Move_to(xd, yd);
            return 1;
        }
        return 0;
    }
    if(P8.GetPosition_x()==xs && P8.GetPosition_y()==ys)
    {
        if(P8.CanLegalyGoThere(xd, yd, !Enemy->IsEmpty(xs, ys+(1*(colour?1:-1))), !Enemy->IsEmpty(xs, ys+(2*(colour?1:-1))), !Enemy->IsEmpty(xs-(1*(colour?-1:1)), ys+(1*(colour?1:-1))), !Enemy->IsEmpty(xs+(1*(colour?-1:1)), ys+(1*(colour?1:-1)))) && IsEmpty(xd, yd))
        {
            P8.Move_to(xd, yd);
            return 1;
        }
        return 0;
    }

return 0;
}

void Team::MoveBack()
{
    if(Q.GetPosition_x()==xd && Q.GetPosition_y()==yd)
    {
        Q.Move_to(xs, ys);
    }
    if(K.GetPosition_x()==xd && K.GetPosition_y()==yd)
    {
        K.Move_to(xs, ys);
    }
    if(T1.GetPosition_x()==xd && T1.GetPosition_y()==yd)
    {
        T1.Move_to(xs, ys);
    }
    if(T2.GetPosition_x()==xd && T2.GetPosition_y()==yd)
    {
        T2.Move_to(xs, ys);
    }
    if(H1.GetPosition_x()==xd && H1.GetPosition_y()==yd)
    {
        H1.Move_to(xs, ys);
    }
    if(H2.GetPosition_x()==xd && H2.GetPosition_y()==yd)
    {
        H2.Move_to(xs, ys);
    }
    if(B1.GetPosition_x()==xd && B1.GetPosition_y()==yd)
    {
        B1.Move_to(xs, ys);
    }
    if(B2.GetPosition_x()==xd && B2.GetPosition_y()==yd)
    {
        B2.Move_to(xs, ys);
    }

    if(P1.GetPosition_x()==xd && P1.GetPosition_y()==yd)
    {
        P1.Move_to(xs, ys);
    }
    if(P2.GetPosition_x()==xd && P2.GetPosition_y()==yd)
    {
        P2.Move_to(xs, ys);
    }
    if(P3.GetPosition_x()==xd && P3.GetPosition_y()==yd)
    {
        P3.Move_to(xs, ys);
    }
    if(P4.GetPosition_x()==xd && P4.GetPosition_y()==yd)
    {
        P4.Move_to(xs, ys);
    }
    if(P5.GetPosition_x()==xd && P5.GetPosition_y()==yd)
    {
        P5.Move_to(xs, ys);
    }
    if(P6.GetPosition_x()==xd && P6.GetPosition_y()==yd)
    {
        P6.Move_to(xs, ys);
    }
    if(P7.GetPosition_x()==xd && P7.GetPosition_y()==yd)
    {
        P7.Move_to(xs, ys);
    }
    if(P8.GetPosition_x()==xd && P8.GetPosition_y()==yd)
    {
        P8.Move_to(xs, ys);
    }
}

bool Team::NothingInBetween(int Xsource, int Ysource, int Xdestination, int Ydestination)
{
    if(Xsource==Xdestination)
    {
        if(Ydestination>Ysource)
        {
            for(int i=Ysource+1; i<Ydestination; i++)        //Down
            {
                if(!Enemy->IsEmpty(Xsource, i) || !IsEmpty(Xsource, i))
                {
                    return 0;
                }
            }
        }
        if(Ydestination<Ysource)
        {
            for(int i=Ysource-1; i>Ydestination; i--)        //Up
            {
                if(!Enemy->IsEmpty(Xsource, i) || !IsEmpty(Xsource, i))
                {
                    return 0;
                }
            }
        }
    }
    if(Ysource==Ydestination)
    {
        if(Xdestination>Xsource)
        {
            for(int i=Xsource+1; i<Xdestination; i++)
            {
                if(!Enemy->IsEmpty(i, Ysource) || !IsEmpty(i, Ysource))
                {
                    return 0;
                }
            }
        }
        if(Xdestination<Xsource)
        {
            for(int i=Xsource-1; i>Xdestination; i--)
            {
                if(!Enemy->IsEmpty(i, Ysource) || !IsEmpty(i, Ysource))
                {
                    return 0;
                }
            }

        }
    }
    if(Ysource>Ydestination && Xsource>Xdestination)
    {
        for(int i=1; i<Xsource-Xdestination; i++)
        {
            if(!Enemy->IsEmpty(Xsource-i, Ysource-i) || !IsEmpty(Xsource-i, Ysource-i))
            {
                return 0;
            }
        }
    }
    if(Ysource<Ydestination && Xsource<Xdestination)
    {
        for(int i=1; i<Xdestination-Xsource; i++)
        {
            if(!Enemy->IsEmpty(Xsource+i, Ysource+i) || !IsEmpty(Xsource+i, Ysource+i))
            {
                return 0;
            }
        }
    }
    if(Ysource>Ydestination && Xsource<Xdestination)
    {
        for(int i=1; i<Xdestination-Xsource; i++)
        {
            if(!Enemy->IsEmpty(Xsource+i, Ysource-i) || !IsEmpty(Xsource+i, Ysource-i))
            {
                return 0;
            }
        }
    }
    if(Ysource<Ydestination && Xsource>Xdestination)
    {
        for(int i=1; i<Xsource-Xdestination; i++)
        {
            if(!Enemy->IsEmpty(Xsource-i, Ysource+i) || !IsEmpty(Xsource-i, Ysource+i))
            {
                return 0;
            }
        }
    }

    return 1;
}

bool Team::CheckForCheck()
{
    return Enemy->FieldUnderAttack(KingX(), KingY());
}

bool Team::FieldUnderAttack(int x, int y)
{
    if(Q.CanLegalyGoThere(x, y) && NothingInBetween(Q.GetPosition_x(), Q.GetPosition_y(), x, y))
    {
        return 1;
    }
    if(K.CanLegalyGoThere(x, y))
    {
        return 1;
    }
    if(T1.CanLegalyGoThere(x, y) && NothingInBetween(T1.GetPosition_x(), T1.GetPosition_y(), x, y))
    {
        return 1;
    }
    if(T2.CanLegalyGoThere(x, y) && NothingInBetween(T2.GetPosition_x(), T2.GetPosition_y(), x, y))
    {
        return 1;
    }
    if(H1.CanLegalyGoThere(x, y))
    {
        return 1;
    }
    if(H2.CanLegalyGoThere(x, y))
    {
        return 1;
    }
    if(B1.CanLegalyGoThere(x, y) && NothingInBetween(B1.GetPosition_x(), B1.GetPosition_y(), x, y))
    {
        return 1;
    }
    if(B2.CanLegalyGoThere(x, y) && NothingInBetween(B2.GetPosition_x(), B2.GetPosition_y(), x, y))
    {
        return 1;
    }


    bool EnFr, EnFr2, EnDiLe, EnDiRi;
    EnFr=!Enemy->IsEmpty(P1.GetPosition_x(), P1.GetPosition_y()+(1*(colour?1:-1)));
    EnFr2=!Enemy->IsEmpty(P1.GetPosition_x(), P1.GetPosition_y()+(2*(colour?1:-1)));
    EnDiLe=!Enemy->IsEmpty(P1.GetPosition_x()-1, P1.GetPosition_y()+(1*(colour?1:-1)));
    EnDiRi=!Enemy->IsEmpty(P1.GetPosition_x()+1, P1.GetPosition_y()+(1*(colour?1:-1)));

    if(P1.CanLegalyGoThere(x, y, EnFr, EnFr2, EnDiLe, EnDiRi))
    {
        return 1;
    }

    EnFr=!Enemy->IsEmpty(P2.GetPosition_x(), P2.GetPosition_y()+(1*(colour?1:-1)));
    EnFr2=!Enemy->IsEmpty(P2.GetPosition_x(), P2.GetPosition_y()+(2*(colour?1:-1)));
    EnDiLe=!Enemy->IsEmpty(P2.GetPosition_x()-1, P2.GetPosition_y()+(1*(colour?1:-1)));
    EnDiRi=!Enemy->IsEmpty(P2.GetPosition_x()+1, P2.GetPosition_y()+(1*(colour?1:-1)));
    if(P2.CanLegalyGoThere(x, y, EnFr, EnFr2, EnDiLe, EnDiRi))
    {
        return 1;
    }

    EnFr=!Enemy->IsEmpty(P3.GetPosition_x(), P3.GetPosition_y()+(1*(colour?1:-1)));
    EnFr2=!Enemy->IsEmpty(P3.GetPosition_x(), P3.GetPosition_y()+(2*(colour?1:-1)));
    EnDiLe=!Enemy->IsEmpty(P3.GetPosition_x()-1, P3.GetPosition_y()+(1*(colour?1:-1)));
    EnDiRi=!Enemy->IsEmpty(P3.GetPosition_x()+1, P3.GetPosition_y()+(1*(colour?1:-1)));
    if(P3.CanLegalyGoThere(x, y, EnFr, EnFr2, EnDiLe, EnDiRi))
    {
        return 1;
    }

    EnFr=!Enemy->IsEmpty(P4.GetPosition_x(), P4.GetPosition_y()+(1*(colour?1:-1)));
    EnFr2=!Enemy->IsEmpty(P4.GetPosition_x(), P4.GetPosition_y()+(2*(colour?1:-1)));
    EnDiLe=!Enemy->IsEmpty(P4.GetPosition_x()-1, P4.GetPosition_y()+(1*(colour?1:-1)));
    EnDiRi=!Enemy->IsEmpty(P4.GetPosition_x()+1, P4.GetPosition_y()+(1*(colour?1:-1)));
    if(P4.CanLegalyGoThere(x, y, EnFr, EnFr2, EnDiLe, EnDiRi))
    {
        return 1;
    }

    EnFr=!Enemy->IsEmpty(P5.GetPosition_x(), P5.GetPosition_y()+(1*(colour?1:-1)));
    EnFr2=!Enemy->IsEmpty(P5.GetPosition_x(), P5.GetPosition_y()+(2*(colour?1:-1)));
    EnDiLe=!Enemy->IsEmpty(P5.GetPosition_x()-1, P5.GetPosition_y()+(1*(colour?1:-1)));
    EnDiRi=!Enemy->IsEmpty(P5.GetPosition_x()+1, P5.GetPosition_y()+(1*(colour?1:-1)));
    if(P5.CanLegalyGoThere(x, y, EnFr, EnFr2, EnDiLe, EnDiRi))
    {
        return 1;
    }

    EnFr=!Enemy->IsEmpty(P6.GetPosition_x(), P6.GetPosition_y()+(1*(colour?1:-1)));
    EnFr2=!Enemy->IsEmpty(P6.GetPosition_x(), P6.GetPosition_y()+(2*(colour?1:-1)));
    EnDiLe=!Enemy->IsEmpty(P6.GetPosition_x()-1, P6.GetPosition_y()+(1*(colour?1:-1)));
    EnDiRi=!Enemy->IsEmpty(P6.GetPosition_x()+1, P6.GetPosition_y()+(1*(colour?1:-1)));
    if(P6.CanLegalyGoThere(x, y, EnFr, EnFr2, EnDiLe, EnDiRi))
    {
        return 1;
    }

    EnFr=!Enemy->IsEmpty(P7.GetPosition_x(), P7.GetPosition_y()+(1*(colour?1:-1)));
    EnFr2=!Enemy->IsEmpty(P7.GetPosition_x(), P7.GetPosition_y()+(2*(colour?1:-1)));
    EnDiLe=!Enemy->IsEmpty(P7.GetPosition_x()-1, P7.GetPosition_y()+(1*(colour?1:-1)));
    EnDiRi=!Enemy->IsEmpty(P7.GetPosition_x()+1, P7.GetPosition_y()+(1*(colour?1:-1)));
    if(P7.CanLegalyGoThere(x, y, EnFr, EnFr2, EnDiLe, EnDiRi))
    {
        return 1;
    }

    EnFr=!Enemy->IsEmpty(P8.GetPosition_x(), P8.GetPosition_y()+(1*(colour?1:-1)));
    EnFr2=!Enemy->IsEmpty(P8.GetPosition_x(), P8.GetPosition_y()+(2*(colour?1:-1)));
    EnDiLe=!Enemy->IsEmpty(P8.GetPosition_x()-1, P8.GetPosition_y()+(1*(colour?1:-1)));
    EnDiRi=!Enemy->IsEmpty(P8.GetPosition_x()+1, P8.GetPosition_y()+(1*(colour?1:-1)));
    if(P8.CanLegalyGoThere(x, y, EnFr, EnFr2, EnDiLe, EnDiRi))
    {
        return 1;
    }

    return 0;
}

int Team::KingX()
{
    return K.GetPosition_x();
}

int Team::KingY()
{
    return K.GetPosition_y();
}

void Team::draw(sf::RenderWindow &window)
{
    Q.draw(window);
    K.draw(window);
    H1.draw(window);
    H2.draw(window);
    T1.draw(window);
    T2.draw(window);
    B1.draw(window);
    B2.draw(window);
    P1.draw(window);
    P2.draw(window);
    P3.draw(window);
    P4.draw(window);
    P5.draw(window);
    P6.draw(window);
    P7.draw(window);
    P8.draw(window);
}
