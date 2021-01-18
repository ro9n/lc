/**
 * @file 229.majority.elem.II
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
  vector<int> majorityElement(vector<int>& nums) {
    // n/2 → max 1
    // n/3 → max 2
    // n/4 → max 3
    /**
     * Boyer-Moore Voting Algorithm
     * 1 select 2 top votes
     * 2 count freq for top 2
     */
    int n = nums.size(), k = n / 3;

    int f1 = 0, f2 = 0, k1 = 0, k2 = 0;  // frequncy, leader/king

    for (auto x : nums) {
      if (x == k1) ++f1;
      else if (x == k2)
        ++f2;
      else if (!f1)
        k1 = x, ++f1;
      else if (!f2)
        k2 = x, ++f2;
      else
        --f1, --f2;
    }

    f1 = f2 = 0;
    for (auto x : nums) {
      if (x == k1) ++f1;
      else if (x == k2)
        ++f2;
    }

    vector<int> ans;
    if (f1 > k) ans.push_back(k1);
    if (f2 > k) ans.push_back(k2);
    return ans;
  }
};