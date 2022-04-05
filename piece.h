// Gabriele Cepparulo
// Final Project
// Abstract base class for piece.
// This class has private members for colour and type.
// Virtual functions to get the piece colour, type, valid moves,
// in the case that the piece is a king to return if it is in check.
// The assignment operator is overloaded, in order to change a piece 
// to a different one when a move is made. 
// The << operator is overloaded to print the board, it involves a print 
// function which is virtual in order to make the operator different 
// for each derived piece class.
#ifndef PIECE_H
#define PIECE_H

#include "pos.h"
#include "constants.h"
#include<iostream>
#include<vector>
#include<array>


class Piece
{

friend std::ostream & operator<<(std::ostream &os,  Piece &p);
protected:
  char colour, type;
  Piece(char colour_in, char type_in) : colour(colour_in), type(type_in) {} 
public:
  virtual ~Piece(){} 
  virtual char getColour() =0;
  virtual char getType()=0;
  virtual std::vector<pos> validMoves(Piece* board[RANKS][FILES], pos start_pos)=0;
  virtual void printFunction();
  Piece& operator=(Piece&);
};

std::ostream& operator<<(std::ostream& os, Piece &p);

#endif