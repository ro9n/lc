/**
 * @file 91.decode.ways
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday January 18 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

// recursive
class Solution {
 public:
  int numDecodings(string s) {
    int n = s.size(), memo[n];
    memset(memo, -0x1, sizeof memo);

    function<int(int)> dcd = [&](int l) {
      if (l >= n) return 1;
      else if (l == n - 1)
        return int(s[l] != '0');
      else if (~memo[l])
        return memo[l];
      else {
        int ans = 0;
        if (s[l] == '0') return memo[l] = 0;
        ans += dcd(l + 1);
        if (stoi(s.substr(l, 2)) <= 26) ans += dcd(l + 2);
        return memo[l] = ans;
      }
    };
    return dcd(0);
  }
};

// iterative
class Solution {
 public:
  int numDecodings(string s) {
    int n = s.size(), dp[n + 2];
    dp[0] = dp[1] = 1;

    for (int i = 0; i < n; ++i) {
      int &ans = dp[i + 2] = 0;
      if (s[i] != '0') {
        ans = dp[i + 1];
      }
      if (i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')))
          ans += dp[i];
    }

    return dp[n + 1];
  }
};