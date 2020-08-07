/**
 * @file 494.target.sum.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Fri August 07 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
  int f(int i, int k, int K, const vector<int>& v) {
      if (i == v.size()) return k == K;
      else return f(i + 1, k + v[i], K, v) + f(i + 1, k - v[i], K, v);
   }

 public:
  int findTargetSumWays(vector<int>& v, int k) {
      return f(0, 0, k, v);
   }
};
*/

class Solution {
 public:
  int findTargetSumWays(vector<int>& v, int k) {
    if (k > 1000) return 0;
    int n = v.size(), dp[n + 1][2001];

    memset(dp, 0, sizeof dp);
    ++dp[0][1000 + v[0]]; ++dp[0][1000 - v[0]];

    for (int i = 1; i < n; ++i) {
      for (int s = -1000; s <= 1000; ++s) {
        if (dp[i - 1][s + 1000] > 0) {
          dp[i][s + v[i] + 1000] += dp[i - 1][s + 1000];
          dp[i][s - v[i] + 1000] += dp[i - 1][s + 1000];
        }
      }
    }

    return dp[n - 1][k + 1000];
  }
};