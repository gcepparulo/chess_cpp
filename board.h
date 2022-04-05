// Gabriele Cepparulo
// Final Project
// Derived class for board.
// This class has private members for: position of 
// white and black king (which is updated when moved),
// a bool to keep track of whose turn it is, a bool
// to see if each of the players is in check.
// The board also contains an array of base piece pointers
// which is updated as the game moves on, and a string stream
// that keeps track of all moves in the game.   
// This class contains a default  constructor, a destructor,
// functions to get private members, functions to convert
// between string input and class pos (coordinates), 
// function to make a move, function to display the board,
// function to save game history to .txt file.
// The () operator is overloaded to select a piece from the array, 
// the assignment operator is overloaded (for creating virtual boards).

#ifndef BOARD_H
#define BOARD_H

#include "pos.h"
#include "constants.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "knight.h"
#include "king.h"
#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>
#include <sstream>

class board
{
private:
    pos white_king_pos{4,7};
    pos black_king_pos{4,0};
    bool whites_turn = true;
    bool white_in_check = false;
    bool black_in_check = false;
public:
    Piece* board_array[RANKS][FILES];
    std::stringstream game_history;
    //default constructor, assigns the pieces 
    //to their default positions in the array
    //empty spaces are null pointers.
    board()
    {
        for(int f=0; f<FILES; f++){
            board_array[1][f] = new Pawn{BLACK_PIECE};
        }
        board_array[0][0] = new Rook{BLACK_PIECE};
        board_array[0][7] = new Rook{BLACK_PIECE};
        board_array[0][1] = new Knight{BLACK_PIECE};
        board_array[0][6] = new Knight{BLACK_PIECE};
        board_array[0][2] = new Bishop{BLACK_PIECE};
        board_array[0][5] = new Bishop{BLACK_PIECE};
        board_array[0][3] = new Queen{BLACK_PIECE};
        board_array[0][4] = new King{BLACK_PIECE};

        for(int f=0; f<FILES; f++){
            board_array[6][f] = new Pawn{WHITE_PIECE};
        }
        board_array[7][0] = new Rook{WHITE_PIECE};
        board_array[7][7] = new Rook{WHITE_PIECE};
        board_array[7][1] = new Knight{WHITE_PIECE};
        board_array[7][6] = new Knight{WHITE_PIECE};
        board_array[7][2] = new Bishop{WHITE_PIECE};
        board_array[7][5] = new Bishop{WHITE_PIECE};
        board_array[7][3] = new Queen{WHITE_PIECE};
        board_array[7][4] = new King{WHITE_PIECE};

        for(int r=2; r<RANKS-2; r++){
            for(int f=0; f<FILES; f++){
                board_array[r][f] = nullptr;
            }
        }   
    }
    ~board(){}
    Piece* operator()(int i, int j);
    board& operator=( board& b);
    void printBoard();
    pos str2pos(std::string input_str);
    std::array<char,2> pos2char(pos inputPos);
    int makeMove(std::string from_in, std::string to_in);
    bool getTurn() {return whites_turn;}
    int isGameOver(char opponent_colour);
    pos getKingPos(char colour);
    bool isWhiteInCheck() {return white_in_check;}
    bool isBlackInCheck() {return black_in_check;}
    void virtualMove(pos from, pos to);
    std::string printColour();
    void clearBoard();
    void saveMove(std::string from_in, std::string to_in);
    void saveHistory(std::string file_name);
};

#endif