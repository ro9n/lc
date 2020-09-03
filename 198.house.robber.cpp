/**
 * @file 198.house.robber.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wed September 02 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& h) {
    if (h.empty()) return 0;

    int dp0 = 0, dp1 = h[0];

    for (int i = 1; i < h.size(); ++i) {
      int tmp = dp0 + h[i];
      dp0 = max(dp0, dp1);
      dp1 = tmp;

    }

    return max(dp0, dp1);
  }
};