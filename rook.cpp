// Gabriele Cepparulo
// Final Project
// Derived class for knight.
#include "rook.h"
#include<iostream>
#include<cctype>

//Parametrised constructor.
Rook::Rook(char colour_in): Piece(colour_in, ROOK) {}

//Overridden function to get colour of rook.
char Rook::getColour() 
{
    return colour;
}

//Overridden function to get rook type.
char Rook::getType() 
{
    return type;
}

//Overridden function to print knight on the board.
void Rook::printFunction()
{   
    if(colour == WHITE_PIECE){
        std::cout<< WHITE_ROOK;
    }
    else{
        std::cout<< BLACK_ROOK;
    }

}

//Overridden function to get allowed moves for a knight.
//Takes as inputs: an array containing piece pointers
//and the position of the knight.
//Rook can move horizontally and vertically by unlimited spaces.
//Rook cannot jump over pieces.
//This function keeps adding valid moves in a given direction
//(UP, DOWN, LEFT, RIGHT) until it encounters an occupied spot.
std::vector<pos> Rook::validMoves(Piece* board[RANKS][FILES], pos start_pos)
{   
    std::vector<pos> valid_moves;
    pos check_pos{0,0};

    check_pos = start_pos + UP;
    while(check_pos.getY()<RANKS && check_pos.getY()>=0){
        if(board[check_pos.getY()][check_pos.getX()] == nullptr){
            valid_moves.push_back(check_pos);
        }
        else if(board[check_pos.getY()][check_pos.getX()] != nullptr){
            if( board[check_pos.getY()][check_pos.getX()]->getColour()!=board[start_pos.getY()][start_pos.getX()]->getColour() ){
                valid_moves.push_back(check_pos);
            }
            break;
        }        
        check_pos = check_pos + UP;
    }

    check_pos = start_pos + DOWN;
    while(check_pos.getY()<RANKS && check_pos.getY()>=0){
        if(board[check_pos.getY()][check_pos.getX()] == nullptr){
            valid_moves.push_back(check_pos);
        }
        else if(board[check_pos.getY()][check_pos.getX()] != nullptr){
            if( board[check_pos.getY()][check_pos.getX()]->getColour()!=board[start_pos.getY()][start_pos.getX()]->getColour() ){
                valid_moves.push_back(check_pos);
            }
            break;
        }        
        check_pos = check_pos + DOWN;
    }

    check_pos = start_pos + LEFT;
    while(check_pos.getX()<FILES && check_pos.getX()>=0){
        if(board[check_pos.getY()][check_pos.getX()] == nullptr){
            valid_moves.push_back(check_pos);
        }
        else if(board[check_pos.getY()][check_pos.getX()] != nullptr){
            if( board[check_pos.getY()][check_pos.getX()]->getColour()!=board[start_pos.getY()][start_pos.getX()]->getColour() ){
                valid_moves.push_back(check_pos);
            }
            break;
        }        
        check_pos = check_pos + LEFT;
    }

    check_pos = start_pos + RIGHT;
    while(check_pos.getX()<FILES && check_pos.getX()>=0){
        if(board[check_pos.getY()][check_pos.getX()] == nullptr){
            valid_moves.push_back(check_pos);
        }
        else if(board[check_pos.getY()][check_pos.getX()] != nullptr){
            if( board[check_pos.getY()][check_pos.getX()]->getColour()!=board[start_pos.getY()][start_pos.getX()]->getColour() ){
                valid_moves.push_back(check_pos);
            }
            break;
        }        
        check_pos = check_pos + RIGHT;
    }
    return valid_moves;
}
