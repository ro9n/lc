/**
 * @file 1155.num.of.dice.rolls.with.target.sum.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu August 06 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

class Solution {
 public:
  int numRollsToTarget(int d, int f, int K) {
    int dp[d + 1][K + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;

    for (int i = 1; i <= d; ++i) {
      for (int j = 1; j <= K; ++j) {
        int &ans = dp[i][j];
        for (int k = 1; k <= f; ++k) {
          if (k <= j) {
            ans += dp[i - 1][j - k];
            if (ans >= M) ans -= M;
          }
        }
      }
    }

    return dp[d][K];
  }
};
