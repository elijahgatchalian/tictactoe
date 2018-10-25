// Eli Gatchalian
// p2.cpp
// May 1, 2014
// Purpose: Outputs the game Tic-Tac-Toe for users to play
// Input: Asks users for the row and column they wish to place their X's and
//  O's on the board
// Process: Uses input from users to place appropriate marker in the
//  corresponding spot on the board. Game will continue until a player has won
//  or there are no more spaces available.
// Output: Program will output the board after each turn. Once the game is
//  done, the program will display the winner or if there was a tie. After,
//  the program will display a running record of how many wins and ties there
//  are.
// Example: "X, row?" "0" "X, column?" "0"
//          "O, row?" "1" "O, column?" "2"

#include <iostream>
#include "tictactoe.h"
using namespace std;

const char YES = 'Y';
const char X = 'X';
const char O = 'O';
const int STOP = 25;

void twentyFiveLines();
// Clears the screen by printing out 25 blank lines

void welcomeMessage();
// Greets users and explains game

void statistics(int xWins, int oWins, int ties);
// Displays results of the game and previous games

void goodbyeMessage();
// Thanks users for playing the game

int main(){
    TicTacToe playGame;
    char answer;
    char piece = X;
    int row, col;
    int xWins = 0;
    int oWins = 0;
    int ties = 0;

    welcomeMessage();
    cout << "Would you like to play? (y/n) ";
    cin >> answer;
    cin.ignore();
    
    while (toupper(answer) == YES){
        playGame.resetBoard();
        playGame.drawBoard();
        while (!playGame.checkWin(piece) && !playGame.checkTie()){
            cout << endl << endl << endl;
            cout << piece << ", please provide a row: ";
            cin >> row;
            cout << piece << ", please provide a column: ";
            cin >> col;
            cout << endl << endl << endl;
            playGame.placePiece(piece, row, col);
            if (!playGame.placePiece(piece, row, col))
                cout << "That spot is already taken! Sorry!" << endl;
            playGame.drawBoard();
            playGame.checkWin(piece);
            if (piece == X){
                if (!playGame.checkWin(piece))
                    piece = O;
            }else{
                if (!playGame.checkWin(piece))
                    piece = X;
            }
        }
        if (playGame.checkWin(piece)){
            if (piece == X){
                cout << endl << endl;
                cout << "X wins!" << endl << endl;
                xWins++;
            }else{
                cout << endl << endl;
                cout << "O wins!" << endl << endl;
                oWins++;
            }
        }else{
            cout << endl << endl;
            cout << "No one won! The game ends in a tie." << endl << endl;
            ties++;
        }
        statistics(xWins, oWins, ties);
        cout << endl << endl << endl;
        cout << "Would you like to play again? (y/n) ";
        cin >> answer;
    }
    goodbyeMessage();
    
    return 0;
}

void twentyFiveLines(){
  for (int i = 0; i < STOP; i++)
	cout << endl;
}

void welcomeMessage(){
    twentyFiveLines();
    cout << "Welcome to Tic-Tac-Toe! Get a piece three in a row and you win!" << endl
    << "You have three ways to win! Three in a row, column, or diagonal! Goodluck!";
    cout << endl << endl << endl;
}

void statistics(int xWins, int oWins, int ties){
    cout << "X wins: " << xWins << endl;
    cout << "O wins: " << oWins << endl;
    cout << "Ties: " << ties << endl;
}

void goodbyeMessage(){
    cout << endl << endl << endl
    << "Thanks for playing!"
    << endl << endl << endl;
}
