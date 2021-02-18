/**
 * @file 1395.count.number.of.teams
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday January 29 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ASC 0
#define DSC 1

class Solution {
 public:
  int numTeams(vector<int>& rating) {
    int n = rating.size(), ans = 0,
        dp[2][n];

    memset(dp, 0x0, sizeof(int) * 2 * n);

    for (int i = n - 2; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        if (rating[i] > rating[j]) ++dp[DSC][i];
        else if (rating[i] < rating[j]) ++dp[ASC][i];
      }
      for (int j = i + 1; j < n; ++j) {
        if (rating[i] < rating[j]) ans += dp[ASC][j];
        else if (rating[i] > rating[j]) ans += dp[DSC][j];
      }
    }

    return ans;
  }
};