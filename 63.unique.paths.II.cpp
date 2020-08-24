/**
 * @file 63.unique.paths.II.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sun August 23 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& g) {
    int n = g.size(), m = g[0].size(), dp[n][m];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < m && !g[0][i]; ++i) dp[0][i] = 1;
    for (int i = 0; i < n && !g[i][0]; ++i) dp[i][0] = 1;

    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        if (!g[i][j]) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    
    return dp[n - 1][m - 1];
  }
};

int main() {
  auto S = new Solution();
  vector<vector<int>> v{
      {0, 0, 0},
      {0, 1, 0},
      {0, 0, 0},
  };

  cout << S->uniquePathsWithObstacles(v) << endl;
  return 0;
}