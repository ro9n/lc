/**
 * @file 115.distinct.sseq.cpp
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
  int numDistinct(string s, string t) {
    int n = t.size(), m = s.size(), dp[n + 1][m + 1];

    for (int j = 0; j <= m; ++j) dp[0][j] = 1;  // t: empty substring
    for (int i = 0; i <= n; ++i) dp[i][0] = 0;
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        dp[i][j] = dp[i][j - 1];  // without considering s[j]
        if (t[i - 1] == s[j - 1])
          dp[i][j] += dp[i - 1][j - 1]; // extend with prv matches
      }
    }

    return dp[n][m];
  }
};
