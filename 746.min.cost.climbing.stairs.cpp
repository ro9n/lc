/**
 * @file 746.min.cost.climbing.stairs.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu July 16 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& c) {
    const int n = c.size();
    vector<int> dp(n + 1, 0);

    for(int i = 2; i <= n; ++i) {
      dp[i] = min(dp[i - 1] + c[i - 1], dp[i - 2] + c[i - 2]);
    }

    return dp[n];
  }
};