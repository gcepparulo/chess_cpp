// Gabriele Cepparulo
// Final Project
// Derived class for knight.

#include "knight.h"
#include<iostream>
#include<cctype>

//Parametrised constructor.
Knight::Knight(char colour_in): Piece(colour_in, KNIGHT) {}


//Overridden function to get colour of knight.
char Knight::getColour() 
{
    return colour;
}

//Overridden function to get knight type.
char Knight::getType() 
{
    return type;
}

//Overridden function to print knight on the board.
void Knight::printFunction()
{   
    if(colour == WHITE_PIECE){
        std::cout<< WHITE_KNIGHT;
    }
    else{
        std::cout<< BLACK_KNIGHT;
    }

}

//Overridden function to get allowed moves for a knight.
//Takes as inputs: an array containing piece pointers
//and the position of the knight.
//Knight can move in an 'L' shape:
// - 2 spaces vertically and 1 horizontally
// - 2 spaces horizontally and 1 vertically
//Knight can jump over pieces.
//This function checks if that the spot on the 
//board is empty or occupied by a different
//colour piece.
std::vector<pos> Knight::validMoves(Piece* board[RANKS][FILES], pos start_pos)
{   
    std::vector<pos> all_moves;
    std::vector<pos> valid_moves;
    pos check_pos;

    check_pos = start_pos + UP*2 + LEFT;
    all_moves.push_back(check_pos);
    check_pos = start_pos + UP*2 + RIGHT;
    all_moves.push_back(check_pos);
    check_pos = start_pos + DOWN*2 + LEFT;
    all_moves.push_back(check_pos);
    check_pos = start_pos + DOWN*2 + RIGHT;
    all_moves.push_back(check_pos);
    check_pos = start_pos + RIGHT*2 + UP;
    all_moves.push_back(check_pos);
    check_pos = start_pos + RIGHT*2 + DOWN;
    all_moves.push_back(check_pos);
    check_pos = start_pos + LEFT*2 + UP;
    all_moves.push_back(check_pos);
    check_pos = start_pos + LEFT*2 + DOWN;
    all_moves.push_back(check_pos);

    //Add move to the allowed moves if it is within board and it is not occupied by a piece of the same colour.
    for(auto it = all_moves.begin(); it!=all_moves.end(); it++){
        if( (*it).getY()<RANKS && (*it).getY()>=0 && (*it).getX()<FILES && (*it).getX()>=0){
            if(board[(*it).getY()][(*it).getX()] != nullptr && board[start_pos.getY()][start_pos.getX()]->getColour() != (board[(*it).getY()][(*it).getX()])->getColour()){
                valid_moves.push_back(*it);
            }else if(board[(*it).getY()][(*it).getX()] == nullptr){
                valid_moves.push_back(*it);
            }
        }
    }
    return valid_moves;
}