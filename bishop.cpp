// Gabriele Cepparulo
// Final Project
// Derived class for bishop.

#include "bishop.h"
#include<iostream>
#include<cctype>

//Parametrised constructor.
Bishop::Bishop(char colour_in): Piece(colour_in, BISHOP) {}

//Overridden function to get colour of bishop
char Bishop::getColour() 
{
    return colour;
}

//Overridden function to get bishop type.
char Bishop::getType() 
{
    return type;
}

//Overridden function to print bishop on the board.
void Bishop::printFunction()
{   
    if(colour == WHITE_PIECE){
        std::cout<< WHITE_BISHOP;
    }
    else{
        std::cout<< BLACK_BISHOP;
    }

}

//Overridden function to get allowed moves for a bishop.
//Takes as inputs: an array containing piece pointers
//and the position of the bishop.
//Bishop can move diagonally by unlimited spaces.
//Bishop cannot jump over pieces.
//This function keeps adding valid moves in a given direction
//(for all diagonal directions) until it encounters an occupied spot.
std::vector<pos> Bishop::validMoves(Piece* board[RANKS][FILES], pos start_pos)
{   
    std::vector<pos> valid_moves;
    pos check_pos;

    check_pos = start_pos + UP + RIGHT;
    while(check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
        if(board[check_pos.getY()][check_pos.getX()] == nullptr){
            valid_moves.push_back(check_pos);
        }
        //The bishop can not continue in a given direction after it encounters a piece.
        else if(board[check_pos.getY()][check_pos.getX()] != nullptr){
            if( board[check_pos.getY()][check_pos.getX()]->getColour()!=board[start_pos.getY()][start_pos.getX()]->getColour() ){
                valid_moves.push_back(check_pos);
            }
            break;
        }        
        check_pos = check_pos + UP + RIGHT;
    }

    check_pos = start_pos + DOWN + RIGHT;
    while(check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
        if(board[check_pos.getY()][check_pos.getX()] == nullptr){
            valid_moves.push_back(check_pos);
        }
        //The bishop can not continue in a given direction after it encounters a piece.
        else if(board[check_pos.getY()][check_pos.getX()] != nullptr){
            if( board[check_pos.getY()][check_pos.getX()]->getColour()!=board[start_pos.getY()][start_pos.getX()]->getColour() ){
                valid_moves.push_back(check_pos);
            }
            break;
        }        
        check_pos = check_pos + DOWN + RIGHT;
    }

    check_pos = start_pos + UP + LEFT;
    while(check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
        if(board[check_pos.getY()][check_pos.getX()] == nullptr){
            valid_moves.push_back(check_pos);
        }
        //The bishop can not continue in a given direction after it encounters a piece.
        else if(board[check_pos.getY()][check_pos.getX()] != nullptr){
            if( board[check_pos.getY()][check_pos.getX()]->getColour()!=board[start_pos.getY()][start_pos.getX()]->getColour() ){
                valid_moves.push_back(check_pos);
            }
            break;
        }        
        check_pos = check_pos + UP + LEFT;
    }

    check_pos = start_pos + DOWN + LEFT;
    while(check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
        if(board[check_pos.getY()][check_pos.getX()] == nullptr){
            valid_moves.push_back(check_pos);
        }
        //The bishop can not continue in a given direction after it encounters a piece.
        else if(board[check_pos.getY()][check_pos.getX()] != nullptr){
            if( board[check_pos.getY()][check_pos.getX()]->getColour()!=board[start_pos.getY()][start_pos.getX()]->getColour() ){
                valid_moves.push_back(check_pos);
            }
            break;
        }        
        check_pos = check_pos + DOWN + LEFT;
    }   

    return valid_moves;
}
