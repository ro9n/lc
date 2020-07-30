/**
 * @file 279.perfect.squares.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu July 30 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9 + 7;

class Solution {
 public:
  int numSquares(int n) {
    int dp[n + 1], k = sqrt(n) + 1;
    dp[0] = 0; for (int i = 1; i <= n; ++i) dp[i] = INF;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j < k; ++j) {
        if (i >= j * j) dp[i] = min(dp[i], 1 + dp[i - j * j]);
      }
    }

    return dp[n];
  }
};
