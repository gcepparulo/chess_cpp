// Gabriele Cepparulo
// Final Project
// Derived class for king.
// This class has private members for colour and type, a
// parametrised constructor, a destructor, overridden 
// functions to get the piece colour, type, valid moves.
// The << operator is overloaded to print the board, 
// it involves a print function which is overridden.
#ifndef KING_H
#define KING_H

#include "constants.h"
#include "pos.h"
#include "piece.h"
#include <iostream>
#include <array>
#include <vector>


class King: public Piece{
public:
    King(char colour_in);
    ~King(){};
    char getColour();
    char getType();
    void printFunction();
    bool kingToCheck(Piece* board[RANKS][FILES], pos from, pos to,  const char kingcolour);
    std::vector<pos> validMoves(Piece* board[RANKS][FILES], pos start_pos);
};

#endif