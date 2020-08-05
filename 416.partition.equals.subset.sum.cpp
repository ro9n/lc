/**
 * @file 416.partition.equals.subset.sum.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Fri July 31 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& v) {
    int n = v.size(), s = accumulate(v.begin(), v.end(), 0);

    if (s & 1) return 0;

    // dp of target sum
    int dp[(s >> 1) + 1]; memset(dp, 0, sizeof dp); dp[0] = 1;

    for (int i = 0; i < n; ++i) {
      // left to right would count the complement twice
      // -> right to left
      for (int j = s >> 1; j >= v[i]; --j) {
        dp[j] |= dp[j - v[i]]; // complement of j
      }
    }

    return dp[s >> 1];
  }
};