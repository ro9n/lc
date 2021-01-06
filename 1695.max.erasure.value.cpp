/**
 * @file 1695.max.erasure.value
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
  int maximumUniqueSubarray(vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size(), pfx[n], best = 0;
    ;
    pfx[0] = nums[0];

    for (int i = 1; i < n; ++i) pfx[i] = nums[i] + pfx[i - 1];

    unordered_map<int, int> m;

    for (int i = 0, l = 0; i < n; ++i) {
      l = max(l, m.count(nums[i]) ? m[nums[i]] + 1 : 0);
      m[nums[i]] = i;
      best = max(best, pfx[i] - (l > 0 ? pfx[l - 1] : 0));
    }

    return best;
  }
};

class Solution {
 public:
  int maximumUniqueSubarray(vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size(), sum = 0, best = 0;

    unordered_map<int, int> m;

    for (int i = 0, l = 0, L = 0; i < n; ++i) {
      sum += nums[i];
      l = max(l, m.count(nums[i]) ? m[nums[i]] + 1 : 0);
      m[nums[i]] = i;
      while (L < l) sum -= nums[L++];
      best = max(best, sum);
    }

    return best;
  }
};