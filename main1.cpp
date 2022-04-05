// Gabriele Cepparulo 24/02/21
// PHYS 30762 Programming in C++
//Final Project
//Program to play chess.
//This program prints a board and asks for moves from two players.
//The program performs input validation, error handling for allowed moves
//and keeps track of whose turn it is to play.
//The code announces when a king is in check and when the game ends 
//in checkmate or stalemate.
//After a game ends the user is asked to input a file name to save game history
//to a text file. The user can choose to play again after a game ends.

//Main file.

#include "pos.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "board.h"
#include "constants.h"
#include <fstream>
#include <bits/stdc++.h>
#include <iostream>
#include <cctype>

int main()
{   
    char play_more = 'Y';
    while(toupper(play_more) == 'Y'){

        board chessboard;
        chessboard.printBoard();
        int counter = 0;
        int game = GAMEON;
            
        std::cout << std::endl << "*************************************************" << std::endl << std::endl;
        std::cout<< "White Begins:  " << std::endl;
        while(game == GAMEON || game == REPEATMOVE){
            if(counter != 0){
                std::cout << std::endl << chessboard.printColour() << "'s turn:" << std::endl;
            }

            //Asking and validating user input for piece to be moved (from)
            std::cout<< "From: " << std::endl;
            std::string input_from;
            std::getline(std::cin, input_from);
            while(toupper(input_from[0]) > 'H' || toupper(input_from[0]) < 'A' || input_from[1] > '8' || input_from[1] < '1' || input_from.length() > 2){
                std::cout<< "Error: Wrong input format. Please enter a file (letters from A to H) and an rank (integers 1 to 8)" << std::endl;
                std::cin.clear();
                std::getline(std::cin, input_from);
            }

            //Asking and validating user input for destination of move (to)
            std::cout<< "To: " << std::endl;
            std::string input_to;
            std::getline(std::cin, input_to);
            while(toupper(input_to[0]) > 'H' || toupper(input_to[0]) < 'A' || input_to[1] > '8' || input_to[1] < '1' || input_to.length() > 2){
                std::cout<< "Error: Wrong input format. Please enter a letter (A to H) and an integer (1 to 8)" << std::endl;
                std::cin.clear();
                std::getline(std::cin, input_to);
            }
            //Calling function to make the move, which returns an integer value.
            //possible outcomes: repeat move (because not valid), checkmate, stalemate.
            game = chessboard.makeMove(input_from, input_to);
            std::cout << std::endl << std::endl;
            if(game != REPEATMOVE){
                counter++;
            }

            if(game == GAMEON){
                std::cout<< "*************************************************" << std::endl << std::endl;
                std::cout<< "MOVE N.: " << counter+1 << std::endl;
            }        
        }

        //Once game is over, ask user a file name to save game history as .txt file.
        char history_file[100];
        std::cout<<"Enter file name to save game history (without extension): ";
        std::cin>>history_file;
        chessboard.saveHistory(std::strcat(history_file, ".txt"));

        //Garbage collection
        chessboard.clearBoard();

        //Ask user to play another game.
        std::cout<<"Do you want to play again? Press yes [Y/y] or no [N/n]." << std::endl;
        std::cin>>play_more;
        while (play_more != 'Y' && play_more != 'y' && play_more != 'N' && play_more != 'n') {
            std::cout << "Incorrect input character. Press [Y/y] yes or [N/n] no." << std::endl;
            std::cin.clear();
            std::cin >> play_more;
        }
        std::cin.clear();
        std::cin.ignore();
    }
    
    return 0;
}


