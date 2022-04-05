// Gabriele Cepparulo
// Final Project
// Class for position coordinates.
// This class has private members for x and y coordinates,
// default and parametrised constructor, a destructor and 
// overridden functions to get and to set coordinates.
// The following operators are overloaded: assignment,
// comparison, addition and multiplicaiton (by integer).
#ifndef POS_H
#define POS_H

class pos
{
private:
    int x,y;
public:
    pos(): x(-1), y(-1) {}
    pos(int x_in, int y_in);
    ~pos(){}
    int getX() const;
    int getY() const;
    void setX(int i);
    void setY(int j);
    pos& operator=(const pos& p);
    bool operator==(const pos & p) const { return x==p.x && y==p.y;}
    pos operator+(const pos &p) const;
    const pos operator*(int i) const;
};

#endif
