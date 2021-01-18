/**
 * @file 977.sq.of.sorted.array
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday January 18 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size(); vector<int> ans(n);
    for (int l = 0, r = n - 1, i = n - 1; i>=0; --i) {
      if (abs(nums[l]) > abs(nums[r])) ans[i] = nums[l] * nums[l], ++l;
      else ans[i] = nums[r] * nums[r], --r;
    }

    return ans;
  }
};