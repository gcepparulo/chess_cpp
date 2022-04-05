// Final Project
// Class for position coordinate.
// Gabriele Cepparulo

#include "pos.h"

//Parametrised constructor.
pos::pos(int x_in, int y_in): x(x_in), y(y_in) {}

//Functions to get x and y coordinates
int pos::getX() const
{
    return x;
}
int pos::getY() const
{
    return y;
}

//Functions to set x and y coordinates
void pos::setX(int i) 
{
    x = i;
}
void pos::setY(int j) 
{
    y = j;
}

// Assignment operator for deep copying
pos& pos::operator=(const pos &p)
{
    if(&p == this) return *this;
    x=p.getX();
    y=p.getY();
    return *this; 
}

//Overloading addition operator
pos pos::operator+(const pos &p) const
{
    pos temp{x + p.getX(), y + p.getY()};
    return temp;
}

//Overloading * operator for multiplication between pos and integer
const pos pos::operator*(int i) const
{
    pos temp{x * i, y * i};
    return temp;
}



