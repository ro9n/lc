/**
 * @file 1143.lcs.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Mon August 31 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int longestCommonSubsequence(string p, string t) {
      if(p.size() > t.size()) swap(p, t);
      int n = p.size(), m = t.size(), dp[n][m];

      for(int i = 0; i < n; ++i) {
          for(int j = 0; j < m; ++j) {
              if (p[i] == t[j]) dp[i][j] = i > 0 && j > 0 ? dp[i - 1][j - 1] + 1 : 1;
              else dp[i][j] = max(i > 0 ? dp[i - 1][j] : 0, j > 0 ? dp[i][j - 1] : 0);
          }
      }

      return dp[n - 1][m - 1];
  }
};

int main() {
    auto s = new Solution();
    cout << s->longestCommonSubsequence("abcde", "ace") << endl;

    return 0;
}