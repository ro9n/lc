/**
 * @file 1482.min.num.of.days.to.make.m.bouqets
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday February 02 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minDays(vector<int>& blooms_on, int m, int k) {
    int n = blooms_on.size(),
        ans = -1;
    for (int l = 1, r = 1e9; l <= r;) {
      int mid = l + ((r - l) >> 1),
          flowers = 0,
          bouqets = 0;

      for (int j = 0; j < n; ++j) {
        if (blooms_on[j] <= mid) ++flowers;
        else
          bouqets += flowers / k, flowers = 0;
      }
      bouqets += flowers / k;
      if (bouqets >= m) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }

    return ans;
  }
};
