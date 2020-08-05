/**
 * @file 221.maximal.square.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sat August 01 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& M) {
    if (M.empty()) return 0;
    int n = M.size(), m = M[0].size(), best = 0, dp[n][m];

    memset(dp, 0, sizeof dp);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (M[i][j] - '0') {
          int u = i > 0 ? dp[i - 1][j] : 0;
          int l = j > 0 ? dp[i][j - 1] : 0;
          int c = i > 0 && j > 0 ? dp[i - 1][j - 1] : 0;

          dp[i][j] = 1 + min(min(u, l), c);
          best = max(best, dp[i][j]);
        }
      }
    }

    return best * best;
  }
};