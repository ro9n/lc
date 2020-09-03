/**
 * @file 1092.shortest.common.superstr.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tue September 01 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string shortestCommonSupersequence(string p, string t) {
    if (p.size() > t.size()) swap(p, t);
    int n = p.size(), m = t.size(), dp[n][m];

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (p[i] == t[j]) dp[i][j] = i > 0 && j > 0 ? dp[i - 1][j - 1] + 1 : 1;
        else
          dp[i][j] = max(i > 0 ? dp[i - 1][j] : 0, j > 0 ? dp[i][j - 1] : 0);
      }
    }

    for(int i = 0; i < n; ++i) {for(int j = 0; j < m; ++j) cerr << setw(2) << dp[i][j]; cerr << endl;}

    int i = n - 1, j = m - 1;
    string s;

    while (i >= 0 && j >= 0) {
      if (p[i] == t[j]) s.push_back(p[i]), --i, --j;
      else if (i > 0 && j > 0 && dp[i][j - 1] >= dp[i - 1][j])
        s.push_back(t[j--]);
      else
        s.push_back(p[i--]);
    }

    while (i >= 0) s.push_back(p[i--]);
    while (j >= 0) s.push_back(t[j--]);

    return string(s.rbegin(), s.rend());
  }
};

int main() {
  auto s = new Solution();
  cout << s->shortestCommonSupersequence("bcacaaab", "bbabaccc") << endl;
  return 0;
}