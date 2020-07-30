/**
 * @file 1049.last.stone.weight.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu July 30 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()

class Solution {
 public:
  int lastStoneWeightII(vector<int>& v) {
    int n = v.size(), s = accumulate(all(v), 0), dp[n + 1][(s >> 1) + 1], best = 0; // [index upto i][target sum]

    memset(dp, 0, sizeof dp); dp[0][0] = 1;

    // index
    for (int i = 1; i <= n; ++i) {
      dp[i][0] = 1;
      // weight
      for (int w = 1; w <= s >> 1; ++w) {
        if (w < v[i - 1]) dp[i][w] = dp[i - 1][w]; // current weight is greater than target sum: skip
        else dp[i][w] = dp[i - 1][w] | dp[i - 1][w - v[i - 1]]; // take

        if (dp[i][w]) best = max(best, w); // by maximizing diff, minimize ans
      }
    }

    return s - (best << 1);
  }
};

