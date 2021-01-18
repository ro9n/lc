/**
 * @file 32.longest.valid.parentheses
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday January 18 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    int n = s.size(), dp[n + 1], best = 0;
    memset(dp, 0x0, sizeof dp);
    stack<int> S;

    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') S.push(i);
      else {
        if (!S.empty()) {
          int top = S.top();
          S.pop();
          dp[i + 1] = i - top + 1 + dp[top];
          best = max(best, dp[i + 1]);
        }
      }
    }

    return best;
  }
};
