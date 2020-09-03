/**
 * @file 73.edit.distance.cpp
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
  int minDistance(string s, string t) {
    int n = s.size(), m = t.size(), dp[n + 1][m + 1];

    for (int i = 1; i <= n; ++i) dp[i][0] = i;
    for (int j = 1; j <= m; ++j) dp[0][j] = j;
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        // + min(prv + noop = 0 OR prv + replace = 1, min(add = 1, remove = 1))
        dp[i][j] = min(dp[i - 1][j - 1] + (1 & s[i - 1] != t[j - 1]),
                       min(1 + dp[i][j - 1], 1 + dp[i - 1][j]));
      }
    }

    // for (int i = 0; i <= n; ++i) {
    //   for (int j = 0; j <= m; ++j) cerr << setw(2) << dp[i][j];
    //   cerr << endl;
    // }

    return dp[n][m];
  }
};

int main() {
  auto s = new Solution();
  // cout << s->minDistance("intention", "execution") << endl;
  // cout << s->minDistance("horse", "ros") << endl;
  cout << s->minDistance("", "a") << endl;

  return 0;
}