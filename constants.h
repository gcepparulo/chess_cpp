// Gabriele Cepparulo
// Final Project
// Header file containing constants.
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "pos.h"
#include <array>
#include <string>


const int RANKS = 8; //rows
const int FILES = 8; //columns
//characters for white and black colours
const char WHITE_PIECE = 'w';
const char BLACK_PIECE = 'b';
//characters for different pieces.
const char PAWN = 'p';
const char ROOK = 'r';
const char BISHOP = 'b';
const char QUEEN = 'q';
const char KNIGHT = 'n';
const char KING = 'k';
//output string for colours.
const std::string white = "White";
const std::string black = "Black";
//output format of pieces when printing board.
const std::string WHITE_PAWN = "♟";
const std::string BLACK_PAWN = "♙";
const std::string WHITE_ROOK = "♜";
const std::string BLACK_ROOK = "♖";
const std::string WHITE_BISHOP = "♝";
const std::string BLACK_BISHOP = "♗";
const std::string WHITE_QUEEN = "♛";
const std::string BLACK_QUEEN = "♕";
const std::string WHITE_KNIGHT = "♞";
const std::string BLACK_KNIGHT = "♘";
const std::string WHITE_KING = "♚";
const std::string BLACK_KING = "♔";
//integers to indicate in main function wether game
//is still playing, or it is finished in checkmate;
//or stalemate, or if a move has to be repeated.
const int GAMEON = 0;
const int CHECKMATE = 1;
const int STALEMATE = 2;
const int REPEATMOVE = 3;
//constant vectors for 4 directions
const pos UP {0,-1}; //move array by one space in upward direction
const pos DOWN {0,1}; //move array by one space in downward direction
const pos RIGHT {1,0}; //move array by one space in rightward direction
const pos LEFT {-1,0}; //move array by one space in leftward direction


#endif