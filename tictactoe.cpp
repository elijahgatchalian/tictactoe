// Eli Gatchalian
// tictactoe.cpp
// May 1, 2014
// Purpose: Implementation file for the tic-tac-toe game described in
//  tictactoe.h

#include "tictactoe.h"
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

TicTacToe::TicTacToe(){
    board = new char*[SIZE];
    assert(board != nullptr);
    for (int i = 0; i < SIZE; i++){
        board[i] = new char[SIZE];
        assert(board[i] != nullptr);
    }
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            board[r][c] = SPACE;
}

TicTacToe::TicTacToe(const TicTacToe& t){
    board = new char*[SIZE];
    assert(board != nullptr);
    for (int i = 0; i < SIZE; i++){
        board[i] = new char[SIZE];
        assert(board[i] != nullptr);
    }
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            board[r][c] = t.board[r][c];
}

TicTacToe& TicTacToe::operator = (const TicTacToe& rhs){
    if (this != &rhs){
        for (int r = 0; r < SIZE; r++)
            for (int c = 0; c < SIZE; c++)
                board[r][c] = rhs.board[r][c];
    }
    return *this;
}

void TicTacToe::drawBoard(){
    cout << endl << endl;
    for (int i = 0; i < COL_WIDTH - 1; i++)
        cout << SPACE;
    for (int i = 0; i < SIZE; i++)
        cout << setw(COL_WIDTH) << i;
    cout << endl;
    for (int r = 0; r < SIZE; r++){
        cout << setw(COL_WIDTH) << r;
        for (int c = 0; c < SIZE; c++)
            cout << SPACE << board[r][c] << VERTICAL;
        for (int i = 0; i < COL_WIDTH - 1; i++)
            cout << SPACE;
        cout << endl;
        for (int i = 0; i < SIZE; i++)
            cout << SPACE << DASH << SPACE << DASH;
        cout << endl;
    }
}

bool TicTacToe::placePiece(char piece, int row, int col){
    if (board[row][col] != SPACE && board[row][col] != piece)
        return false;
    else
        board[row][col] = piece;

    return true;
}

bool TicTacToe::checkWin(char& piece){
    int col, row;
    int count = 0;
  
    // check each row
    for (int r = 0; r < SIZE; r++){
        col = 0;
        for (int c = 0; c < SIZE; c++){
            if (board[r][c] == piece)
                col++;
        }
        if (col == SIZE) return true;
    }
  
    // check each column
    for (int c = 0; c < SIZE; c++){
        row = 0;
        for (int r = 0; r < SIZE; r++){
            if (board[r][c] == piece)
                row++;
        }
        if (row == SIZE) return true;
    }
  
    // check one diagonal
    for (int i = 0; i < SIZE; i++){
        if (board[i][i] == piece)
            count++;
    }
    if (count == SIZE) return true;
    count = 0;
  
    // check other diagonal
    for (int i = 0; i < SIZE; i++){
        if (board[i][SIZE - 1 - i] == piece) count++;
    }
    if (count == SIZE) return true;
    
    return false;
}

bool TicTacToe::checkTie(){
    int col = 0;
    int row = 0;

    for (int r = 0; r < SIZE; r++){
        while (board[r][col] != SPACE && col < SIZE) col++;
        if (col == SIZE) row++;
        col = 0;
    }
    
    return row == SIZE;
}

void TicTacToe::resetBoard(){
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            board[r][c] = SPACE;
}

TicTacToe::~TicTacToe(){
    for (int i = 0; i < SIZE; i++)
        delete [] board[i];
    delete [] board;
}
