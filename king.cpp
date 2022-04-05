// Final Project
// Inherited class for King.
// Gabriele Cepparulo

#include "king.h"
#include<iostream>
#include<cctype>

//Parametrised constructor.
King::King(char colour_in): Piece(colour_in, KING) {}


//Overridden function to get colour of pawn
char King::getColour() 
{
    return colour;
}

//Overridden function to get king type.
char King::getType() 
{
    return type;
}

//Overridden function to print king on the board.
void King::printFunction()
{   
    if(colour == WHITE_PIECE){
        std::cout<< WHITE_KING;
    }
    else{
        std::cout<< BLACK_KING;
    }

}


//Overridden function to get allowed moves for a pawn.
//Takes as inputs: an array containing piece pointers
//and the position of the pawn.
//King can move by one space in every direction.
//For each possible move, the function checks whether
//it would put the king in check.
std::vector<pos> King::validMoves(Piece* board[RANKS][FILES], pos start_pos)
{   
    std::vector<pos> valid_moves;
    pos check_pos;
    bool king_to_check;
    char king_colour;
    king_colour = (board[start_pos.getY()][start_pos.getX()])->getColour();

    check_pos = start_pos + UP;
    if(check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
        king_to_check = kingToCheck(board, start_pos, check_pos, king_colour);
        if (king_to_check == false){
            if(board[check_pos.getY()][check_pos.getX()] == nullptr){
                valid_moves.push_back(check_pos);
            }else if(board[check_pos.getY()][check_pos.getX()] != nullptr && (board[check_pos.getY()][check_pos.getX()])->getColour() != (board[start_pos.getY()][start_pos.getX()])->getColour()){
                valid_moves.push_back(check_pos);
            }
        }
    }

    check_pos = start_pos + UP + RIGHT;
    if(check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
        king_to_check = kingToCheck(board, start_pos, check_pos, king_colour);
        if (king_to_check == false){
            if(board[check_pos.getY()][check_pos.getX()] == nullptr){
                valid_moves.push_back(check_pos);
            }else if(board[check_pos.getY()][check_pos.getX()] != nullptr && (board[check_pos.getY()][check_pos.getX()])->getColour() != (board[start_pos.getY()][start_pos.getX()])->getColour()){
                valid_moves.push_back(check_pos);
            }
        }
    }

    check_pos = start_pos + UP + LEFT;
    if(check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
        king_to_check = kingToCheck(board, start_pos, check_pos, king_colour);
        if (king_to_check == false){
            if(board[check_pos.getY()][check_pos.getX()] == nullptr){
                valid_moves.push_back(check_pos);
            }else if(board[check_pos.getY()][check_pos.getX()] != nullptr && (board[check_pos.getY()][check_pos.getX()])->getColour() != (board[start_pos.getY()][start_pos.getX()])->getColour()){
                valid_moves.push_back(check_pos);
            }
        }
    }

    check_pos = start_pos + DOWN;
    if(check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
        king_to_check = kingToCheck(board, start_pos, check_pos, king_colour);
        if (king_to_check == false){
            if(board[check_pos.getY()][check_pos.getX()] == nullptr){
                valid_moves.push_back(check_pos);
            }else if(board[check_pos.getY()][check_pos.getX()] != nullptr && (board[check_pos.getY()][check_pos.getX()])->getColour() != (board[start_pos.getY()][start_pos.getX()])->getColour()){
                valid_moves.push_back(check_pos);
            }
        }
    }

    check_pos = start_pos + DOWN + RIGHT;
    if(check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
        king_to_check = kingToCheck(board, start_pos, check_pos, king_colour);
        if (king_to_check == false){
            if(board[check_pos.getY()][check_pos.getX()] == nullptr){
                valid_moves.push_back(check_pos);
            }else if(board[check_pos.getY()][check_pos.getX()] != nullptr && (board[check_pos.getY()][check_pos.getX()])->getColour() != (board[start_pos.getY()][start_pos.getX()])->getColour()){
                valid_moves.push_back(check_pos);
            }
        }
    }

    check_pos = start_pos + DOWN + LEFT;
    if(check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
        king_to_check = kingToCheck(board, start_pos, check_pos, king_colour);
        if (king_to_check == false){
            if(board[check_pos.getY()][check_pos.getX()] == nullptr){
                valid_moves.push_back(check_pos);
            }else if(board[check_pos.getY()][check_pos.getX()] != nullptr && (board[check_pos.getY()][check_pos.getX()])->getColour() != (board[start_pos.getY()][start_pos.getX()])->getColour()){
                valid_moves.push_back(check_pos);
            }
        }
    }

    check_pos = start_pos + LEFT;
    if(check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
        king_to_check = kingToCheck(board, start_pos, check_pos, king_colour);
        if (king_to_check == false){
            if(board[check_pos.getY()][check_pos.getX()] == nullptr){
                valid_moves.push_back(check_pos);
            }else if(board[check_pos.getY()][check_pos.getX()] != nullptr && (board[check_pos.getY()][check_pos.getX()])->getColour() != (board[start_pos.getY()][start_pos.getX()])->getColour()){
                valid_moves.push_back(check_pos);
            }
        }
    }

    check_pos = start_pos + RIGHT;
    if(check_pos.getY()<RANKS && check_pos.getY()>=0 && check_pos.getX()<FILES && check_pos.getX()>=0){
        king_to_check = kingToCheck(board, start_pos, check_pos, king_colour);
        if (king_to_check == false){
            if(board[check_pos.getY()][check_pos.getX()] == nullptr){
                valid_moves.push_back(check_pos);
            }else if(board[check_pos.getY()][check_pos.getX()] != nullptr && (board[check_pos.getY()][check_pos.getX()])->getColour() != (board[start_pos.getY()][start_pos.getX()])->getColour()){
                valid_moves.push_back(check_pos);
            }
        }
    }

    return valid_moves;

}


//Function to check if the king of a given colour is in check
//checks through the valid moves of all the pieces of the opponent
//if the king's destination coincides with at least one move of an opponent's piece
//the function returns true.
//(a player cannot put its own king in check)
bool King::kingToCheck(Piece* board[RANKS][FILES], pos from, pos to, char kingcolour)
{   
    Piece* virtual_board[RANKS][FILES];

    for(int r=0; r<RANKS; r++){
        for(int f=0; f<FILES; f++){
            virtual_board[r][f] = board[r][f];
        }
    }

    char opponent_colour;
    if(kingcolour == WHITE_PIECE){
        opponent_colour = BLACK_PIECE;
    }else{
        opponent_colour = WHITE_PIECE;
    }

    virtual_board[to.getY()][to.getX()] = board[from.getY()][from.getX()];
    virtual_board[from.getY()][from.getX()] = nullptr;

    bool check = false;
    for(int r=0; r<RANKS; r++){
        for(int f=0; f<FILES; f++){
            if(virtual_board[r][f] != nullptr){
                if((virtual_board[r][f])->getColour() == opponent_colour){
                    if((virtual_board[r][f])->getType() != KING){
                        pos check_pos{f,r};
                        std::vector<pos> move_set;
                        move_set = (virtual_board[r][f])->validMoves(virtual_board, check_pos);
                        for(auto it = move_set.begin(); it!=move_set.end(); it++){
                            if((*it).getX() == to.getX() && (*it).getY() == to.getY()){
                                check = true;
                                //if at least one move of one piece coincides with the king position
                                //the king is in check, no need to check the rest
                                goto jump; 
                            }
                        }
                    }
                }
            }
        }
    }

    jump:
    return check;
}
