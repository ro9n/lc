/**
 * @file 39.combination.sum
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday January 17 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> f(min(n, 30), 0);
    unordered_set<string> seen;
    vector<vector<int>> ans;

    function<void(int)> choose = [&](int k) {
      if (!k) {
        vector<int> tmp;
        string s;
        for (int i = 0, n = f.size(); i < n; ++i) {
          if (f[i]) s += to_string(i) + 'x' + to_string(f[i]);
          for (int j = 0; j < f[i]; ++j) tmp.push_back(nums[i]);
        }
        if (seen.count(s)) return;
        else
          seen.insert(s), ans.push_back(tmp);
      } else if (k > 0) {
        for (int i = 0; i < n; ++i) {
          if (nums[i] <= k) ++f[i], choose(k - nums[i]), --f[i];
        }
      }
    };

    choose(k);
    return ans;
  }
};
