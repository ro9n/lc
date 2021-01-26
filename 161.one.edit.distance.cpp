/**
 * @file 161.one.edit.distance
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday January 23 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isOneEditDistance(string s, string t) {
    int n = s.size(), m = t.size(), dp[n + 1][m + 1];

    for (int i = 1; i <= n; ++i) dp[i][0] = i;
    for (int j = 1; j <= m; ++j) dp[0][j] = j;
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        if (s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j];
        else
          dp[i + 1][j + 1] = 1 + min(
                                     dp[i][j], min(dp[i + 1][j], dp[i][j + 1]));
      }

    return dp[n][m] == 1;
  }

  bool isOneEditDistance(string s, string t) {
    int n = s.size(), m = t.size();

    if (n > m) return isOneEditDistance(t, s);

    for (int i = 0; i < n; ++i) {
      if (s[i] != t[i]) {
        if (n == m) return s.substr(i + 1) == t.substr(i + 1);  // skip from both
        else
          return s.substr(i) == t.substr(i + 1);  // skip from larger of two
      }
    }

    return n + 1 == m;  // exhausted s
  }

  bool isOneEditDistance(string s, string t) {
    int n = s.size(), m = t.size();

    int i = 0, j = 0, d = 0;

    while (i < n && j < m) {
      if (s[i] != t[j]) {
        ++d;
        if (n - i != m - j) {
          n < m ? --i : --j;
        }
      }
      ++i, ++j;
    }

    return (d == 1 && i == n && j == m) ||
           (!d && (i + 1 == n || j + 1 == m));
  }
};
