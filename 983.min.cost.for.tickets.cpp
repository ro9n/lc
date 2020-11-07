/**
 * @file 983.min.cost.for.tickets
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday October 20 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& c) {
    unordered_set<int> d(days.begin(), days.end());
    int dp[30] = {};

    for (int i = days[0]; i <= days[days.size() - 1]; ++i) {
      if (!d.count(i)) dp[i % 30] = dp[(i - 1) % 30];
      else
        dp[i % 30] = min(dp[max(0, i - 1) % 30] + c[0], min(dp[max(0, i - 7) % 30] + c[1], dp[max(0, i - 30) % 30] + c[2]));
    }

    return dp[days[days.size() - 1] % 30];
  }
};
