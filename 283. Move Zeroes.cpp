/**
 * @file 283. Move Zeroes.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sun Jun 21 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& v) {
    int i = 0, j = 0, n = v.size();

    while (j < n) {
      if (v[j]) swap(v[i++], v[j++]);
      else
        ++j;
    }

    while (i < n) v[i++] = 0;
  }
};

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size(), j = 0;

    for (int i = 0; i < n; ++i) {
      if (nums[i]) {
        nums[j++] = nums[i];
      }
    }

    while (0 < j && j < n) nums[j++] = 0;
  }
};