// include guard: prevent from recompile

#ifndef TICTACTOE_H
#define TICTACTOE_H

const int r = 3;
const int c = 3;

class TicTacToe {
private:
  char board[r][c];
  int count = 0;

public:
  TicTacToe();
  bool isFull();
  void drawBoard();
  int checkWin();
  void compMove();
  bool playerMove(int row, int col);
  int minimax(int depth, bool isMax);
};

#endif
