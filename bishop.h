// Gabriele Cepparulo
// Final Project
// Derived class for bishop.
// This class has private members for colour and type, a
// parametrised constructor, a destructor, overridden 
// functions to get the piece colour, type, valid moves.
// The << operator is overloaded to print the board, 
// it involves a print function which is overridden.
#ifndef BISHOP_H
#define BISHOP_H

#include "constants.h"
#include "pos.h"
#include "piece.h"
#include <iostream>
#include <array>
#include <vector>


class Bishop: public Piece{
public:
    Bishop(char colour_in);
    ~Bishop(){};
    char getColour();
    char getType();
    void printFunction();
    std::vector<pos> validMoves(Piece* board[RANKS][FILES], pos start_pos);
};

#endif