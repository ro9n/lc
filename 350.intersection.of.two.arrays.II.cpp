/**
 * @file 350.intersection.of.two.arrays.II
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday December 01 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define all(k) k.begin(), k.end()
#define eb     emplace_back

class Solution {
 public:
  vector<int> intersect(vector<int>& u, vector<int>& v) {
    vector<int> ans;
    sort(all(u)), sort(all(v));

    int n = u.size(), m = v.size();

    for (int i = 0, j = 0; i < n && j < m;) {
      if (u[i] == v[j]) ans.eb(u[i]), ++i, ++j;
      else if (u[i] < v[j])
        ++i;
      else
        ++j;
    }
    return ans;
  }
};