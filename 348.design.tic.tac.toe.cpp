/**
 * @file 348.design.tic.tac.toe
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday October 09 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class TicTacToe {
  vector<int> R, C;
  int diag, anti_diag;
  int N;

 public:
  /** Initialize your data structure here. */
  TicTacToe(int n) : N(n) {
    R.assign(n, 0), C.assign(n, 0);
    diag = anti_diag = 0;
  }

  /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
  int move(int r, int c, int p) {
    int k = p == 1 ? 1 : -1;
    R[r] += k, C[c] += k;
    if (r == c) diag += k;
    if (r == N - 1 - c) anti_diag += k;
    if (R[r] == N || C[c] == N || diag == N || anti_diag == N) return 1;
    else if (R[r] == -N || C[c] == -N || diag == -N || anti_diag == -N)
      return 2;

    return 0;
  }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */