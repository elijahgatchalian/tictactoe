// Eli Gatchalian
// tictactoe.h
// May 1, 2014
// Purpose: This class holds all the necessary functions and variables to
//  properly play a game of Tic-Tac-Toe.

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
 public:
  TicTacToe();
  
  TicTacToe(const TicTacToe& t);
  
  TicTacToe& operator = (const TicTacToe& rhs);
  
  void drawBoard();
  // Displays board after each user has chosen a spot
  
  bool placePiece(char piece, int row, int col);
  // postconditions: Changes chosen spot from user from SPACE to their
  //  respective piece
  
  bool checkWin(char& piece);
  // Returns true if a player has won the game
  
  bool checkTie();
  // Returns true if there are no more free spaces to place piece
  
  void resetBoard();
  // Resets board after a player has won or the game ends in a tie
  
  ~TicTacToe();
  
 private:
  char **board;
  static const int SIZE = 3;
  static const char SPACE = ' ';
  static const char VERTICAL = '|';
  static const char DASH = '-';
  static const int COL_WIDTH = 3;
};
#endif
