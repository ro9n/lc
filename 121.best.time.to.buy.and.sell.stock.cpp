/**
 * @file 121.best.time.to.buy.and.sell.stock.cpp
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
  int maxProfit(vector<int>& p) {
    if (p.empty()) return 0;

    int dp0 = p[0], dp1 = 0;  // profit without stock: 0, with stock: 1

    for (int i = 1; i < p.size(); ++i) {
      int tmp = dp1 + p[i];  // new dp0
      dp1 = dp0 - p[i];
      dp0 = tmp;
    }

    return max(dp0, dp1);
  }
};
