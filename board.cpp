// Gabriele Cepparulo
// Final Project
// Class for board.

#include "board.h"
#include "pos.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


//Overloading () operator to select piece from board array.
Piece* board::operator()(int i, int j)
{
    if(i<0 || i>RANKS || j<0 || j>FILES){
        std::cout<<"Error: trying to access board element out of bounds"<<std::endl;
        throw("Out of Bounds error");
    }
    // j is the y coordinate, corresponding to rows
    // i is the x coordinate, corresponding to columns
    return board_array[j][i];
}

//Overloading assignment operator for deep copying.
board& board::operator=(board& b)
{
	// self-assignment check
	if (this == &b){
		return *this;
    }
    
    for(int r = 0; r < RANKS; r++){
        for(int f = 0; f < RANKS; f++){
            board_array[r][f] = b.board_array[r][f];
        }
    }
    white_king_pos = b.getKingPos(WHITE_PIECE);
    black_king_pos = b.getKingPos(BLACK_PIECE);
    whites_turn = b.getTurn();
    white_in_check = b.isWhiteInCheck();
    black_in_check = b.isBlackInCheck();

	return *this;
}

//Function to visualise board
void board::printBoard()
{   
    std::cout<< std::endl << "  ";
    for(int i=0; i<RANKS; i++){
        std::cout<< " -  ";
    }
    std::cout<<std::endl;
    for(int i=0; i<RANKS; i++){
        std::cout << RANKS - i ;  

        for(int j=0; j<FILES; j++){
            std::cout << "| ";
            if((board_array[i][j]) == nullptr){
                std::cout << "  ";
            }else{
                (*board_array[i][j]).printFunction();
                std::cout << " ";
            }
            if(j==FILES-1){
                std::cout << "|" << std::endl; 
            }

        }
        for(int j=0; j<=FILES; j++){
            if(i==RANKS-1){
                continue;
            }else{
                if(j==0){
                    std::cout << "  "; 
                }else if(j==FILES){
                    std::cout << " - " << std::endl; 
                }else{
                    std::cout << " - +";
                }
            }
        }
    }
    std::cout<< "  ";
    for(int i=0; i<RANKS; i++){
        std::cout<< " -  ";
    }
    std::cout<<std::endl <<"  ";
    for(char i='A'; i<='H'; i++){
        std::cout << " "<< i << "  ";
    }
    std::cout<<std::endl;
}

//Functions to convert from input to pos and viceversa
pos board::str2pos(std::string input_str)
{   
    int i = toupper(input_str[0]) - 65;
    pos temp{i, 48 + RANKS - toupper(input_str[1])};
    return temp;
}
std::array<char,2> board::pos2char(pos input_pos)
{
    std::array<char,2> char_arr;
    char_arr[0] = input_pos.getX() + 65;
    char_arr[1] = 48 + RANKS - input_pos.getY();
    return char_arr;
}

//Function to get the position of a king of a given colour.
pos board::getKingPos(char colour)
{
    if (colour==WHITE_PIECE){
        return white_king_pos;
    }else{
        return black_king_pos;
    }
}

// Function to make a move. This function takes user input
// for the piece to move and the desired destination.
// The function then checks if a piece of the right
// colour is selected, or if an empty space is selected.
// The function checks all the allowed moves for that piece.
// The function then checks if the move would put the 
// king in check, and if the king is already in check
// it only allows moves to stop the threat.
// The function returns an integer which indicates if:
// the game ended in a checkmate or stalemate, the
// move was not valid and hence must be repeated,
// the move was performed correctly. 
// If move is performed correctly, board is printed and 
// it is the other player's turn. 
int board::makeMove(std::string from_in, std::string to_in)
{
    pos from = str2pos(from_in);
    pos to = str2pos(to_in);
    std::cout << std::endl<< "moving from: " << from_in << std::endl;
    std::cout << "moving to: " << to_in << std::endl;

    std::vector<pos> valid_moves;
    bool allowed_move = false;
    char turn;
    int move_result;
    pos king_position;
    bool player_in_check;
    if (whites_turn==true){
        turn = WHITE_PIECE;
        king_position = white_king_pos;
        player_in_check = white_in_check;
    }else{
        turn = BLACK_PIECE;
        king_position = black_king_pos;
        player_in_check = black_in_check;
    }
    
    //if the chosen piece is not an empty space and of the right colour find the valid moves
    if(board_array[from.getY()][from.getX()] != nullptr){
        if(board_array[from.getY()][from.getX()]->getColour() == turn){
            valid_moves = board_array[from.getY()][from.getX()]->validMoves(board_array, from);
            //check which of the valid moves do not leave the king in check afterwards
            for(auto it = valid_moves.begin(); it!=valid_moves.end(); it++){
                if (*it == to){
                    //make a virtual board, copying the current one
                    //make the move in the virtual board and check if king is in check
                    board virtual_board;
                    virtual_board = *this;
                    virtual_board.virtualMove(from, (*it));
                    pos virtual_king_pos;
                    virtual_king_pos = virtual_board.getKingPos(turn);
                    if( dynamic_cast<King*>(virtual_board.board_array[virtual_king_pos.getY()][virtual_king_pos.getX()])->kingToCheck(virtual_board.board_array,virtual_king_pos, virtual_king_pos, turn) == false){
                        allowed_move = true;
                    }else{
                        printBoard();
                        //if the king was already in check before, and the move leaves the king still in check
                        if( dynamic_cast<King*>(board_array[king_position.getY()][king_position.getX()])->kingToCheck(board_array,king_position, king_position, turn) == true){
                            std::cout  << std::endl << "Error: Your king is in check, you must stop the threat.";
                        //if the king was not in check before, and the move leaves the king in check after
                        }else if ( dynamic_cast<King*>(board_array[king_position.getY()][king_position.getX()])->kingToCheck(board_array,king_position, king_position, turn) == false) {
                            std::cout  << std::endl << "Error: This move puts your own king in check";
                        }
                        //move must be repeated, skip to the end
                        move_result = REPEATMOVE;
                        goto End_of_move;
                    }
                }
            }
        }else{
            printBoard();
            std::cout  << std::endl << "Error: It is not your turn to move";
            move_result = REPEATMOVE;
            goto End_of_move;
        }
    }else{
        printBoard();
        std::cout  << std::endl << "Error: You selected an empty space";
        move_result = REPEATMOVE;
        goto End_of_move;
    }
    // if the move is allowed (based on the move set of the piece and if the king would
    // not be in check after the move) then make the move
    if(allowed_move==true){
        //if the king is moving, update its position in the private member
        if( (board_array[from.getY()][from.getX()])->getType() == KING ){
            if(turn == WHITE_PIECE){
                white_king_pos = to;
            }else{
                black_king_pos = to;
            }
        }
        board_array[to.getY()][to.getX()] = board_array[from.getY()][from.getX()];
        board_array[from.getY()][from.getX()] = nullptr;
        saveMove(from_in, to_in); //save move to stringstream

        //Promotion of pawns when they get to the opposite side
        if( (board_array[to.getY()][to.getX()])->getType() == PAWN){
            if( (board_array[to.getY()][to.getX()])->getColour() == WHITE_PIECE){
                if( to.getY() == 0){
                    delete board_array[to.getY()][to.getX()];
                    board_array[to.getY()][to.getX()] = new Queen{WHITE_PIECE};
                }
            }else{
                if( to.getY() == RANKS - 1){
                delete board_array[to.getY()][to.getX()];
                board_array[to.getY()][to.getX()] = new Queen{BLACK_PIECE};
                }
            }
        }
        printBoard();

        char opponent_colour;
        if(whites_turn==true){
            opponent_colour = BLACK_PIECE;
        }else{
            opponent_colour = WHITE_PIECE;
        }
        //check if game is over after the move
        move_result = isGameOver(opponent_colour);
        if(move_result == CHECKMATE || move_result == STALEMATE){
            goto End_of_move;
        }
        //if game is not over, update player's turn to make the next move
        if(whites_turn==true){
            whites_turn = false;
        } else{
            whites_turn = true;
        }
    }else{
        printBoard();
        std::cout<<std::endl<<"Error: this move is not allowed"<<std::endl;
        if(valid_moves.size() == 0){
            std::cout<<"There are no allowed moves for this piece.";
        }else{
            std::cout<<"Allowed moves for this piece are: "<<std::endl;
            for(auto it = valid_moves.begin(); it!=valid_moves.end(); it++){
                std::array<char,2> move_it = pos2char(*it);
                std::cout << move_it[0] << move_it[1] << std::endl;
            }
        }
        move_result = REPEATMOVE;
    }
    End_of_move:

    return move_result;
}

// Function to make a virtual move, without checking anything
// this is only used in "virtual" boards.
void board::virtualMove(pos from, pos to)
{   
    if (board_array[from.getY()][from.getX()]->getType() == KING){
        if (board_array[from.getY()][from.getX()]->getColour() == WHITE_PIECE){
            white_king_pos = to;
        }else{
            black_king_pos = to;
        }
    }
    board_array[to.getY()][to.getX()] = board_array[from.getY()][from.getX()];
    board_array[from.getY()][from.getX()] = nullptr;
}

// Function to check if the game is over or can still continue.
int board::isGameOver(char opponent_colour)
{   
    int game_over;
    pos king_position;
    bool king_in_check;
    std::vector<pos> king_valid_moves;
    std::vector<pos> block_moves;
    if(opponent_colour == WHITE_PIECE){
        king_position = white_king_pos;
    }else{
        king_position = black_king_pos;
    }
    king_in_check = dynamic_cast<King*>(board_array[king_position.getY()][king_position.getX()])->kingToCheck(board_array, king_position, king_position, opponent_colour);
    king_valid_moves = (board_array[king_position.getY()][king_position.getX()])->validMoves(board_array, king_position);
    
    board virtual_board;
    //find which moves could stop the king from being in check
    for(int r=0; r<RANKS; r++){
        for(int f=0; f<FILES; f++){
            if(board_array[r][f] != nullptr){
                if((board_array[r][f])->getColour() == opponent_colour){
                    if((board_array[r][f])->getType() != KING){
                        pos check_pos{f,r};
                        std::vector<pos> move_set;
                        move_set = (board_array[r][f])->validMoves(board_array, check_pos);
                        if(move_set.size()!=0){
                            for(auto it = move_set.begin(); it!=move_set.end(); it++){
                                virtual_board = *this;
                                virtual_board.virtualMove(check_pos, (*it));
                                pos virtual_king_pos;
                                virtual_king_pos = virtual_board.getKingPos(opponent_colour);                                
                                if( dynamic_cast<King*>( virtual_board.board_array[virtual_king_pos.getY()][virtual_king_pos.getX()])->kingToCheck(virtual_board.board_array,virtual_king_pos, virtual_king_pos, opponent_colour) == false){
                                    block_moves.push_back((*it));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    //if the king is in check and there are no moves to stop the threat
    //then it is a checkmate and game is over
    if(king_in_check == true){
        if(king_valid_moves.size() == 0 && block_moves.size() == 0){
            game_over = CHECKMATE;
            std::cout<< "Checkmate!" << std::endl; 
            if(whites_turn == true){
                std::cout<< "White Wins." << std::endl; 
            }else{
                std::cout<< "Black Wins." << std::endl; 
            }
        //if the king is in check but there are moves to stop the threat
        //then game is not over
        }else if( king_valid_moves.size() != 0 || block_moves.size() != 0){
            game_over = GAMEON;
            if(whites_turn == true){
                std::cout << std::endl << "Black is in check!! You must stop the threat!" << std::endl;
                black_in_check = true;

            }else{
                std::cout << std::endl << "White is in check!! You must stop the threat!" << std::endl;
                white_in_check = true; 
            }     
        }
    // if the king is not in check but there are no moves that would
    // not put the king in check, then it is stalemate
    }else if(king_in_check == false){
        if(king_valid_moves.size() == 0 && block_moves.size() == 0){
            game_over = STALEMATE;
            std::cout<< "Stalemate! No one wins." << std::endl; 
        }else{
            game_over = GAMEON;
        }
    }
    return game_over;
}

//function to print the colour of the player whose turn it is.
std::string board::printColour()
{
    if(whites_turn == true){
        return white;
    }else{
        return black;
    }
}

// Function to clear board (garbage collection)
void board::clearBoard()
{
    for(int r=0; r<RANKS; r++){
        for(int f=0; f<FILES; f++){
            if(board_array[r][f] != nullptr){
                delete board_array[r][f];
            }
        }
    }
}
// Function to save a move to a stringstream after it is performed correctly
void board::saveMove(std::string from_in, std::string to_in)
{
    game_history << from_in << "->" << to_in << std::endl;
}
// Fucntion write game history to a .txt file
void board::saveHistory(std::string file_name)
{
    std::ofstream output_file(file_name);;
    output_file << game_history.rdbuf();
    output_file.close();
}
