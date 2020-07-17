/**
 * @file 322.coin.change.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu July 16 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

class Solution {
 public:
  int coinChange(const vector<int>& coins, int k) {
    vector<int> dp(k + 1, INF);

    dp[0] = 0;

    for (int j = 1; j <= k; ++j) {
      for (auto c : coins) {
        if (j >= c) dp[j] = min(dp[j], 1 + dp[j - c]);
      }
    }

    return dp[k] == INF ? -1 : dp[k];
  }
};