/**
 * @file 1000.min.cost.to.merge.stones.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sun August 30 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

#define INF 101

class Solution {
 public:
  int mergeStones(vector<int>& stones, int K) {
    // int n = stones.size();
    // if (n % K) return -1;

    // int dp[n][n];

    // for (int i = 0; i < n; ++i) {
    //   dp[i][i] = stones[i];

    //   for (int j = i; j < n; ++j) {
    //     if (i != j) dp[i][j] = INF;
    //   }
    // }

    // for (int l = 0; l < n; ++l) {
    //   for (int r = l; r < n; ++r) {
    //     int tmp = 0;
    //     if (r - l + 1 == K) {
    //       for (int i = l; i <= r; ++i) {
    //         tmp += stones[i];
    //       }
    //       dp[l][r] = min(dp[l][r], tmp);
    //     }
    //   }
    // }

    // return dp[0][n - 1];
  }
};