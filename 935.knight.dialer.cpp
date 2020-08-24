/**
 * @file 935.knight.dialer.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sat August 08 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

const vector<vector<int>> m = {{4, 6}, {6, 8},    {7, 9}, {4, 8}, {0, 3, 9},
                               {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

class Solution {
 public:
  int knightDialer(int N) {
    int dp[N + 1][10];  // #of ways to dial i with j rep
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < 10; ++i) dp[1][i] = 1;

    for (int i = 2; i <= N; ++i) {
      for (int f = 0; f < 10; ++f) {  // from
        for (auto t : m[f]) {         // to
          dp[i][f] += dp[i - 1][t];
          if (dp[i][f] > M) dp[i][f] -= M;
        }
      }
    }

    long w = 0;
    for (int i = 0; i < 10; ++i) {
      w += dp[N][i];
      if (w > M) w -= M;
    }

    return w;
  }
};
