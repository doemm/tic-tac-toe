#include <bits/stdc++.h>
#include "tic_tac_toe.h"
using namespace std;

TicTacToe::TicTacToe() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      board[i][j] = '*';
    }
  }
}

void TicTacToe::drawBoard() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (j < c-1) cout << board[i][j] << '|';
      else cout << board[i][j];
    }
    cout << endl;
  }
}

bool TicTacToe::playerMove(int row, int col) {
  if (board[row][col] == '*') {
    board[row][col] = 'X';
    count += 1;
    return true;
  }

  return false;
}

bool TicTacToe::isFull() {
  if (count == 9) return true;
  return false;
}

int TicTacToe::minimax(int depth, bool isMax) {
  int score = checkWin();

  // if comp has won
  if (score == 1) return score;
  
  // if player has won
  if (score == -1) return score;

  // if board is full
  if (isFull()) return 0;

  if (isMax) {
    
    int best = INT_MIN;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == '*') {
          board[i][j] = 'O';
          count += 1;
          best = max(best, minimax(depth+1, !isMax));
          board[i][j] = '*';
          count -= 1;
        }
      }
    }

    return best;

  } else {
    
    int best = INT_MAX;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == '*') {
          board[i][j] = 'X';
          count += 1;
          best = min(best, minimax(depth+1, !isMax));
          board[i][j] = '*';
          count -= 1;
        }
      }
    }

    return best;
  }
}

void TicTacToe::compMove() {
  int best_val = INT_MIN;
  int best_row = -1, best_col = -1;
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == '*') {
        board[i][j] = 'O';
        count += 1;
        int move_val = minimax(0, false);
        board[i][j] = '*';
        count -= 1;

        if (move_val > best_val) {
          best_row = i;
          best_col = j;
          best_val = move_val;
        }
      }
    }
  }

  board[best_row][best_col] = 'O';
  count += 1;
}

int TicTacToe::checkWin() {
  // check through the row
  for (int i = 0; i < r; i++) {
    if (board[i][0] == board[i][1] && 
        board[i][0] == board[i][2]) {
      if (board[i][0] == 'X') return -1;
      if (board[i][0] == 'O') return 1;
    }
  }

  // check through the col
  for (int i = 0; i < r; i++) {
    if (board[0][i] == board[1][i] && 
        board[0][i] == board[2][i]) {
      if (board[0][i] == 'X') return -1;
      if (board[0][i] == 'O') return 1;
    }
  }

  // check for the diagonals
  if (board[0][0] == board[1][1] && 
      board[0][0] == board[2][2]) {
      if (board[0][0] == 'X') return -1;
      if (board[0][0] == 'O') return 1;
  }

  if (board[0][2] == board[1][1] && 
      board[0][2] == board[2][0]) {
      if (board[0][2] == 'X') return -1;
      if (board[0][2] == 'O') return 1;
  }

  // game is not over
  return 0;
}
