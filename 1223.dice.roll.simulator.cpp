/**
 * @file 1223.dice.roll.simulator.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sun August 09 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

void add_self(int& a, int b) {
  a += b;
  if (a >= M) a -= M;
}

class Solution {
 public:
  int dieSimulator(int n, vector<int>& rmax) {
    int dp[n + 1][6]; memset(dp, 0, sizeof dp);

    for (int j = 0; j < 6; ++j)
      for (int k = 1; k <= min(n, rmax[j]); ++k) ++dp[k][j];

    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 6; ++j) {
        for (int k = 0; k < 6; ++k) {
          if (j == k) continue;
          for (int l = 1; l <= rmax[k] && i - l >= 0; ++l) {
            add_self(dp[i][k], dp[i - l][j]);
          }
        }
      }
    }

    int r = 0;
    for (int j = 0; j < 6; ++j) add_self(r, dp[n][j]);

    return r;
  }
};

