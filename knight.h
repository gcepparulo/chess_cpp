// Gabriele Cepparulo
// Final Project
// Derived class for knight.
// This class has private members for colour and type, a
// parametrised constructor, a destructor, overridden 
// functions to get the piece colour, type, valid moves.
// The << operator is overloaded to print the board, 
// it involves a print function which is overridden.
#ifndef KNIGHT_H
#define KNIGHT_H

#include "constants.h"
#include "pos.h"
#include "piece.h"
#include <iostream>
#include <array>
#include <vector>


class Knight: public Piece{
public:
    Knight(char colour_in);
    ~Knight(){};
    char getColour();
    char getType();
    void printFunction();
    std::vector<pos> validMoves(Piece* board[RANKS][FILES], pos start_pos);
};

#endif