/**
 * @file 416.triangle.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sat August 01 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& t) {
    int n = t.size();

    for (int i = n - 1; i > 0; --i) {
      for (int j = 0; j < t[i].size() - 1; ++j) {
        t[i - 1][j] += min(t[i][j], t[i][j + 1]);
      }
    }
    return t[0][0];
  }
};
