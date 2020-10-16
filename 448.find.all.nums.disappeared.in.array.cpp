/**
 * @file 448.find.all.nums.disappeared.in.array
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday October 09 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size(); vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (nums[i] > n || nums[abs(nums[i]) - 1] < 0) continue;
      nums[abs(nums[i]) - 1] *= -1;
    }

    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0) ans.emplace_back(i + 1);
    }

    return ans;
  }
};
