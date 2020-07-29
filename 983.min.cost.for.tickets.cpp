/**
 * @file 983.min.cost.for.tickets.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sat July 18 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

class Solution {
 public:
  int mincostTickets(vector<int>& d, vector<int>& c) {
    unordered_set<int> s(d.begin(), d.end());

    int n = d[d.size() - 1];
    int dp[n + 1];

    dp[0] = 0;
    for(int i = 1; i < n + 1; ++i) {
        dp[i] = INF;
    }
    
    for(int i = 1; i <= n; ++i) {
      if(!s.count(i)) dp[i] = dp[i - 1];
      else dp[i] = min({
        dp[i],
        dp[max(i - 01, 0)] + c[0],
        dp[max(i - 07, 0)] + c[1],
        dp[max(i - 30, 0)] + c[2]
      });
    }

    return dp[n];
  }
};
