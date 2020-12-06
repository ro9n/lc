/**
 * @file 57.insert.interval
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday December 01 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define eb push_back

typedef vector<int> vi;

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& k) {
    if (v.empty()) return {k};

    int n = v.size(), i = 0, mx = k[1], mn = k[0];
    vector<vi> ans;

    while (i < n && v[i][1] < k[0]) ans.pb(v[i]), ++i;
    while (i < n && v[i][0] <= k[1])
      mn = min(mn, v[i][0]), mx = max(mx, v[i][1]), ++i;

    ans.pb({mn, mx});
    while (i < n) ans.pb(v[i]), ++i;

    return ans;
  }
};

