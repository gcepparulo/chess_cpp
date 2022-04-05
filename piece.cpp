// Gabriele Cepparulo
// Final Project
// Abstract base class for piece.


#include "piece.h"
#include<iostream>

//Overloading output stream
std::ostream& operator<<(std::ostream& os, Piece &p) 
{  
    p.printFunction();
    return os;
}

//Print function, to print an empty space when
// the piece has not been assigned to any type.
void Piece::printFunction()
{
    std::cout<<" ";
}


// Overloading assignment operator for deep copying
Piece & Piece::operator=(Piece &p)
{
  if(&p == this) return *this;
  type=p.getType();
  colour=p.getColour();
  return *this; 
}