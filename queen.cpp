// Gabriele Cepparulo
// Final Project
// Derived class for queen.

#include "queen.h"
#include<iostream>
#include<cctype>

//Parametrised constructor.
Queen::Queen(char colour_in): Piece(colour_in, QUEEN) {}

//Overridden function to get colour of queen
char Queen::getColour() 
{
    return colour;
}

//Overridden function to get queen type.
char Queen::getType() 
{
    return type;
}

//Overridden function to print queen on the board.
void Queen::printFunction()
{   
    if(colour == WHITE_PIECE){
        std::cout<< WHITE_QUEEN;
    }
    else{
        std::cout<< BLACK_QUEEN;
    }

}

//Overridden function to get allowed moves for a queen.
//Takes as inputs: an array containing piece pointers
//and the position of the queen.
//Queen can move in any direction by unlimited spaces.
//Queen cannot jump over pieces.
//This function keeps adding valid moves in a given direction
//(for every direction) until it encounters an occupied spot.
//(essentially combines rook and bishop)
std::vector<pos> Queen::validMoves(Piece* board[RANKS][FILES], pos start_pos)
{   
    std::vector<pos> valid_moves;
    pos check_pos;

    //Keep going up until a piece is encountered or the board ends.
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

    //Keep going down until a piece is encountered or the board ends.
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

    //Keep going left until a piece is encountered or the board ends.
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

    //Keep going right until a piece is encountered or the board ends.
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

    //Keep going diagonally until a piece is encountered or the board ends.
    check_pos = start_pos + UP + RIGHT;
    while(check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
        if(board[check_pos.getY()][check_pos.getX()] == nullptr){
            valid_moves.push_back(check_pos);
        }
        else if(board[check_pos.getY()][check_pos.getX()] != nullptr){
            if( board[check_pos.getY()][check_pos.getX()]->getColour()!=board[start_pos.getY()][start_pos.getX()]->getColour() ){
                valid_moves.push_back(check_pos);
            }
            break;
        }        
        check_pos = check_pos + UP + RIGHT;
    }

    //Keep going diagonally until a piece is encountered or the board ends.
    check_pos = start_pos + DOWN + RIGHT;
    while(check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
        if(board[check_pos.getY()][check_pos.getX()] == nullptr){
            valid_moves.push_back(check_pos);
        }
        else if(board[check_pos.getY()][check_pos.getX()] != nullptr){
            if( board[check_pos.getY()][check_pos.getX()]->getColour()!=board[start_pos.getY()][start_pos.getX()]->getColour() ){
                valid_moves.push_back(check_pos);
            }
            break;
        }        
        check_pos = check_pos + DOWN + RIGHT;
    }

    //Keep going diagonally until a piece is encountered or the board ends.
    check_pos = start_pos + UP + LEFT;
    while(check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
        if(board[check_pos.getY()][check_pos.getX()] == nullptr){
            valid_moves.push_back(check_pos);
        }
        else if(board[check_pos.getY()][check_pos.getX()] != nullptr){
            if( board[check_pos.getY()][check_pos.getX()]->getColour()!=board[start_pos.getY()][start_pos.getX()]->getColour() ){
                valid_moves.push_back(check_pos);
            }
            break;
        }        
        check_pos = check_pos + UP + LEFT;
    }

    //Keep going diagonally until a piece is encountered or the board ends.
    check_pos = start_pos + DOWN + LEFT;
    while(check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
        if(board[check_pos.getY()][check_pos.getX()] == nullptr){
            valid_moves.push_back(check_pos);
        }
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

