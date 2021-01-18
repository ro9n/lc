/**
 * @file 349.intersection.of.two.arrays
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
  vector<int> intersection(vector<int>& a, vector<int>& b) {
    if (a.empty() || b.empty()) return {};

    // 1 sort
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int j = 1, n = a.size(), m = b.size();
    // 2.1 remove dup a + resize
    for (int i = 1; i < n; ++i) {
      if (a[i - 1] != a[i]) {
        if (i == j) ++j;
        else
          a[j++] = a[i];
      }
    }
    a.resize(n = j), j = 1;

    // 2.2 remove dup b + resize
    for (int i = 1; i < m; ++i) {
      if (b[i - 1] != b[i]) {
        if (i == j) ++j;
        else
          b[j++] = b[i];
      }
    }
    b.resize(m = j);

    // 3 2 pointer match
    vector<int> ans;
    for (int i = 0, j = 0; i < n && j < m;) {
      if (a[i] == b[j]) ans.push_back(a[i]), ++i, ++j;
      else if (a[i] < b[j])
        ++i;
      else
        ++j;
    }

    return ans;
  }
};
