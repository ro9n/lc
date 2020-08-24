/**
 * @file 1220.count.vowel.permutations.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Mon August 24 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

inline void add_self(int &a, int b) {
  a += b;
  if (a >= M) a -= M;
}

class Solution {
 public:
  int countVowelPermutation(int n) {
    int dp[n][5]; memset(dp, 0, sizeof dp);
     
    // a e i o u
    // 0 1 2 3 4
    for(int i = 0; i < 5; ++i) dp[0][i] = 1;

    for (int i = 1; i < n; ++i) {
      // a
      add_self(dp[i][1], dp[i - 1][0]);

      // e
      add_self(dp[i][0], dp[i - 1][1]);
      add_self(dp[i][2], dp[i - 1][1]);

      // i
      add_self(dp[i][0], dp[i - 1][2]);
      add_self(dp[i][1], dp[i - 1][2]);
      add_self(dp[i][3], dp[i - 1][2]);
      add_self(dp[i][4], dp[i - 1][2]);

      // o
      add_self(dp[i][2], dp[i - 1][3]);
      add_self(dp[i][4], dp[i - 1][3]);

      // u
      add_self(dp[i][0], dp[i - 1][4]);
    }

    int c = 0;
    for (auto f : dp[n - 1]) add_self(c, f);
    return c;
  }
};