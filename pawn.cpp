// Gabriele Cepparulo
// Final Project
// Derived class for pawn.

#include "pawn.h"
#include<iostream>
#include<cctype>

//Parametrised constructor.
Pawn::Pawn(char colour_in): Piece(colour_in, PAWN) {}

//Overridden function to get colour of pawn
char Pawn::getColour() 
{
    return colour;
}

//Overridden function to get pawn type.
char Pawn::getType() 
{
    return type;
}

//Overridden function to print pawn on the board.
void Pawn::printFunction()
{   
    if(colour == WHITE_PIECE){
        std::cout<< WHITE_PAWN;
    }
    else{
        std::cout<< BLACK_PAWN;
    }

}

//Overridden function to get allowed moves for a pawn.
//Takes as inputs: an array containing piece pointers
//and the position of the pawn.
std::vector<pos> Pawn::validMoves(Piece* board[RANKS][FILES], pos start_pos)
{   
    //Creating an empty vector of coordinates to append all allowed moves.
    std::vector<pos> valid_moves;
    pos check_pos;

    //Pawns can only move forward, so allowed moves are different based on colour.
    if( board[start_pos.getY()][start_pos.getX()]->getColour() == WHITE_PIECE){
        //Pawns can move up if the space is empty.
        check_pos = start_pos + UP;
        if(board[check_pos.getY()][check_pos.getX()] == nullptr && check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
            valid_moves.push_back(check_pos);
        }
        //Pawns can move up by two spaces if it's their first move.
        if(start_pos.getY() == 6){
            if(board[check_pos.getY()][check_pos.getX()] == nullptr && check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
                check_pos = check_pos + UP;
                if(board[check_pos.getY()][check_pos.getX()] == nullptr && check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
                    valid_moves.push_back(check_pos);
                }
            }
        }
        //Pawns can only capture diagonally.
        check_pos = start_pos + UP + RIGHT;
        if(board[check_pos.getY()][check_pos.getX()] != nullptr && (board[check_pos.getY()][check_pos.getX()])->getColour() != (board[start_pos.getY()][start_pos.getX()])->getColour() && check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
            valid_moves.push_back(check_pos);
        }

        check_pos = start_pos + UP + LEFT;
        if(board[check_pos.getY()][check_pos.getX()] != nullptr && (board[check_pos.getY()][check_pos.getX()])->getColour() != (board[start_pos.getY()][start_pos.getX()])->getColour() && check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
            valid_moves.push_back(check_pos);
        }
    }else{

        check_pos = start_pos + DOWN;
        if(board[check_pos.getY()][check_pos.getX()] == nullptr && check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
            valid_moves.push_back(check_pos);
        }

        if(start_pos.getY() == 1){
            if(board[check_pos.getY()][check_pos.getX()] == nullptr && check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
                check_pos = check_pos + DOWN;
                if(board[check_pos.getY()][check_pos.getX()] == nullptr && check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
                    valid_moves.push_back(check_pos);
                }
            }
        }

        check_pos = start_pos + DOWN + RIGHT;
        if(board[check_pos.getY()][check_pos.getX()] != nullptr && (board[check_pos.getY()][check_pos.getX()])->getColour() != (board[start_pos.getY()][start_pos.getX()])->getColour() && check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
            valid_moves.push_back(check_pos);
        }

        check_pos = start_pos + DOWN + LEFT;
        if(board[check_pos.getY()][check_pos.getX()] != nullptr && (board[check_pos.getY()][check_pos.getX()])->getColour() != (board[start_pos.getY()][start_pos.getX()])->getColour() && check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
            valid_moves.push_back(check_pos);
        }       
    }
    return valid_moves;
}

