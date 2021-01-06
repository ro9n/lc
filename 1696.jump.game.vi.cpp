/**
 * @file 1696.jump.game.vi
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday December 25 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    int n = nums.size(), best = 0;

    for (int i = 1; i < n; ++i) {
      if (i - k <= best) {
        nums[i] += nums[best];
        if (nums[i] >= nums[best]) best = i;
      } else {
        best = max(best + 1, i - k);
        for (int j = best + 1; j < i; ++j)
          if (nums[j] >= nums[best]) best = j;
        nums[i] += nums[best];
      }
    }

    return nums[n - 1];
  }
};