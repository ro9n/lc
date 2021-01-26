/**
 * @file 523.continuous.subarray.sum
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday January 20 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    map<int, int> m; int sum = 0;
    m[0] = -1; // {0, 0}, 0

    for(int i = 0, n = nums.size(); i < n; ++i) {
      sum += nums[i];
      if (k) sum %= k;
      if (m.count(sum)){ if (i - m[sum] > 1) return 1;}
      else m[sum] = i;
    }

    return 0;
  }
};
