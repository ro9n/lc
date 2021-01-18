/**
 * @file best.time.to.buy.and.sell.stock.revisited
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday January 19 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e4 + 4;

class Solution {
 public:
  int maxProfit(vector<int>& p) {
    int best = 0, buy = INF;

    for (int i = 0, n = p.size(); i < n; ++i) {
      if (p[i] < buy) buy = p[i];
      else best = max(best, p[i] - buy);
    }

    return best;
  }
};

