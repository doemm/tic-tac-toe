#include <bits/stdc++.h>
#include "tic_tac_toe.h"
using namespace std;

int main() {
  TicTacToe game;
  cout << "start game" << endl;
  game.drawBoard();

  int status = 0;
  while (true) {
    bool input = 0;
    cout << "== your ==" << endl;
    while (input == 0) {
      int x, y;
      cout << "enter loc: ";
      cin >> x >> y;
      input = game.playerMove(x, y);
    }

    game.drawBoard();
    status = game.checkWin();
    if (status == -1) {
      cout << "you win" << endl;
      break;
    }

    if (game.isFull()) {
      cout << "draw" << endl;
      break;
    }

    cout << "== ai's ==" << endl;
    
    game.compMove();
    game.drawBoard();
    status = game.checkWin();

    if (status == 1) {
      cout << "you lose" << endl;
      break;
    }

    if (game.isFull()) {
      cout << "draw" << endl;
      break;
    }
  }

  return 0;
}
